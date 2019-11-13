/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "thrift/compiler/test/fixtures/types/gen-cpp2/SomeServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace apache { namespace thrift { namespace fixtures { namespace types {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_MAP,  ::apache::thrift::fixtures::types::SomeMap*>> SomeService_bounce_map_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_MAP,  ::apache::thrift::fixtures::types::SomeMap*>> SomeService_bounce_map_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_LIST, ::std::vector<int64_t>*>> SomeService_binary_keyed_map_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_MAP, ::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>*>> SomeService_binary_keyed_map_presult;

template <typename Protocol_>
void SomeServiceAsyncClient::bounce_mapT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  SomeService_bounce_map_pargs args;
  args.get<0>().value = const_cast< ::apache::thrift::fixtures::types::SomeMap*>(&m);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), ctx->ctx, std::move(header), channel_.get(), "bounce_map", writer, sizer, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE);
  ctx->reqContext.setRequestHeader(nullptr);
}

template <typename Protocol_>
void SomeServiceAsyncClient::binary_keyed_mapT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::vector<int64_t>& r) {
  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  SomeService_binary_keyed_map_pargs args;
  args.get<0>().value = const_cast<::std::vector<int64_t>*>(&r);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), ctx->ctx, std::move(header), channel_.get(), "binary_keyed_map", writer, sizer, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE);
  ctx->reqContext.setRequestHeader(nullptr);
}



void SomeServiceAsyncClient::bounce_map(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  bounce_map(rpcOptions, std::move(callback), m);
}

void SomeServiceAsyncClient::bounce_map(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(),
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "SomeService.bounce_map");
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  bounce_mapImpl(rpcOptions, std::move(ctx), apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext)), m);
}

void SomeServiceAsyncClient::bounce_mapImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      bounce_mapT(&writer, rpcOptions, std::move(ctx), std::move(callback), m);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      bounce_mapT(&writer, rpcOptions, std::move(ctx), std::move(callback), m);
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void SomeServiceAsyncClient::sync_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_bounce_map(rpcOptions, _return, m);
}

void SomeServiceAsyncClient::sync_bounce_map(apache::thrift::RpcOptions& rpcOptions,  ::apache::thrift::fixtures::types::SomeMap& _return, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  apache::thrift::ClientReceiveState _returnState;
  apache::thrift::ClientSyncCallback<false> callback(&_returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      protocolId,
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "SomeService.bounce_map");
  bounce_mapImpl(rpcOptions, ctx, apache::thrift::RequestClientCallback::Ptr(&callback), m);
  callback.waitUntilDone(evb);
  _returnState.resetProtocolId(protocolId);
  _returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_bounce_map(_return, _returnState);
}



folly::Future< ::apache::thrift::fixtures::types::SomeMap> SomeServiceAsyncClient::future_bounce_map(const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_bounce_map(rpcOptions, m);
}

folly::SemiFuture< ::apache::thrift::fixtures::types::SomeMap> SomeServiceAsyncClient::semifuture_bounce_map(const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_bounce_map(rpcOptions, m);
}

folly::Future< ::apache::thrift::fixtures::types::SomeMap> SomeServiceAsyncClient::future_bounce_map(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  folly::Promise< ::apache::thrift::fixtures::types::SomeMap> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback< ::apache::thrift::fixtures::types::SomeMap>>(std::move(_promise), recv_wrapped_bounce_map, channel_);
  bounce_map(rpcOptions, std::move(callback), m);
  return _future;
}

folly::SemiFuture< ::apache::thrift::fixtures::types::SomeMap> SomeServiceAsyncClient::semifuture_bounce_map(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_bounce_map, channel_);
  auto callback = std::move(callbackAndFuture.first);
  bounce_map(rpcOptions, std::move(callback), m);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair< ::apache::thrift::fixtures::types::SomeMap, std::unique_ptr<apache::thrift::transport::THeader>>> SomeServiceAsyncClient::header_future_bounce_map(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  folly::Promise<std::pair< ::apache::thrift::fixtures::types::SomeMap, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback< ::apache::thrift::fixtures::types::SomeMap>>(std::move(_promise), recv_wrapped_bounce_map, channel_);
  bounce_map(rpcOptions, std::move(callback), m);
  return _future;
}

folly::SemiFuture<std::pair< ::apache::thrift::fixtures::types::SomeMap, std::unique_ptr<apache::thrift::transport::THeader>>> SomeServiceAsyncClient::header_semifuture_bounce_map(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_bounce_map, channel_);
  auto callback = std::move(callbackAndFuture.first);
  bounce_map(rpcOptions, std::move(callback), m);
  return std::move(callbackAndFuture.second);
}
void SomeServiceAsyncClient::bounce_map(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  bounce_map(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), m);
}

