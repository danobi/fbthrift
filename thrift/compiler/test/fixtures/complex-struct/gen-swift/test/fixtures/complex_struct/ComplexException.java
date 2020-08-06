/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.complex_struct;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;

@SwiftGenerated
@ThriftStruct("complexException")
public final class ComplexException extends java.lang.Exception {
    private static final long serialVersionUID = 1L;

    private BitSet __isset_bit_vector = new BitSet();

    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();

    private static final TStruct STRUCT_DESC = new TStruct("complexException");
    private final String message;
    public static final int _MESSAGE = 1;
    private static final TField MESSAGE_FIELD_DESC = new TField("message", TType.STRING, (short)1);
    private final List<String> listStrings;
    public static final int _LISTSTRINGS = 2;
    private static final TField LIST_STRINGS_FIELD_DESC = new TField("listStrings", TType.LIST, (short)2);
    private final test.fixtures.complex_struct.MyEnum errorEnum;
    public static final int _ERRORENUM = 3;
    private static final TField ERROR_ENUM_FIELD_DESC = new TField("errorEnum", TType.I32, (short)3);
    private final test.fixtures.complex_struct.MyUnion unionError;
    public static final int _UNIONERROR = 4;
    private static final TField UNION_ERROR_FIELD_DESC = new TField("unionError", TType.STRUCT, (short)4);
    private final test.fixtures.complex_struct.MyStruct structError;
    public static final int _STRUCTERROR = 5;
    private static final TField STRUCT_ERROR_FIELD_DESC = new TField("structError", TType.STRUCT, (short)5);
    private final it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> lsMap;
    public static final int _LSMAP = 6;
    private static final TField LS_MAP_FIELD_DESC = new TField("lsMap", TType.MAP, (short)6);

    @ThriftConstructor
    public ComplexException(
        @ThriftField(value=1, name="message", requiredness=Requiredness.NONE) final String message,
        @ThriftField(value=2, name="listStrings", requiredness=Requiredness.NONE) final List<String> listStrings,
        @ThriftField(value=3, name="errorEnum", requiredness=Requiredness.NONE) final test.fixtures.complex_struct.MyEnum errorEnum,
        @ThriftField(value=4, name="unionError", requiredness=Requiredness.OPTIONAL) final test.fixtures.complex_struct.MyUnion unionError,
        @ThriftField(value=5, name="structError", requiredness=Requiredness.NONE) final test.fixtures.complex_struct.MyStruct structError,
        @ThriftField(value=6, name="lsMap", requiredness=Requiredness.NONE) final it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> lsMap
    ) {
        this.message = message;
        this.listStrings = listStrings;
        this.errorEnum = errorEnum;
        this.unionError = unionError;
        this.structError = structError;
        this.lsMap = lsMap;
    }
    
