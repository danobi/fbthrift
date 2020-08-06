/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.lazy_constants;

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
@ThriftStruct(value="Internship", builder=Internship.Builder.class)
public final class Internship {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public Internship(
        @ThriftField(value=1, name="weeks", requiredness=Requiredness.REQUIRED) final int weeks,
        @ThriftField(value=2, name="title", requiredness=Requiredness.NONE) final String title,
        @ThriftField(value=3, name="employer", requiredness=Requiredness.OPTIONAL) final test.fixtures.lazy_constants.Company employer
    ) {
        this.weeks = weeks;
        this.title = title;
        this.employer = employer;
    }
    
    @ThriftConstructor
    protected Internship() {
      this.weeks = 0;
      this.title = null;
      this.employer = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private int weeks = 0;
        private String title = null;
        private test.fixtures.lazy_constants.Company employer = null;
    
        @ThriftField(value=1, name="weeks", requiredness=Requiredness.REQUIRED)
        public Builder setWeeks(int weeks) {
            this.weeks = weeks;
            return this;
        }
    
        public int getWeeks() { return weeks; }
    
            @ThriftField(value=2, name="title", requiredness=Requiredness.NONE)
        public Builder setTitle(String title) {
            this.title = title;
            return this;
        }
    
        public String getTitle() { return title; }
    
            @ThriftField(value=3, name="employer", requiredness=Requiredness.OPTIONAL)
        public Builder setEmployer(test.fixtures.lazy_constants.Company employer) {
            this.employer = employer;
            return this;
        }
    
        public test.fixtures.lazy_constants.Company getEmployer() { return employer; }
    
        public Builder() { }
        public Builder(Internship other) {
            this.weeks = other.weeks;
            this.title = other.title;
            this.employer = other.employer;
        }
    
        @ThriftConstructor
        public Internship build() {
            Internship result = new Internship (
                this.weeks,
                this.title,
                this.employer
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("Internship");
    private final int weeks;
    public static final int _WEEKS = 1;
    private static final TField WEEKS_FIELD_DESC = new TField("weeks", TType.I32, (short)1);
        private final String title;
    public static final int _TITLE = 2;
    private static final TField TITLE_FIELD_DESC = new TField("title", TType.STRING, (short)2);
        private final test.fixtures.lazy_constants.Company employer;
    public static final int _EMPLOYER = 3;
    private static final TField EMPLOYER_FIELD_DESC = new TField("employer", TType.I32, (short)3);
    static {
      NAMES_TO_IDS.put("weeks", 1);
      FIELD_METADATA.put(1, WEEKS_FIELD_DESC);
      NAMES_TO_IDS.put("title", 2);
      FIELD_METADATA.put(2, TITLE_FIELD_DESC);
      NAMES_TO_IDS.put("employer", 3);
      FIELD_METADATA.put(3, EMPLOYER_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="weeks", requiredness=Requiredness.REQUIRED)
    public int getWeeks() { return weeks; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetWeeks() {
        return __isset_bit_vector.get(_WEEKS);
    }
    
    
    @ThriftField(value=2, name="title", requiredness=Requiredness.NONE)
    public String getTitle() { return title; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetTitle() {
        return this.title != null;
    }
    
    
    @ThriftField(value=3, name="employer", requiredness=Requiredness.OPTIONAL)
    public test.fixtures.lazy_constants.Company getEmployer() { return employer; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetEmployer() {
        return this.employer != null;
    }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("weeks", weeks);
        helper.add("title", title);
        helper.add("employer", employer);
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
    
        Internship other = (Internship)o;
    
        return
            Objects.equals(weeks, other.weeks) &&
            Objects.equals(title, other.title) &&
            Objects.equals(employer, other.employer) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            weeks,
            title,
            employer
        });
    }
    
    
    public static Internship read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(Internship.NAMES_TO_IDS, Internship.FIELD_METADATA);
      Internship.Builder builder = new Internship.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _WEEKS:
          if (__field.type == TType.I32) {
            int weeks = oprot.readI32();
            builder.setWeeks(weeks);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _TITLE:
          if (__field.type == TType.STRING) {
            String title = oprot.readString();
            builder.setTitle(title);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _EMPLOYER:
          if (__field.type == TType.I32) {
            test.fixtures.lazy_constants.Company employer = test.fixtures.lazy_constants.Company.fromInteger(oprot.readI32());
            builder.setEmployer(employer);
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
      oprot.writeFieldBegin(WEEKS_FIELD_DESC);
      oprot.writeI32(this.weeks);
      oprot.writeFieldEnd();
      if (this.title != null) {
        oprot.writeFieldBegin(TITLE_FIELD_DESC);
        oprot.writeString(this.title);
        oprot.writeFieldEnd();
      }
      if (this.employer != null) {
        oprot.writeFieldBegin(EMPLOYER_FIELD_DESC);
        oprot.writeI32(this.employer == null ? 0 : this.employer.getValue());
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
