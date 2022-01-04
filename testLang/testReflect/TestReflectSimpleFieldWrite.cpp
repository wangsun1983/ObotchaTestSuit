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

DECLARE_CLASS(MyData3) {
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
    DECLARE_REFLECT_FIELD(MyData3,intData,byteData,doubleData,
                          floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                          uint64Data,boolData)
};

DECLARE_CLASS(MyData4) {
public:
    Integer intData;
    Byte byteData;
    Double doubleData;
    Float floatData;
    Boolean boolData;
    Long longData;
    String stringData;
    Uint8 uint8Data;
    Uint16 uint16Data;
    Uint32 uint32Data;
    Uint64 uint64Data;
    DECLARE_REFLECT_FIELD(MyData4,intData,byteData,doubleData,
                          floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                          uint64Data,boolData)
};


void testReflectFieldWrite() {
    //test1
    while(1) {
      MyData3 data1 = createMyData3();
      //check field
      Field f = data1->getField("intData");
      f->setValue(1);

      f = data1->getField("byteData");
      f->setValue(2);

      f = data1->getField("doubleData");
      f->setValue(1.1);

      f = data1->getField("floatData");
      f->setValue(2.2);

      f = data1->getField("longData");
      f->setValue(3);

      f = data1->getField("stringData");
      f->setValue(createString("a"));

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
      if(data1->intData != 1) {
        TEST_FAIL("Reflect Reflect Field Write test1");
        break;
      }

      if(data1->byteData != 2) {
        TEST_FAIL("Reflect Reflect Field Write test2");
        break;
      }

      if(data1->doubleData != 1.1) {
        TEST_FAIL("Reflect Reflect Field Write test3");
        break;
      }

      if(st(Math)::compareFloat(data1->floatData,2.2) != st(Math)::AlmostEqual) {
        TEST_FAIL("Reflect Reflect Field Write test4");
        break;
      }

      if(data1->longData != 3) {
        TEST_FAIL("Reflect Reflect Field Write test5");
        break;
      }

      if(!data1->stringData->equals("a")) {
        TEST_FAIL("Reflect Reflect Field Write test6");
        break;
      }

      if(data1->uint8Data != 4) {
        TEST_FAIL("Reflect Reflect Field Write test7");
        break;
      }

      if(data1->uint16Data != 5) {
        TEST_FAIL("Reflect Reflect Field Write test8");
        break;
      }

      if(data1->uint32Data != 6) {
        TEST_FAIL("Reflect Reflect Field Write test9");
        break;
      }

      if(data1->uint64Data != 7) {
        TEST_FAIL("Reflect Reflect Field Write test10");
        break;
      }

      if(data1->boolData) {
        TEST_FAIL("Reflect Reflect Field Write test11");
        break;
      }

      TEST_OK("Reflect Reflect Field test12");
      break;
    }

    //test1
    while(1) {
      MyData4 data1 = createMyData4();
      //check field
      Field f = data1->getField("intData");
      Integer v1 = Cast<Integer>(f->createObject());
      v1->update(1);

      f = data1->getField("byteData");
      Byte v2 = Cast<Byte>(f->createObject());
      v2->update(2);

      f = data1->getField("doubleData");
      Double v3 = Cast<Double>(f->createObject());
      v3->update(1.1);

      f = data1->getField("floatData");
      Float v4 = Cast<Float>(f->createObject());
      v4->update(2.2);

      f = data1->getField("longData");
      Long v5 = Cast<Long>(f->createObject());
      v5->update(3);

      f = data1->getField("stringData");
      f->setValue(createString("a"));

      f = data1->getField("uint8Data");
      Uint8 v7 = Cast<Uint8>(f->createObject());
      v7->update(4);

      f = data1->getField("uint16Data");
      Uint16 v7_1 = Cast<Uint16>(f->createObject());
      v7_1->update(5);

      f = data1->getField("uint32Data");
      Uint32 v8 = Cast<Uint32>(f->createObject());
      v8->update(6);

      f = data1->getField("uint64Data");
      Uint64 v9 = Cast<Uint64>(f->createObject());
      v9->update(7);

      f = data1->getField("boolData");
      Boolean v10 = Cast<Boolean>(f->createObject());
      v10->update(false);

      if(data1->intData == nullptr||data1->intData->toValue() != 1) {
        TEST_FAIL("Reflect Reflect Field Write test13");
        break;
      }

      if(data1->byteData == nullptr || data1->byteData->toValue() != 2) {
        TEST_FAIL("Reflect Reflect Field Write test14");
        break;
      }

      if(data1->doubleData == nullptr ||data1->doubleData->toValue() != 1.1) {
        TEST_FAIL("Reflect Reflect Field Write test15");
        break;
      }

      if(data1->floatData == nullptr
        ||st(Math)::compareFloat(data1->floatData->toValue(),2.2) != st(Math)::AlmostEqual) {
        TEST_FAIL("Reflect Reflect Field Write test16");
        break;
      }

      if(data1->longData == nullptr ||data1->longData->toValue() != 3) {
        TEST_FAIL("Reflect Reflect Field Write test17");
        break;
      }

      if(data1->stringData == nullptr ||!data1->stringData->equals("a")) {
        TEST_FAIL("Reflect Reflect Field Write test18");
        break;
      }

      if(data1->uint8Data == nullptr ||data1->uint8Data->toValue() != 4) {
        TEST_FAIL("Reflect Reflect Field Write test19");
        break;
      }

      if(data1->uint16Data == nullptr ||data1->uint16Data->toValue() != 5) {
        TEST_FAIL("Reflect Reflect Field Write test20");
        break;
      }

      if(data1->uint32Data == nullptr ||data1->uint32Data->toValue() != 6) {
        TEST_FAIL("Reflect Reflect Field Write test21");
        break;
      }

      if(data1->uint64Data == nullptr ||data1->uint64Data->toValue() != 7) {
        TEST_FAIL("Reflect Reflect Field Write test22");
        break;
      }

      if(data1->boolData == nullptr ||data1->boolData->toValue()) {
        TEST_FAIL("Reflect Reflect Field Write test23");
        break;
      }

      TEST_OK("Reflect Reflect Field test24");
      break;
    }

}
