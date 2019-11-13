/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/stream-client-buffered-stream/gen-cpp2/PubSubStreamingService.h"

#include <thrift/lib/cpp2/gen/service_tcc.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>, apache::thrift::FieldData<2, apache::thrift::protocol::T_I32, int32_t*>> PubSubStreamingService_returnstream_pargs;
typedef apache::thrift::ThriftPResultStream<
    apache::thrift::ThriftPresult<true>, 
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_I32, int32_t*>>
    > PubSubStreamingService_returnstream_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>> PubSubStreamingService_streamthrows_pargs;
typedef apache::thrift::ThriftPResultStream<
    apache::thrift::ThriftPresult<true>, 
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_I32, int32_t*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>>
    > PubSubStreamingService_streamthrows_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>> PubSubStreamingService_boththrows_pargs;
typedef apache::thrift::ThriftPResultStream<
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>>, 
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_I32, int32_t*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>>
    > PubSubStreamingService_boththrows_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>> PubSubStreamingService_responseandstreamthrows_pargs;
typedef apache::thrift::ThriftPResultStream<
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_I32, int32_t*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>>, 
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_I32, int32_t*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>>
    > PubSubStreamingService_responseandstreamthrows_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_returnstream(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_STREAMING_RESPONSE, &PubSubStreamingServiceAsyncProcessor::process_returnstream<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_returnstream(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_returnstream_pargs args;
  int32_t uarg_i32_from{0};
  args.get<0>().value = &uarg_i32_from;
  int32_t uarg_i32_to{0};
  args.get<1>().value = &uarg_i32_to;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "PubSubStreamingService.returnstream", ctx));
  try {
    folly::io::Cursor cursor(buf.get());
    cursor.skip(ctx->getMessageBeginSize());
    ProtocolIn_ iprot;
    iprot.setInput(cursor);
    deserializeRequest(args, buf.get(), &iprot, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "returnstream");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<apache::thrift::Stream<int32_t>>>(std::move(req), std::move(ctxStack), return_returnstream<ProtocolIn_,ProtocolOut_>, throw_wrapped_returnstream<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_returnstream(std::move(callback), args.get<0>().ref(), args.get<1>().ref());
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::ResponseAndStream<folly::IOBufQueue, folly::IOBufQueue> PubSubStreamingServiceAsyncProcessor::return_returnstream(int32_t protoSeqId, apache::thrift::ContextStack* ctx, apache::thrift::Stream<int32_t> _return) {
  ProtocolOut_ prot;
  PubSubStreamingService_returnstream_presult::FieldsType result;
  using StreamPResultType = PubSubStreamingService_returnstream_presult::StreamPResultType;
  auto& _returnStream = _return;

  auto exMap = [](StreamPResultType&, folly::exception_wrapper) {
    return false;
  };

  auto _encodedStream = apache::thrift::detail::ap::encode_stream<ProtocolOut_, StreamPResultType>(std::move(_returnStream), std::move(exMap));
  return {serializeResponse("returnstream", &prot, protoSeqId, ctx, result), std::move(_encodedStream)};
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_returnstream(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "returnstream");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_streamthrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_STREAMING_RESPONSE, &PubSubStreamingServiceAsyncProcessor::process_streamthrows<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_streamthrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_streamthrows_pargs args;
  int32_t uarg_foo{0};
  args.get<0>().value = &uarg_foo;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "PubSubStreamingService.streamthrows", ctx));
  try {
    folly::io::Cursor cursor(buf.get());
    cursor.skip(ctx->getMessageBeginSize());
    ProtocolIn_ iprot;
    iprot.setInput(cursor);
    deserializeRequest(args, buf.get(), &iprot, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "streamthrows");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<apache::thrift::Stream<int32_t>>>(std::move(req), std::move(ctxStack), return_streamthrows<ProtocolIn_,ProtocolOut_>, throw_wrapped_streamthrows<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_streamthrows(std::move(callback), args.get<0>().ref());
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::ResponseAndStream<folly::IOBufQueue, folly::IOBufQueue> PubSubStreamingServiceAsyncProcessor::return_streamthrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx, apache::thrift::Stream<int32_t> _return) {
  ProtocolOut_ prot;
  PubSubStreamingService_streamthrows_presult::FieldsType result;
  using StreamPResultType = PubSubStreamingService_streamthrows_presult::StreamPResultType;
  auto& _returnStream = _return;

  auto exMap = [](StreamPResultType& res, folly::exception_wrapper ew) {
    if (ew.with_exception([&]( ::cpp2::FooEx& e) {
          res.get<1>().ref() = e;
          res.setIsSet(1, true);
        })) {
      return true;
    }
    return false;
  };

  auto _encodedStream = apache::thrift::detail::ap::encode_stream<ProtocolOut_, StreamPResultType>(std::move(_returnStream), std::move(exMap));
  return {serializeResponse("streamthrows", &prot, protoSeqId, ctx, result), std::move(_encodedStream)};
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_streamthrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "streamthrows");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_boththrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_STREAMING_RESPONSE, &PubSubStreamingServiceAsyncProcessor::process_boththrows<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_boththrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_boththrows_pargs args;
  int32_t uarg_foo{0};
  args.get<0>().value = &uarg_foo;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "PubSubStreamingService.boththrows", ctx));
  try {
    folly::io::Cursor cursor(buf.get());
    cursor.skip(ctx->getMessageBeginSize());
    ProtocolIn_ iprot;
    iprot.setInput(cursor);
    deserializeRequest(args, buf.get(), &iprot, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "boththrows");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<apache::thrift::Stream<int32_t>>>(std::move(req), std::move(ctxStack), return_boththrows<ProtocolIn_,ProtocolOut_>, throw_wrapped_boththrows<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_boththrows(std::move(callback), args.get<0>().ref());
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::ResponseAndStream<folly::IOBufQueue, folly::IOBufQueue> PubSubStreamingServiceAsyncProcessor::return_boththrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx, apache::thrift::Stream<int32_t> _return) {
  ProtocolOut_ prot;
  PubSubStreamingService_boththrows_presult::FieldsType result;
  using StreamPResultType = PubSubStreamingService_boththrows_presult::StreamPResultType;
  auto& _returnStream = _return;

  auto exMap = [](StreamPResultType& res, folly::exception_wrapper ew) {
    if (ew.with_exception([&]( ::cpp2::FooEx& e) {
          res.get<1>().ref() = e;
          res.setIsSet(1, true);
        })) {
      return true;
    }
    return false;
  };

  auto _encodedStream = apache::thrift::detail::ap::encode_stream<ProtocolOut_, StreamPResultType>(std::move(_returnStream), std::move(exMap));
  return {serializeResponse("boththrows", &prot, protoSeqId, ctx, result), std::move(_encodedStream)};
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_boththrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  PubSubStreamingService_boththrows_presult result;
  if (ew.with_exception([&]( ::cpp2::FooEx& e) {
    ctx->userExceptionWrapped(true, ew);
    result.fields.get<0>().ref() = e;
    result.fields.setIsSet(0, true);
  }
  )) {} else
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "boththrows");
    return;
  }
  ProtocolOut_ prot;
  auto queue = serializeResponse("boththrows", &prot, protoSeqId, ctx, result.fields);
  queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
  return req->sendStreamReply({queue.move(), {}});
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_responseandstreamthrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_STREAMING_RESPONSE, &PubSubStreamingServiceAsyncProcessor::process_responseandstreamthrows<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_responseandstreamthrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_responseandstreamthrows_pargs args;
  int32_t uarg_foo{0};
  args.get<0>().value = &uarg_foo;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "PubSubStreamingService.responseandstreamthrows", ctx));
  try {
    folly::io::Cursor cursor(buf.get());
    cursor.skip(ctx->getMessageBeginSize());
    ProtocolIn_ iprot;
    iprot.setInput(cursor);
    deserializeRequest(args, buf.get(), &iprot, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "responseandstreamthrows");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<apache::thrift::ResponseAndStream<int32_t,int32_t>>>(std::move(req), std::move(ctxStack), return_responseandstreamthrows<ProtocolIn_,ProtocolOut_>, throw_wrapped_responseandstreamthrows<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_responseandstreamthrows(std::move(callback), args.get<0>().ref());
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::ResponseAndStream<folly::IOBufQueue, folly::IOBufQueue> PubSubStreamingServiceAsyncProcessor::return_responseandstreamthrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx, apache::thrift::ResponseAndStream<int32_t,int32_t> _return) {
  ProtocolOut_ prot;
  PubSubStreamingService_responseandstreamthrows_presult::FieldsType result;
  using StreamPResultType = PubSubStreamingService_responseandstreamthrows_presult::StreamPResultType;
  result.get<0>().value = const_cast<apache::thrift::ResponseAndStream<int32_t,int32_t>::ResponseType*>(&_return.response);
  result.setIsSet(0, true);
  auto& _returnStream = _return.stream;

  auto exMap = [](StreamPResultType& res, folly::exception_wrapper ew) {
    if (ew.with_exception([&]( ::cpp2::FooEx& e) {
          res.get<1>().ref() = e;
          res.setIsSet(1, true);
        })) {
      return true;
    }
    return false;
  };

  auto _encodedStream = apache::thrift::detail::ap::encode_stream<ProtocolOut_, StreamPResultType>(std::move(_returnStream), std::move(exMap));
  return {serializeResponse("responseandstreamthrows", &prot, protoSeqId, ctx, result), std::move(_encodedStream)};
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_responseandstreamthrows(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  PubSubStreamingService_responseandstreamthrows_presult result;
  if (ew.with_exception([&]( ::cpp2::FooEx& e) {
    ctx->userExceptionWrapped(true, ew);
    result.fields.get<1>().ref() = e;
    result.fields.setIsSet(1, true);
  }
  )) {} else
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "responseandstreamthrows");
    return;
  }
  ProtocolOut_ prot;
  auto queue = serializeResponse("responseandstreamthrows", &prot, protoSeqId, ctx, result.fields);
  queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
  return req->sendStreamReply({queue.move(), {}});
}

} // cpp2
