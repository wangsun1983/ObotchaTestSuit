#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <type_traits>

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "Reflect.hpp"
#include "String.hpp"
#include "Math.hpp"
#include "Field.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyMember) {
public:
  int intData;
  byte byteData;
  double doubleData;
  float floatData;
  long longData;
  String stringData;
  uint8_t uint8Data;
  uint16_t uint16Data;
  uint32_t uint32Data;
  uint64_t uint64Data;
  bool boolData;
  DECLARE_REFLECT_FIELD(MyMember,intData,byteData,doubleData,
                        floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                        uint64Data,boolData)
};

DECLARE_CLASS(MyComplexMember) {
public:
  MyMember complexMember1;
  MyMember complexMember2;

  DECLARE_REFLECT_FIELD(MyComplexMember,complexMember1,complexMember2)
};

DECLARE_CLASS(MyData5) {
public:
    MyComplexMember data1;
    DECLARE_REFLECT_FIELD(MyData5,data1)
};

void testReflectComplexFieldRead() {
    //test1
    while(1) {
      MyData5 data = createMyData5();
      data->data1 = createMyComplexMember();
      data->data1->complexMember1 = createMyMember();
      data->data1->complexMember1->intData = 1;
      data->data1->complexMember1->byteData = 2;
      data->data1->complexMember1->doubleData = 1.1;
      data->data1->complexMember1->floatData = 2.2;
      data->data1->complexMember1->longData = 3;
      data->data1->complexMember1->stringData = createString("a");
      data->data1->complexMember1->uint8Data = 4;
      data->data1->complexMember1->uint16Data = 5;
      data->data1->complexMember1->uint32Data = 6;
      data->data1->complexMember1->uint64Data = 7;
      data->data1->complexMember1->boolData = false;

      data->data1->complexMember2 = createMyMember();
      data->data1->complexMember2->intData = 11;
      data->data1->complexMember2->byteData = 12;
      data->data1->complexMember2->doubleData = 11.1;
      data->data1->complexMember2->floatData = 12.2;
      data->data1->complexMember2->longData = 13;
      data->data1->complexMember2->stringData = createString("b");
      data->data1->complexMember2->uint8Data = 14;
      data->data1->complexMember2->uint16Data = 15;
      data->data1->complexMember2->uint32Data = 16;
      data->data1->complexMember2->uint64Data = 17;
      data->data1->complexMember2->boolData = false;

      Field memberField = data->getField("data1");
      Object dd = memberField->getObjectValue();
      Object data1 = dd->getField("complexMember1")->getObjectValue();
      //check field
      Field f = data1->getField("intData");
      if(f->getIntValue() != 1 || f->getType() != st(Field)::Type::Int) {
        TEST_FAIL("Reflect Complex Field Read test1");
        break;
      }
      f = data1->getField("byteData");
      if(f->getByteValue() != 2 || f->getType() != st(Field)::Type::Byte) {
        TEST_FAIL("Reflect Complex Field Read test2");
        break;
      }

      f = data1->getField("doubleData");
      if(f->getDoubleValue() != 1.1 || f->getType() != st(Field)::Type::Double) {
        TEST_FAIL("Reflect Complex Field Read test3");
        break;
      }

      f = data1->getField("floatData");
      if(st(Float)::Compare(2.2,f->getFloatValue()) != 0 || f->getType() != st(Field)::Type::Float) {
        TEST_FAIL("Reflect Complex Field Read test4");
        break;
      }

      f = data1->getField("longData");
      if(f->getLongValue() != 3 || f->getType() != st(Field)::Type::Long) {
        TEST_FAIL("Reflect Complex Field Read test5");
        break;
      }

      f = data1->getField("stringData");
      String v = f->getStringValue();
      if(v == nullptr || !v->sameAs("a")|| f->getType() != st(Field)::Type::String) {
        TEST_FAIL("Reflect Complex Field Read test6");
        break;
      }

      f = data1->getField("uint8Data");
      if(f->getByteValue() != 4 || f->getType() != st(Field)::Type::Byte) {
        TEST_FAIL("Reflect Complex Field Read test7");
        break;
      }

      f = data1->getField("uint16Data");
      if(f->getUint16Value() != 5 || f->getType() != st(Field)::Type::Uint16) {
        TEST_FAIL("Reflect Complex Field Read test7");
        break;
      }

      f = data1->getField("uint32Data");
      if(f->getUint32Value() != 6 || f->getType() != st(Field)::Type::Uint32) {
        TEST_FAIL("Reflect Complex Field Read test8");
        break;
      }

      f = data1->getField("uint64Data");
      if(f->getUint64Value() != 7 || f->getType() != st(Field)::Type::Uint64) {
        TEST_FAIL("Reflect Complex Field Read test9");
        break;
      }

      f = data1->getField("boolData");
      if(f->getBoolValue() || f->getType() != st(Field)::Type::Bool) {
        TEST_FAIL("Reflect Complex Field Read test10");
        break;
      }

      //data2
      Object data2 = dd->getField("complexMember2")->getObjectValue();
      //check field
      f = data2->getField("intData");
      if(f->getIntValue() != 11 || f->getType() != st(Field)::Type::Int) {
        TEST_FAIL("Reflect Complex Field Read test11");
        break;
      }

      f = data2->getField("byteData");
      if(f->getByteValue() != 12 || f->getType() != st(Field)::Type::Byte) {
        TEST_FAIL("Reflect Complex Field Read test12");
        break;
      }

      f = data2->getField("doubleData");
      if(f->getDoubleValue() != 11.1 || f->getType() != st(Field)::Type::Double) {
        TEST_FAIL("Reflect Complex Field Read test13");
        break;
      }

      f = data2->getField("floatData");
      if(st(Float)::Compare(12.2,f->getFloatValue()) != 0 || f->getType() != st(Field)::Type::Float) {
        TEST_FAIL("Reflect Complex Field Read test14");
        break;
      }

      f = data2->getField("longData");
      if(f->getLongValue() != 13 || f->getType() != st(Field)::Type::Long) {
        TEST_FAIL("Reflect Complex Field Read test15");
        break;
      }

      f = data2->getField("stringData");
      v = f->getStringValue();
      if(v == nullptr || !v->sameAs("b")|| f->getType() != st(Field)::Type::String) {
        TEST_FAIL("Reflect Complex Field Read test16");
        break;
      }

      f = data2->getField("uint8Data");
      if(f->getByteValue() != 14 || f->getType() != st(Field)::Type::Byte) {
        TEST_FAIL("Reflect Complex Field Read test17");
        break;
      }

      f = data2->getField("uint16Data");
      if(f->getUint16Value() != 15 || f->getType() != st(Field)::Type::Uint16) {
        TEST_FAIL("Reflect Complex Field Read test17");
        break;
      }

      f = data2->getField("uint32Data");
      if(f->getUint32Value() != 16 || f->getType() != st(Field)::Type::Uint32) {
        TEST_FAIL("Reflect Complex Field Read test18");
        break;
      }

      f = data2->getField("uint64Data");
      if(f->getUint64Value() != 17 || f->getType() != st(Field)::Type::Uint64) {
        TEST_FAIL("Reflect Complex Field Read test19");
        break;
      }

      f = data2->getField("boolData");
      if(f->getBoolValue() || f->getType() != st(Field)::Type::Bool) {
        TEST_FAIL("Reflect Complex Field Read test10");
        break;
      }

      TEST_OK("Reflect Complex Field Read test11");
      break;
    }
}
