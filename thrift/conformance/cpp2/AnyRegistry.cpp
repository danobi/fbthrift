/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/conformance/cpp2/AnyRegistry.h>

#include <glog/logging.h>

#include <folly/CppAttributes.h>
#include <folly/Singleton.h>
#include <folly/io/Cursor.h>
#include <thrift/conformance/cpp2/Any.h>
#include <thrift/conformance/cpp2/ThriftTypeInfo.h>
#include <thrift/conformance/cpp2/UniversalType.h>

namespace apache::thrift::conformance {
namespace detail {

AnyRegistry& getGeneratedAnyRegistry() {
  struct GeneratedTag {};
  return folly::detail::createGlobal<AnyRegistry, GeneratedTag>();
}

} // namespace detail

namespace {

folly::fbstring maybeGetTypeHash(
    const ThriftTypeInfo& type,
    type_hash_size_t defaultTypeHashBytes = kMinTypeHashBytes) {
  if (type.typeHashBytes_ref().has_value()) {
    // Use the custom size.
    defaultTypeHashBytes = type.typeHashBytes_ref().value_unchecked();
  }
  return conformance::maybeGetTypeHashPrefix(
      TypeHashAlgorithm::Sha2_256, type.get_name(), defaultTypeHashBytes);
}

const AnySerializer* checkFound(const AnySerializer* serializer) {
  if (serializer == nullptr) {
    folly::throw_exception<std::out_of_range>("serializer not found");
  }
  return serializer;
}

} // namespace

AnyRegistry::TypeEntry::TypeEntry(
    const std::type_info& typeInfo,
    ThriftTypeInfo type)
    : typeInfo(typeInfo),
      typeHash(maybeGetTypeHash(type)),
      type(std::move(type)) {}

bool AnyRegistry::registerType(
    const std::type_info& typeInfo,
    ThriftTypeInfo type) {
  return registerTypeImpl(typeInfo, std::move(type)) != nullptr;
}

bool AnyRegistry::registerSerializer(
    const std::type_info& type,
    const AnySerializer* serializer) {
  return registerSerializerImpl(
      serializer, &registry_.at(std::type_index(type)));
}

bool AnyRegistry::registerSerializer(
    const std::type_info& type,
    std::unique_ptr<AnySerializer> serializer) {
  return registerSerializerImpl(
      std::move(serializer), &registry_.at(std::type_index(type)));
}

std::string_view AnyRegistry::getTypeName(const std::type_info& type) const
    noexcept {
  const auto* entry = getTypeEntry(type);
  if (entry == nullptr) {
    return {};
  }
  return entry->type.get_name();
}

const AnySerializer* AnyRegistry::getSerializer(
    const std::type_info& type,
    const Protocol& protocol) const noexcept {
  return getSerializer(getTypeEntry(type), protocol);
}

const AnySerializer* AnyRegistry::getSerializerByName(
    const std::string_view name,
    const Protocol& protocol) const noexcept {
  return getSerializer(getTypeEntryByName(name), protocol);
}

const AnySerializer* AnyRegistry::getSerializerByHash(
    TypeHashAlgorithm alg,
    const folly::fbstring& typeHash,
    const Protocol& protocol) const {
  if (alg != TypeHashAlgorithm::Sha2_256) {
    folly::throw_exception<std::runtime_error>(
        "Unsupported hash algorithm: " + std::to_string(static_cast<int>(alg)));
  }
  return getSerializer(getTypeEntryByHash(typeHash), protocol);
}

Any AnyRegistry::store(any_ref value, const Protocol& protocol) const {
  if (value.type() == typeid(Any)) {
    // Use the Any specific overload.
    return store(any_cast<const Any&>(value), protocol);
  }

  const auto* entry = getTypeEntry(value.type());
  const auto* serializer = checkFound(getSerializer(entry, protocol));

  folly::IOBufQueue queue(folly::IOBufQueue::cacheChainLength());
  // Allocate 16KB at a time; leave some room for the IOBuf overhead
  constexpr size_t kDesiredGrowth = (1 << 14) - 64;
  serializer->encode(value, folly::io::QueueAppender(&queue, kDesiredGrowth));

  Any result;
  if (entry->typeHash.empty()) {
    result.set_type(entry->type.get_name());
  } else {
    result.set_typeHashPrefixSha2_256(entry->typeHash);
  }
  if (protocol.isCustom()) {
    result.customProtocol_ref() = protocol.custom();
  } else {
    result.protocol_ref() = protocol.standard();
  }
  result.set_data(queue.moveAsValue());
  return result;
}

Any AnyRegistry::store(const Any& value, const Protocol& protocol) const {
  if (hasProtocol(value, protocol)) {
    return value;
  }
  return store(load(value), protocol);
}

void AnyRegistry::load(const Any& value, any_ref out) const {
  const auto* entry = getTypeEntryFor(value);
  const auto* serializer = checkFound(getSerializer(entry, getProtocol(value)));
  folly::io::Cursor cursor(&*value.data_ref());
  serializer->decode(entry->typeInfo, cursor, out);
}

std::any AnyRegistry::load(const Any& value) const {
  std::any out;
  load(value, out);
  return out;
}

auto AnyRegistry::registerTypeImpl(
    const std::type_info& typeInfo,
    ThriftTypeInfo type) -> TypeEntry* {
  validateThriftTypeInfo(type);
  std::vector<folly::fbstring> typeHashs;
  typeHashs.reserve(type.aliases_ref()->size() + 1);
  if (!genTypeHashsAndCheckForConflicts(type, &typeHashs)) {
    return nullptr;
  }

  auto result = registry_.emplace(
      std::type_index(typeInfo), TypeEntry(typeInfo, std::move(type)));
  if (!result.second) {
    return nullptr;
  }

  TypeEntry* entry = &result.first->second;

  // Add to secondary indexes.
  indexName(*entry->type.name_ref(), entry);
  for (const auto& alias : *entry->type.aliases_ref()) {
    indexName(alias, entry);
  }

  for (auto& hash : typeHashs) {
    indexHash(std::move(hash), entry);
  }
  return &result.first->second;
}

bool AnyRegistry::registerSerializerImpl(
    const AnySerializer* serializer,
    TypeEntry* entry) {
  if (serializer == nullptr) {
    return false;
  }
  validateProtocol(serializer->getProtocol());
  return entry->serializers.emplace(serializer->getProtocol(), serializer)
      .second;
}

bool AnyRegistry::registerSerializerImpl(
    std::unique_ptr<AnySerializer> serializer,
    TypeEntry* entry) {
  if (!registerSerializerImpl(serializer.get(), entry)) {
    return false;
  }
  ownedSerializers_.emplace_front(std::move(serializer));
  return true;
}

bool AnyRegistry::genTypeHashsAndCheckForConflicts(
    std::string_view name,
    std::vector<folly::fbstring>* typeHashs) const noexcept {
  if (name.empty() || nameIndex_.contains(name)) {
    return false; // Already exists.
  }

  auto typeHash = getTypeHash(TypeHashAlgorithm::Sha2_256, name);
  // Find shortest valid type hash prefix.
  folly::fbstring minTypeHash(getTypeHashPrefix(typeHash, kMinTypeHashBytes));
  // Check if the minimum type hash would be ambiguous.
  if (containsTypeHash(hashIndex_, minTypeHash)) {
    return false; // Ambigous with another typeHash.
  }
  typeHashs->emplace_back(std::move(typeHash));
  return true;
}

bool AnyRegistry::genTypeHashsAndCheckForConflicts(
    const ThriftTypeInfo& type,
    std::vector<folly::fbstring>* typeHashs) const noexcept {
  // Ensure name and all aliases are availabile.
  if (!genTypeHashsAndCheckForConflicts(*type.name_ref(), typeHashs)) {
    return false;
  }
  for (const auto& alias : *type.aliases_ref()) {
    if (!genTypeHashsAndCheckForConflicts(alias, typeHashs)) {
      return false;
    }
  }
  return true;
}

void AnyRegistry::indexName(std::string_view name, TypeEntry* entry) noexcept {
  auto res = nameIndex_.emplace(name, entry);
  DCHECK(res.second);
}

void AnyRegistry::indexHash(
    folly::fbstring&& typeHash,
    TypeEntry* entry) noexcept {
  auto res = hashIndex_.emplace(std::move(typeHash), entry);
  DCHECK(res.second);
}

auto AnyRegistry::getTypeEntry(const std::type_index& typeIndex) const noexcept
    -> const TypeEntry* {
  auto itr = registry_.find(typeIndex);
  if (itr == registry_.end()) {
    return nullptr;
  }
  return &itr->second;
}

auto AnyRegistry::getTypeEntryByHash(const folly::fbstring& typeHash) const
    noexcept -> const TypeEntry* {
  if (typeHash.size() < kMinTypeHashBytes) {
    return nullptr;
  }
  auto itr = findByTypeHash(hashIndex_, typeHash);
  if (itr == hashIndex_.end()) {
    // No match.
    return nullptr;
  }
  return itr->second;
}

auto AnyRegistry::getTypeEntryByName(std::string_view name) const noexcept
    -> const TypeEntry* {
  auto itr = nameIndex_.find(name);
  if (itr == nameIndex_.end()) {
    return nullptr;
  }
  return itr->second;
}

auto AnyRegistry::getTypeEntryFor(const Any& value) const noexcept
    -> const TypeEntry* {
  if (value.type_ref().has_value() &&
      !value.type_ref().value_unchecked().empty()) {
    return getTypeEntryByName(value.type_ref().value_unchecked());
  }
  if (value.typeHashPrefixSha2_256_ref().has_value()) {
    return getTypeEntryByHash(
        value.typeHashPrefixSha2_256_ref().value_unchecked());
  }
  return nullptr;
}

const AnySerializer* AnyRegistry::getSerializer(
    const TypeEntry* entry,
    const Protocol& protocol) const noexcept {
  if (entry == nullptr) {
    return nullptr;
  }

  auto itr = entry->serializers.find(protocol);
  if (itr == entry->serializers.end()) {
    return nullptr;
  }
  return itr->second;
}

} // namespace apache::thrift::conformance
