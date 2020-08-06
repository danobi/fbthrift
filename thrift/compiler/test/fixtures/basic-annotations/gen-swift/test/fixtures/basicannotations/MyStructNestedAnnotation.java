/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basicannotations;

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
@ThriftStruct(value="MyStructNestedAnnotation", builder=MyStructNestedAnnotation.Builder.class)
public final class MyStructNestedAnnotation {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public MyStructNestedAnnotation(
        @ThriftField(value=1, name="name", requiredness=Requiredness.NONE) final String name
    ) {
        this.name = name;
    }
    
    @ThriftConstructor
    protected MyStructNestedAnnotation() {
      this.name = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private String name = null;
    
        @ThriftField(value=1, name="name", requiredness=Requiredness.NONE)
        public Builder setName(String name) {
            this.name = name;
            return this;
        }
    
        public String getName() { return name; }
    
        public Builder() { }
        public Builder(MyStructNestedAnnotation other) {
            this.name = other.name;
        }
    
        @ThriftConstructor
        public MyStructNestedAnnotation build() {
            MyStructNestedAnnotation result = new MyStructNestedAnnotation (
                this.name
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyStructNestedAnnotation");
    private final String name;
    public static final int _NAME = 1;
    private static final TField NAME_FIELD_DESC = new TField("name", TType.STRING, (short)1);
    static {
      NAMES_TO_IDS.put("name", 1);
      FIELD_METADATA.put(1, NAME_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="name", requiredness=Requiredness.NONE)
    public String getName() { return name; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetName() {
        return this.name != null;
    }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("name", name);
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
    
        MyStructNestedAnnotation other = (MyStructNestedAnnotation)o;
    
        return
            Objects.equals(name, other.name) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            name
        });
    }
    
    
    public static MyStructNestedAnnotation read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(MyStructNestedAnnotation.NAMES_TO_IDS, MyStructNestedAnnotation.FIELD_METADATA);
      MyStructNestedAnnotation.Builder builder = new MyStructNestedAnnotation.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _NAME:
          if (__field.type == TType.STRING) {
            String name = oprot.readString();
            builder.setName(name);
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
      if (this.name != null) {
        oprot.writeFieldBegin(NAME_FIELD_DESC);
        oprot.writeString(this.name);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
