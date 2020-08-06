/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.swift.enumstrict;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@ThriftStruct(value="MyStruct", builder=MyStruct.Builder.class)
public final class MyStruct {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public MyStruct(
        @ThriftField(value=1, name="myEnum", requiredness=Requiredness.NONE) final test.fixtures.swift.enumstrict.MyEnum myEnum,
        @ThriftField(value=2, name="myBigEnum", requiredness=Requiredness.NONE) final test.fixtures.swift.enumstrict.MyBigEnum myBigEnum
    ) {
        this.myEnum = myEnum;
        this.myBigEnum = myBigEnum;
    }
    
    @ThriftConstructor
    protected MyStruct() {
      this.myEnum = null;
      this.myBigEnum = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private test.fixtures.swift.enumstrict.MyEnum myEnum = null;
        private test.fixtures.swift.enumstrict.MyBigEnum myBigEnum = test.fixtures.swift.enumstrict.MyBigEnum.ONE;
    
        @ThriftField(value=1, name="myEnum", requiredness=Requiredness.NONE)
        public Builder setMyEnum(test.fixtures.swift.enumstrict.MyEnum myEnum) {
            this.myEnum = myEnum;
            return this;
        }
    
        public test.fixtures.swift.enumstrict.MyEnum getMyEnum() { return myEnum; }
    
            @ThriftField(value=2, name="myBigEnum", requiredness=Requiredness.NONE)
        public Builder setMyBigEnum(test.fixtures.swift.enumstrict.MyBigEnum myBigEnum) {
            this.myBigEnum = myBigEnum;
            return this;
        }
    
        public test.fixtures.swift.enumstrict.MyBigEnum getMyBigEnum() { return myBigEnum; }
    
        public Builder() { }
        public Builder(MyStruct other) {
            this.myEnum = other.myEnum;
            this.myBigEnum = other.myBigEnum;
        }
    
        @ThriftConstructor
        public MyStruct build() {
            MyStruct result = new MyStruct (
                this.myEnum,
                this.myBigEnum
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyStruct");
    private final test.fixtures.swift.enumstrict.MyEnum myEnum;
    public static final int _MYENUM = 1;
    private static final TField MY_ENUM_FIELD_DESC = new TField("myEnum", TType.I32, (short)1);
        private final test.fixtures.swift.enumstrict.MyBigEnum myBigEnum;
    public static final int _MYBIGENUM = 2;
    private static final TField MY_BIG_ENUM_FIELD_DESC = new TField("myBigEnum", TType.I32, (short)2);
    static {
      NAMES_TO_IDS.put("myEnum", 1);
      FIELD_METADATA.put(1, MY_ENUM_FIELD_DESC);
      NAMES_TO_IDS.put("myBigEnum", 2);
      FIELD_METADATA.put(2, MY_BIG_ENUM_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="myEnum", requiredness=Requiredness.NONE)
    public test.fixtures.swift.enumstrict.MyEnum getMyEnum() { return myEnum; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetMyEnum() {
        return this.myEnum != null;
    }
    
    
    @ThriftField(value=2, name="myBigEnum", requiredness=Requiredness.NONE)
    public test.fixtures.swift.enumstrict.MyBigEnum getMyBigEnum() { return myBigEnum; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetMyBigEnum() {
        return this.myBigEnum != null;
    }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("myEnum", myEnum);
        helper.add("myBigEnum", myBigEnum);
        return helper.toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyStruct other = (MyStruct)o;
    
        return
            Objects.equals(myEnum, other.myEnum) &&
            Objects.equals(myBigEnum, other.myBigEnum) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            myEnum,
            myBigEnum
        });
    }
    
    
    public static MyStruct read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(MyStruct.NAMES_TO_IDS, MyStruct.FIELD_METADATA);
      MyStruct.Builder builder = new MyStruct.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _MYENUM:
          if (__field.type == TType.I32) {
            test.fixtures.swift.enumstrict.MyEnum myEnum = test.fixtures.swift.enumstrict.MyEnum.fromInteger(oprot.readI32());
            builder.setMyEnum(myEnum);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _MYBIGENUM:
          if (__field.type == TType.I32) {
            test.fixtures.swift.enumstrict.MyBigEnum myBigEnum = test.fixtures.swift.enumstrict.MyBigEnum.fromInteger(oprot.readI32());
            builder.setMyBigEnum(myBigEnum);
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
      oprot.writeFieldBegin(MY_ENUM_FIELD_DESC);
      oprot.writeI32(this.myEnum == null ? 0 : this.myEnum.getValue());
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(MY_BIG_ENUM_FIELD_DESC);
      oprot.writeI32(this.myBigEnum == null ? 0 : this.myBigEnum.getValue());
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