folly::exception_wrapper SomeServiceAsyncClient::recv_wrapped_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = SomeService_bounce_map_presult;
  constexpr auto const fname = "bounce_map";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void SomeServiceAsyncClient::recv_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_bounce_map(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void SomeServiceAsyncClient::recv_instance_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_bounce_map(_return, state);
}

folly::exception_wrapper SomeServiceAsyncClient::recv_instance_wrapped_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_bounce_map(_return, state);
}

void SomeServiceAsyncClient::binary_keyed_map(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::vector<int64_t>& r) {
  ::apache::thrift::RpcOptions rpcOptions;
  binary_keyed_map(rpcOptions, std::move(callback), r);
}

void SomeServiceAsyncClient::binary_keyed_map(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::vector<int64_t>& r) {
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(),
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "SomeService.binary_keyed_map");
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  binary_keyed_mapImpl(rpcOptions, std::move(ctx), apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext)), r);
}

void SomeServiceAsyncClient::binary_keyed_mapImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::vector<int64_t>& r) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      binary_keyed_mapT(&writer, rpcOptions, std::move(ctx), std::move(callback), r);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      binary_keyed_mapT(&writer, rpcOptions, std::move(ctx), std::move(callback), r);
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void SomeServiceAsyncClient::sync_binary_keyed_map(::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>& _return, const ::std::vector<int64_t>& r) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_binary_keyed_map(rpcOptions, _return, r);
}

void SomeServiceAsyncClient::sync_binary_keyed_map(apache::thrift::RpcOptions& rpcOptions, ::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>& _return, const ::std::vector<int64_t>& r) {
  apache::thrift::ClientReceiveState _returnState;
  apache::thrift::ClientSyncCallback<false> callback(&_returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      protocolId,
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "SomeService.binary_keyed_map");
  binary_keyed_mapImpl(rpcOptions, ctx, apache::thrift::RequestClientCallback::Ptr(&callback), r);
  callback.waitUntilDone(evb);
  _returnState.resetProtocolId(protocolId);
  _returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_binary_keyed_map(_return, _returnState);
}



folly::Future<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>> SomeServiceAsyncClient::future_binary_keyed_map(const ::std::vector<int64_t>& r) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_binary_keyed_map(rpcOptions, r);
}

folly::SemiFuture<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>> SomeServiceAsyncClient::semifuture_binary_keyed_map(const ::std::vector<int64_t>& r) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_binary_keyed_map(rpcOptions, r);
}

folly::Future<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>> SomeServiceAsyncClient::future_binary_keyed_map(apache::thrift::RpcOptions& rpcOptions, const ::std::vector<int64_t>& r) {
  folly::Promise<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>>>(std::move(_promise), recv_wrapped_binary_keyed_map, channel_);
  binary_keyed_map(rpcOptions, std::move(callback), r);
  return _future;
}

folly::SemiFuture<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>> SomeServiceAsyncClient::semifuture_binary_keyed_map(apache::thrift::RpcOptions& rpcOptions, const ::std::vector<int64_t>& r) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_binary_keyed_map, channel_);
  auto callback = std::move(callbackAndFuture.first);
  binary_keyed_map(rpcOptions, std::move(callback), r);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>, std::unique_ptr<apache::thrift::transport::THeader>>> SomeServiceAsyncClient::header_future_binary_keyed_map(apache::thrift::RpcOptions& rpcOptions, const ::std::vector<int64_t>& r) {
  folly::Promise<std::pair<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>>>(std::move(_promise), recv_wrapped_binary_keyed_map, channel_);
  binary_keyed_map(rpcOptions, std::move(callback), r);
  return _future;
}

folly::SemiFuture<std::pair<::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>, std::unique_ptr<apache::thrift::transport::THeader>>> SomeServiceAsyncClient::header_semifuture_binary_keyed_map(apache::thrift::RpcOptions& rpcOptions, const ::std::vector<int64_t>& r) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_binary_keyed_map, channel_);
  auto callback = std::move(callbackAndFuture.first);
  binary_keyed_map(rpcOptions, std::move(callback), r);
  return std::move(callbackAndFuture.second);
}
void SomeServiceAsyncClient::binary_keyed_map(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::vector<int64_t>& r) {
  binary_keyed_map(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), r);
}

folly::exception_wrapper SomeServiceAsyncClient::recv_wrapped_binary_keyed_map(::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = SomeService_binary_keyed_map_presult;
  constexpr auto const fname = "binary_keyed_map";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void SomeServiceAsyncClient::recv_binary_keyed_map(::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_binary_keyed_map(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void SomeServiceAsyncClient::recv_instance_binary_keyed_map(::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_binary_keyed_map(_return, state);
}

folly::exception_wrapper SomeServiceAsyncClient::recv_instance_wrapped_binary_keyed_map(::std::map< ::apache::thrift::fixtures::types::TBinary, int64_t>& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_binary_keyed_map(_return, state);
}

}}}} // apache::thrift::fixtures::types
