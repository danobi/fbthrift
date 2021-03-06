// Autogenerated by Thrift Compiler (facebook)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
// @generated

package module

import (
	"bytes"
	"context"
	"sync"
	"fmt"
	thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = sync.Mutex{}
var _ = bytes.Equal
var _ = context.Background

type DbMixedStackArguments interface {
  // Parameters:
  //  - Key
  GetDataByKey0(key string) (_r []byte, err error)
  // Parameters:
  //  - Key
  GetDataByKey1(key string) (_r []byte, err error)
}

type DbMixedStackArgumentsClientInterface interface {
  thrift.ClientInterface
  // Parameters:
  //  - Key
  GetDataByKey0(key string) (_r []byte, err error)
  // Parameters:
  //  - Key
  GetDataByKey1(key string) (_r []byte, err error)
}

type DbMixedStackArgumentsClient struct {
  DbMixedStackArgumentsClientInterface
  CC thrift.ClientConn
}

func(client *DbMixedStackArgumentsClient) Open() error {
  return client.CC.Open()
}

func(client *DbMixedStackArgumentsClient) Close() error {
  return client.CC.Close()
}

func(client *DbMixedStackArgumentsClient) IsOpen() bool {
  return client.CC.IsOpen()
}

func NewDbMixedStackArgumentsClientFactory(t thrift.Transport, f thrift.ProtocolFactory) *DbMixedStackArgumentsClient {
  return &DbMixedStackArgumentsClient{ CC: thrift.NewClientConn(t, f) }
}

func NewDbMixedStackArgumentsClient(t thrift.Transport, iprot thrift.Protocol, oprot thrift.Protocol) *DbMixedStackArgumentsClient {
  return &DbMixedStackArgumentsClient{ CC: thrift.NewClientConnWithProtocols(t, iprot, oprot) }
}

func NewDbMixedStackArgumentsClientProtocol(prot thrift.Protocol) *DbMixedStackArgumentsClient {
  return NewDbMixedStackArgumentsClient(prot.Transport(), prot, prot)
}

// Parameters:
//  - Key
func (p *DbMixedStackArgumentsClient) GetDataByKey0(key string) (_r []byte, err error) {
  args := DbMixedStackArgumentsGetDataByKey0Args{
    Key : key,
  }
  err = p.CC.SendMsg("getDataByKey0", &args, thrift.CALL)
  if err != nil { return }
  return p.recvGetDataByKey0()
}


func (p *DbMixedStackArgumentsClient) recvGetDataByKey0() (value []byte, err error) {
  var result DbMixedStackArgumentsGetDataByKey0Result
  err = p.CC.RecvMsg("getDataByKey0", &result)
  if err != nil { return }

  return result.GetSuccess(), nil
}

// Parameters:
//  - Key
func (p *DbMixedStackArgumentsClient) GetDataByKey1(key string) (_r []byte, err error) {
  args := DbMixedStackArgumentsGetDataByKey1Args{
    Key : key,
  }
  err = p.CC.SendMsg("getDataByKey1", &args, thrift.CALL)
  if err != nil { return }
  return p.recvGetDataByKey1()
}


func (p *DbMixedStackArgumentsClient) recvGetDataByKey1() (value []byte, err error) {
  var result DbMixedStackArgumentsGetDataByKey1Result
  err = p.CC.RecvMsg("getDataByKey1", &result)
  if err != nil { return }

  return result.GetSuccess(), nil
}


type DbMixedStackArgumentsThreadsafeClient struct {
  DbMixedStackArgumentsClientInterface
  CC thrift.ClientConn
  Mu sync.Mutex
}

func(client *DbMixedStackArgumentsThreadsafeClient) Open() error {
  client.Mu.Lock()
  defer client.Mu.Unlock()
  return client.CC.Open()
}

func(client *DbMixedStackArgumentsThreadsafeClient) Close() error {
  client.Mu.Lock()
  defer client.Mu.Unlock()
  return client.CC.Close()
}

func(client *DbMixedStackArgumentsThreadsafeClient) IsOpen() bool {
  client.Mu.Lock()
  defer client.Mu.Unlock()
  return client.CC.IsOpen()
}

func NewDbMixedStackArgumentsThreadsafeClientFactory(t thrift.Transport, f thrift.ProtocolFactory) *DbMixedStackArgumentsThreadsafeClient {
  return &DbMixedStackArgumentsThreadsafeClient{ CC: thrift.NewClientConn(t, f) }
}

func NewDbMixedStackArgumentsThreadsafeClient(t thrift.Transport, iprot thrift.Protocol, oprot thrift.Protocol) *DbMixedStackArgumentsThreadsafeClient {
  return &DbMixedStackArgumentsThreadsafeClient{ CC: thrift.NewClientConnWithProtocols(t, iprot, oprot) }
}

func NewDbMixedStackArgumentsThreadsafeClientProtocol(prot thrift.Protocol) *DbMixedStackArgumentsThreadsafeClient {
  return NewDbMixedStackArgumentsThreadsafeClient(prot.Transport(), prot, prot)
}

// Parameters:
//  - Key
func (p *DbMixedStackArgumentsThreadsafeClient) GetDataByKey0(key string) (_r []byte, err error) {
  p.Mu.Lock()
  defer p.Mu.Unlock()
  args := DbMixedStackArgumentsGetDataByKey0Args{
    Key : key,
  }
  err = p.CC.SendMsg("getDataByKey0", &args, thrift.CALL)
  if err != nil { return }
  return p.recvGetDataByKey0()
}


func (p *DbMixedStackArgumentsThreadsafeClient) recvGetDataByKey0() (value []byte, err error) {
  var result DbMixedStackArgumentsGetDataByKey0Result
  err = p.CC.RecvMsg("getDataByKey0", &result)
  if err != nil { return }

  return result.GetSuccess(), nil
}

// Parameters:
//  - Key
func (p *DbMixedStackArgumentsThreadsafeClient) GetDataByKey1(key string) (_r []byte, err error) {
  p.Mu.Lock()
  defer p.Mu.Unlock()
  args := DbMixedStackArgumentsGetDataByKey1Args{
    Key : key,
  }
  err = p.CC.SendMsg("getDataByKey1", &args, thrift.CALL)
  if err != nil { return }
  return p.recvGetDataByKey1()
}


func (p *DbMixedStackArgumentsThreadsafeClient) recvGetDataByKey1() (value []byte, err error) {
  var result DbMixedStackArgumentsGetDataByKey1Result
  err = p.CC.RecvMsg("getDataByKey1", &result)
  if err != nil { return }

  return result.GetSuccess(), nil
}


type DbMixedStackArgumentsProcessor struct {
  processorMap map[string]thrift.ProcessorFunction
  handler DbMixedStackArguments
}

func (p *DbMixedStackArgumentsProcessor) AddToProcessorMap(key string, processor thrift.ProcessorFunction) {
  p.processorMap[key] = processor
}

func (p *DbMixedStackArgumentsProcessor) GetProcessorFunction(key string) (processor thrift.ProcessorFunction, err error) {
  if processor, ok := p.processorMap[key]; ok {
    return processor, nil
  }
  return nil, nil // generic error message will be sent
}

func (p *DbMixedStackArgumentsProcessor) ProcessorMap() map[string]thrift.ProcessorFunction {
  return p.processorMap
}

func NewDbMixedStackArgumentsProcessor(handler DbMixedStackArguments) *DbMixedStackArgumentsProcessor {
  self8 := &DbMixedStackArgumentsProcessor{handler:handler, processorMap:make(map[string]thrift.ProcessorFunction)}
  self8.processorMap["getDataByKey0"] = &dbMixedStackArgumentsProcessorGetDataByKey0{handler:handler}
  self8.processorMap["getDataByKey1"] = &dbMixedStackArgumentsProcessorGetDataByKey1{handler:handler}
  return self8
}

type dbMixedStackArgumentsProcessorGetDataByKey0 struct {
  handler DbMixedStackArguments
}

func (p *dbMixedStackArgumentsProcessorGetDataByKey0) Read(iprot thrift.Protocol) (thrift.Struct, thrift.Exception) {
  args := DbMixedStackArgumentsGetDataByKey0Args{}
  if err := args.Read(iprot); err != nil {
    return nil, err
  }
  iprot.ReadMessageEnd()
  return &args, nil
}

func (p *dbMixedStackArgumentsProcessorGetDataByKey0) Write(seqId int32, result thrift.WritableStruct, oprot thrift.Protocol) (err thrift.Exception) {
  var err2 error
  messageType := thrift.REPLY
  switch result.(type) {
  case thrift.ApplicationException:
    messageType = thrift.EXCEPTION
  }
  if err2 = oprot.WriteMessageBegin("getDataByKey0", messageType, seqId); err2 != nil {
    err = err2
  }
  if err2 = result.Write(oprot); err == nil && err2 != nil {
    err = err2
  }
  if err2 = oprot.WriteMessageEnd(); err == nil && err2 != nil {
    err = err2
  }
  if err2 = oprot.Flush(); err == nil && err2 != nil {
    err = err2
  }
  return err
}

func (p *dbMixedStackArgumentsProcessorGetDataByKey0) Run(argStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationException) {
  args := argStruct.(*DbMixedStackArgumentsGetDataByKey0Args)
  var result DbMixedStackArgumentsGetDataByKey0Result
  if retval, err := p.handler.GetDataByKey0(args.Key); err != nil {
    switch err.(type) {
    default:
      x := thrift.NewApplicationException(thrift.INTERNAL_ERROR, "Internal error processing getDataByKey0: " + err.Error())
      return x, x
    }
  } else {
    result.Success = retval
  }
  return &result, nil
}

type dbMixedStackArgumentsProcessorGetDataByKey1 struct {
  handler DbMixedStackArguments
}

func (p *dbMixedStackArgumentsProcessorGetDataByKey1) Read(iprot thrift.Protocol) (thrift.Struct, thrift.Exception) {
  args := DbMixedStackArgumentsGetDataByKey1Args{}
  if err := args.Read(iprot); err != nil {
    return nil, err
  }
  iprot.ReadMessageEnd()
  return &args, nil
}

func (p *dbMixedStackArgumentsProcessorGetDataByKey1) Write(seqId int32, result thrift.WritableStruct, oprot thrift.Protocol) (err thrift.Exception) {
  var err2 error
  messageType := thrift.REPLY
  switch result.(type) {
  case thrift.ApplicationException:
    messageType = thrift.EXCEPTION
  }
  if err2 = oprot.WriteMessageBegin("getDataByKey1", messageType, seqId); err2 != nil {
    err = err2
  }
  if err2 = result.Write(oprot); err == nil && err2 != nil {
    err = err2
  }
  if err2 = oprot.WriteMessageEnd(); err == nil && err2 != nil {
    err = err2
  }
  if err2 = oprot.Flush(); err == nil && err2 != nil {
    err = err2
  }
  return err
}

func (p *dbMixedStackArgumentsProcessorGetDataByKey1) Run(argStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationException) {
  args := argStruct.(*DbMixedStackArgumentsGetDataByKey1Args)
  var result DbMixedStackArgumentsGetDataByKey1Result
  if retval, err := p.handler.GetDataByKey1(args.Key); err != nil {
    switch err.(type) {
    default:
      x := thrift.NewApplicationException(thrift.INTERNAL_ERROR, "Internal error processing getDataByKey1: " + err.Error())
      return x, x
    }
  } else {
    result.Success = retval
  }
  return &result, nil
}


// HELPER FUNCTIONS AND STRUCTURES

// Attributes:
//  - Key
type DbMixedStackArgumentsGetDataByKey0Args struct {
  thrift.IRequest
  Key string `thrift:"key,1" db:"key" json:"key"`
}

func NewDbMixedStackArgumentsGetDataByKey0Args() *DbMixedStackArgumentsGetDataByKey0Args {
  return &DbMixedStackArgumentsGetDataByKey0Args{}
}


func (p *DbMixedStackArgumentsGetDataByKey0Args) GetKey() string {
  return p.Key
}
func (p *DbMixedStackArgumentsGetDataByKey0Args) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Args)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.Key = v
}
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Args) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("getDataByKey0_args"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Args) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("key", thrift.STRING, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:key: ", p), err) }
  if err := oprot.WriteString(string(p.Key)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.key (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:key: ", p), err) }
  return err
}

func (p *DbMixedStackArgumentsGetDataByKey0Args) String() string {
  if p == nil {
    return "<nil>"
  }

  keyVal := fmt.Sprintf("%v", p.Key)
  return fmt.Sprintf("DbMixedStackArgumentsGetDataByKey0Args({Key:%s})", keyVal)
}

// Attributes:
//  - Success
type DbMixedStackArgumentsGetDataByKey0Result struct {
  thrift.IResponse
  Success []byte `thrift:"success,0" db:"success" json:"success,omitempty"`
}

func NewDbMixedStackArgumentsGetDataByKey0Result() *DbMixedStackArgumentsGetDataByKey0Result {
  return &DbMixedStackArgumentsGetDataByKey0Result{}
}

var DbMixedStackArgumentsGetDataByKey0Result_Success_DEFAULT []byte

func (p *DbMixedStackArgumentsGetDataByKey0Result) GetSuccess() []byte {
  return p.Success
}
func (p *DbMixedStackArgumentsGetDataByKey0Result) IsSetSuccess() bool {
  return p != nil && p.Success != nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Result) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 0:
      if err := p.ReadField0(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Result)  ReadField0(iprot thrift.Protocol) error {
  if v, err := iprot.ReadBinary(); err != nil {
  return thrift.PrependError("error reading field 0: ", err)
} else {
  p.Success = v
}
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Result) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("getDataByKey0_result"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField0(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey0Result) writeField0(oprot thrift.Protocol) (err error) {
  if p.IsSetSuccess() {
    if err := oprot.WriteFieldBegin("success", thrift.STRING, 0); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 0:success: ", p), err) }
    if err := oprot.WriteBinary(p.Success); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.success (0) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 0:success: ", p), err) }
  }
  return err
}

func (p *DbMixedStackArgumentsGetDataByKey0Result) String() string {
  if p == nil {
    return "<nil>"
  }

  successVal := fmt.Sprintf("%v", p.Success)
  return fmt.Sprintf("DbMixedStackArgumentsGetDataByKey0Result({Success:%s})", successVal)
}

// Attributes:
//  - Key
type DbMixedStackArgumentsGetDataByKey1Args struct {
  thrift.IRequest
  Key string `thrift:"key,1" db:"key" json:"key"`
}

func NewDbMixedStackArgumentsGetDataByKey1Args() *DbMixedStackArgumentsGetDataByKey1Args {
  return &DbMixedStackArgumentsGetDataByKey1Args{}
}


func (p *DbMixedStackArgumentsGetDataByKey1Args) GetKey() string {
  return p.Key
}
func (p *DbMixedStackArgumentsGetDataByKey1Args) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Args)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.Key = v
}
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Args) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("getDataByKey1_args"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Args) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("key", thrift.STRING, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:key: ", p), err) }
  if err := oprot.WriteString(string(p.Key)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.key (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:key: ", p), err) }
  return err
}

func (p *DbMixedStackArgumentsGetDataByKey1Args) String() string {
  if p == nil {
    return "<nil>"
  }

  keyVal := fmt.Sprintf("%v", p.Key)
  return fmt.Sprintf("DbMixedStackArgumentsGetDataByKey1Args({Key:%s})", keyVal)
}

// Attributes:
//  - Success
type DbMixedStackArgumentsGetDataByKey1Result struct {
  thrift.IResponse
  Success []byte `thrift:"success,0" db:"success" json:"success,omitempty"`
}

func NewDbMixedStackArgumentsGetDataByKey1Result() *DbMixedStackArgumentsGetDataByKey1Result {
  return &DbMixedStackArgumentsGetDataByKey1Result{}
}

var DbMixedStackArgumentsGetDataByKey1Result_Success_DEFAULT []byte

func (p *DbMixedStackArgumentsGetDataByKey1Result) GetSuccess() []byte {
  return p.Success
}
func (p *DbMixedStackArgumentsGetDataByKey1Result) IsSetSuccess() bool {
  return p != nil && p.Success != nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Result) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 0:
      if err := p.ReadField0(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Result)  ReadField0(iprot thrift.Protocol) error {
  if v, err := iprot.ReadBinary(); err != nil {
  return thrift.PrependError("error reading field 0: ", err)
} else {
  p.Success = v
}
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Result) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("getDataByKey1_result"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField0(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *DbMixedStackArgumentsGetDataByKey1Result) writeField0(oprot thrift.Protocol) (err error) {
  if p.IsSetSuccess() {
    if err := oprot.WriteFieldBegin("success", thrift.STRING, 0); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 0:success: ", p), err) }
    if err := oprot.WriteBinary(p.Success); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.success (0) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 0:success: ", p), err) }
  }
  return err
}

func (p *DbMixedStackArgumentsGetDataByKey1Result) String() string {
  if p == nil {
    return "<nil>"
  }

  successVal := fmt.Sprintf("%v", p.Success)
  return fmt.Sprintf("DbMixedStackArgumentsGetDataByKey1Result({Success:%s})", successVal)
}