    @ThriftConstructor
    protected ComplexException() {
      this.message = null;
      this.listStrings = null;
      this.errorEnum = null;
      this.unionError = null;
      this.structError = null;
      this.lsMap = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private String message = null;
        private List<String> listStrings = null;
        private test.fixtures.complex_struct.MyEnum errorEnum = null;
        private test.fixtures.complex_struct.MyUnion unionError = null;
        private test.fixtures.complex_struct.MyStruct structError = null;
        private it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> lsMap = null;
    
        @ThriftField(value=1, name="message", requiredness=Requiredness.NONE)
        public Builder setMessage(String message) {
            this.message = message;
            return this;
        }
    
        public String getMessage() { return message; }
    
            @ThriftField(value=2, name="listStrings", requiredness=Requiredness.NONE)
        public Builder setListStrings(List<String> listStrings) {
            this.listStrings = listStrings;
            return this;
        }
    
        public List<String> getListStrings() { return listStrings; }
    
            @ThriftField(value=3, name="errorEnum", requiredness=Requiredness.NONE)
        public Builder setErrorEnum(test.fixtures.complex_struct.MyEnum errorEnum) {
            this.errorEnum = errorEnum;
            return this;
        }
    
        public test.fixtures.complex_struct.MyEnum getErrorEnum() { return errorEnum; }
    
            @ThriftField(value=4, name="unionError", requiredness=Requiredness.OPTIONAL)
        public Builder setUnionError(test.fixtures.complex_struct.MyUnion unionError) {
            this.unionError = unionError;
            return this;
        }
    
        public test.fixtures.complex_struct.MyUnion getUnionError() { return unionError; }
    
            @ThriftField(value=5, name="structError", requiredness=Requiredness.NONE)
        public Builder setStructError(test.fixtures.complex_struct.MyStruct structError) {
            this.structError = structError;
            return this;
        }
    
        public test.fixtures.complex_struct.MyStruct getStructError() { return structError; }
    
            @ThriftField(value=6, name="lsMap", requiredness=Requiredness.NONE)
        public Builder setLsMap(it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> lsMap) {
            this.lsMap = lsMap;
            return this;
        }
    
        public it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> getLsMap() { return lsMap; }
    
        public Builder() { }
        public Builder(ComplexException other) {
            this.message = other.message;
            this.listStrings = other.listStrings;
            this.errorEnum = other.errorEnum;
            this.unionError = other.unionError;
            this.structError = other.structError;
            this.lsMap = other.lsMap;
        }
    
        @ThriftConstructor
        public ComplexException build() {
            ComplexException result = new ComplexException (
                this.message,
                this.listStrings,
                this.errorEnum,
                this.unionError,
                this.structError,
                this.lsMap
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    
    @ThriftField(value=1, name="message", requiredness=Requiredness.NONE)
    public String getMessage() { return message; }
        
    @ThriftField(value=2, name="listStrings", requiredness=Requiredness.NONE)
    public List<String> getListStrings() { return listStrings; }
        
    @ThriftField(value=3, name="errorEnum", requiredness=Requiredness.NONE)
    public test.fixtures.complex_struct.MyEnum getErrorEnum() { return errorEnum; }
        
    @ThriftField(value=4, name="unionError", requiredness=Requiredness.OPTIONAL)
    public test.fixtures.complex_struct.MyUnion getUnionError() { return unionError; }
        
    @ThriftField(value=5, name="structError", requiredness=Requiredness.NONE)
    public test.fixtures.complex_struct.MyStruct getStructError() { return structError; }
        
    @ThriftField(value=6, name="lsMap", requiredness=Requiredness.NONE)
    public it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> getLsMap() { return lsMap; }
    
    
    public static ComplexException read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(ComplexException.NAMES_TO_IDS, ComplexException.FIELD_METADATA);
      ComplexException.Builder builder = new ComplexException.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _MESSAGE:
          if (__field.type == TType.STRING) {
            String message = oprot.readString();
            builder.setMessage(message);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _LISTSTRINGS:
          if (__field.type == TType.LIST) {
            List<String> listStrings;
            {
            TList _list = oprot.readListBegin();
            if (_list.size < 0) {
                throw new TException("Using an unsupported Map, size is less than zero.");
            }
            listStrings = new ArrayList<String>(_list.size);
            for (int _i = 0; _i < _list.size; _i++) {
                
                String _value1 = oprot.readString();
                listStrings.add(_value1);
            }
            oprot.readListEnd();
            }
            builder.setListStrings(listStrings);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _ERRORENUM:
          if (__field.type == TType.I32) {
            test.fixtures.complex_struct.MyEnum errorEnum = test.fixtures.complex_struct.MyEnum.fromInteger(oprot.readI32());
            builder.setErrorEnum(errorEnum);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _UNIONERROR:
          if (__field.type == TType.STRUCT) {
            test.fixtures.complex_struct.MyUnion unionError = test.fixtures.complex_struct.MyUnion.read0(oprot);
            builder.setUnionError(unionError);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _STRUCTERROR:
          if (__field.type == TType.STRUCT) {
            test.fixtures.complex_struct.MyStruct structError = test.fixtures.complex_struct.MyStruct.read0(oprot);
            builder.setStructError(structError);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _LSMAP:
          if (__field.type == TType.MAP) {
            it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> lsMap;
            {
            TMap _map = oprot.readMapBegin();
            if (_map.size < 0) {
                throw new TException("Using an unsupported Map, size is less than zero.");
            }
            lsMap = new it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String>();
            for (int _i = 0; _i < _map.size; _i++) {
                
                long _key1 = oprot.readI64();

                String _value1 = oprot.readString();
                lsMap.put(_key1, _value1);
            }
            }
            oprot.readMapEnd();
            builder.setLsMap(lsMap);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      if (this.message != null) {
        oprot.writeFieldBegin(MESSAGE_FIELD_DESC);
        oprot.writeString(this.message);
        oprot.writeFieldEnd();
      }
      if (this.listStrings != null) {
        oprot.writeFieldBegin(LIST_STRINGS_FIELD_DESC);
        List<String> _iter0 = this.listStrings;
        oprot.writeListBegin(new TList(TType.STRING, _iter0.size()));
        for (String _iter1 : _iter0) {
          oprot.writeString(_iter1);
        }
        oprot.writeListEnd();
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(ERROR_ENUM_FIELD_DESC);
      oprot.writeI32(this.errorEnum == null ? 0 : this.errorEnum.getValue());
      oprot.writeFieldEnd();
      if (this.unionError != null) {
        oprot.writeFieldBegin(UNION_ERROR_FIELD_DESC);
        this.unionError.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (this.structError != null) {
        oprot.writeFieldBegin(STRUCT_ERROR_FIELD_DESC);
        this.structError.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (this.lsMap != null) {
        oprot.writeFieldBegin(LS_MAP_FIELD_DESC);
        it.unimi.dsi.fastutil.longs.Long2ObjectArrayMap<String> _iter0 = this.lsMap;
        oprot.writeMapBegin(new TMap(TType.I64, TType.STRING, _iter0.size()));
        for (Map.Entry<Long, String> _iter1 : _iter0.entrySet()) {
          oprot.writeI64(_iter1.getKey());
          oprot.writeString(_iter1.getValue());
        }
        oprot.writeMapEnd();
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
