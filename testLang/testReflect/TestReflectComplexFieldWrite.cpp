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

DECLARE_CLASS(MyWriteMember) {
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
  DECLARE_REFLECT_FIELD(MyWriteMember,intData,byteData,doubleData,
                        floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                        uint64Data,boolData)
};

DECLARE_CLASS(MyComplexWriteMember) {
public:
  MyWriteMember complexMember1;
  MyWriteMember complexMember2;

  DECLARE_REFLECT_FIELD(MyComplexWriteMember,complexMember1,complexMember2)
};

DECLARE_CLASS(MyData6) {
public:
    MyComplexWriteMember data1;
    DECLARE_REFLECT_FIELD(MyData6,data1)
};

void testReflectComplexFieldWrite() {
    //test1
    while(1) {
      MyData6 data = MyData6::New();
      Object _data = data->getField("data1")->createObject();
      Object data1 = _data->getField("complexMember1")->createObject();
      Field f = data1->getField("intData");
      f->setValue(1);

      f = data1->getField("byteData");
      f->setValue(2);

      f = data1->getField("doubleData");
      f->setValue(1.1);

      f = data1->getField("floatData");
      f->setValue(2.2f);

      f = data1->getField("longData");
      f->setValue(3);

      f = data1->getField("stringData");
      f->setValue(String::New("a"));

      f = data1->getField("uint8Data");
      f->setValue(4);

      f = data1->getField("uint16Data");
      f->setValue(5);

      f = data1->getField("uint32Data");
      f->setValue(6);

      f = data1->getField("uint64Data");
      f->setValue(7);

      f = data1->getField("boolData");
      f->setValue(false);

      if(data->data1->complexMember1->intData != 1) {
        TEST_FAIL("Reflect Reflect Complex Write test1");
        break;
      }

      if(data->data1->complexMember1->byteData != 2) {
        TEST_FAIL("Reflect Reflect Complex Write test2");
        break;
      }

      if(data->data1->complexMember1->doubleData != 1.1) {
        TEST_FAIL("Reflect Reflect Complex Write test3");
        break;
      }

      if(st(Float)::Compare(data->data1->complexMember1->floatData,2.2) != 0) {
        TEST_FAIL("Reflect Reflect Complex Write test4");
        break;
      }

      if(data->data1->complexMember1->longData != 3) {
        TEST_FAIL("Reflect Reflect Complex Write test5");
        break;
      }

      if(!data->data1->complexMember1->stringData->sameAs("a")) {
        TEST_FAIL("Reflect Reflect Complex Write test6");
        break;
      }

      if(data->data1->complexMember1->uint8Data != 4) {
        TEST_FAIL("Reflect Reflect Complex Write test7");
        break;
      }

      if(data->data1->complexMember1->uint16Data != 5) {
        TEST_FAIL("Reflect Reflect Complex Write test8");
        break;
      }

      if(data->data1->complexMember1->uint32Data != 6) {
        TEST_FAIL("Reflect Reflect Complex Write test9");
        break;
      }

      if(data->data1->complexMember1->uint64Data != 7) {
        TEST_FAIL("Reflect Reflect Complex Write test10");
        break;
      }

      if(data->data1->complexMember1->boolData) {
        TEST_FAIL("Reflect Reflect Complex Write test11");
        break;
      }

      TEST_OK("Reflect Reflect Complex Write test12");
      break;
    }
}
