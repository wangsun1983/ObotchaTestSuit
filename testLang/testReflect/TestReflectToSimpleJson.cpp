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
#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ReflectWriteMember) {
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
  DECLARE_REFLECT_FIELD(ReflectWriteMember,intData,byteData,doubleData,
                        floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                        uint64Data,boolData)
};

DECLARE_CLASS(ReflectData) {
public:
  ReflectWriteMember member1;
  ReflectWriteMember member2;
  DECLARE_REFLECT_FIELD(ReflectData,member1,member2)
};

void testReflectToSimpleJson() {
  //test1
  while(1) {
    ReflectData data = createReflectData();
    data->member1 = createReflectWriteMember();
    data->member2 = createReflectWriteMember();
    data->member1->intData = 1;
    data->member1->byteData = 2;
    data->member1->doubleData = 1.1;
    data->member1->floatData = 2.2;
    data->member1->longData = 3;
    data->member1->stringData = createString("a");
    data->member1->uint8Data = 4;
    data->member1->uint16Data = 5;
    data->member1->uint32Data = 6;
    data->member1->uint64Data = 7;
    data->member1->boolData = false;

    data->member2->intData = 11;
    data->member2->byteData = 12;
    data->member2->doubleData = 11.1;
    data->member2->floatData = 12.2;
    data->member2->longData = 13;
    data->member2->stringData = createString("b");
    data->member2->uint8Data = 14;
    data->member2->uint16Data = 15;
    data->member2->uint32Data = 16;
    data->member2->uint64Data = 17;
    data->member2->boolData = false;
    JsonValue jvalue = createJsonValue();
    jvalue->importFrom(data);
    JsonWriter jwriter = createJsonWriter("output1.json");
    jwriter->write(jvalue);
    JsonReader reader = createJsonReader()->loadFile(createFile("output1.json"));
    JsonValue readValue = reader->get();

    ReflectData rdata3 = createReflectData();
    readValue->reflectTo(rdata3);

    if(data->member1->intData != rdata3->member1->intData) {
      TEST_FAIL("Reflect to json test1");
      break;
    }

    if(data->member1->byteData != rdata3->member1->byteData) {
      TEST_FAIL("Reflect to json test2");
      break;
    }

    if(data->member1->doubleData != rdata3->member1->doubleData) {
      TEST_FAIL("Reflect to json test3");
      break;
    }

    if(data->member1->floatData != rdata3->member1->floatData) {
      TEST_FAIL("Reflect to json test4");
      break;
    }

    if(data->member1->longData != rdata3->member1->longData) {
      TEST_FAIL("Reflect to json test5");
      break;
    }

    if(!data->member1->stringData->equals(rdata3->member1->stringData)) {
      TEST_FAIL("Reflect to json test6");
      break;
    }

    if(data->member1->uint8Data != rdata3->member1->uint8Data) {
      TEST_FAIL("Reflect to json test7");
      break;
    }

    if(data->member1->uint16Data != rdata3->member1->uint16Data) {
      TEST_FAIL("Reflect to json test8");
      break;
    }

    if(data->member1->uint32Data != rdata3->member1->uint32Data) {
      TEST_FAIL("Reflect to json test9");
      break;
    }

    if(data->member1->uint64Data != rdata3->member1->uint64Data) {
      TEST_FAIL("Reflect to json test10");
      break;
    }

    if(data->member1->boolData != rdata3->member1->boolData) {
      TEST_FAIL("Reflect to json test11");
      break;
    }

    TEST_OK("Reflect to json test12");
    break;
  }
}
