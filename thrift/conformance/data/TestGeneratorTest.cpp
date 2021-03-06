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

#include <thrift/conformance/data/TestGenerator.h>

#include <folly/portability/GTest.h>
#include <thrift/conformance/cpp2/AnyRegistry.h>
#include <thrift/conformance/cpp2/AnyStructSerializer.h>
#include <thrift/conformance/cpp2/Object.h>
#include <thrift/conformance/cpp2/ThriftTypeInfo.h>
#include <thrift/conformance/if/gen-cpp2/object_types_custom_protocol.h>

namespace apache::thrift::conformance::data {

TEST(TestGeneratorTest, RoundTripSuite) {
  AnyRegistry registry;
  registry.registerType<Value>(
      createThriftTypeInfo({"facebook.com/thrift/conformance/Value"}));
  registry.registerSerializer<Value>(
      &getAnyStandardSerializer<Value, StandardProtocol::Binary>());
  registry.registerSerializer<Value>(
      &getAnyStandardSerializer<Value, StandardProtocol::Compact>());
  registry.registerSerializer<Value>(
      &getAnyStandardSerializer<Value, StandardProtocol::Json>());
  registry.registerSerializer<Value>(
      &getAnyStandardSerializer<Value, StandardProtocol::SimpleJson>());
  auto suite = createRoundTripSuite(registry);

  constexpr size_t kNumProtocols = 4;
  constexpr size_t kNumTypes = 8;
  EXPECT_EQ(*suite.name_ref(), "Round Trip");
  ASSERT_EQ(suite.tests_ref()->size(), kNumProtocols * kNumTypes);

  EXPECT_EQ(*suite.tests_ref()->at(0 * kNumTypes).name_ref(), "Binary: bool");
  EXPECT_EQ(*suite.tests_ref()->at(1 * kNumTypes).name_ref(), "Compact: bool");
  EXPECT_EQ(*suite.tests_ref()->at(2 * kNumTypes).name_ref(), "Json: bool");
  EXPECT_EQ(
      *suite.tests_ref()->at(3 * kNumTypes).name_ref(), "SimpleJson: bool");

  const auto& test = suite.tests_ref()->at(1);
  EXPECT_EQ(*test.name_ref(), "Binary: byte");

  ASSERT_GT(test.testCases_ref()->size(), 0);
  const auto& testCase = test.testCases_ref()->at(0);
  EXPECT_EQ(*testCase.name_ref(), "zero");
  EXPECT_EQ(testCase.test_ref()->getType(), TestCaseUnion::roundTrip);
}

} // namespace apache::thrift::conformance::data
