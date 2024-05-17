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
#include "TestLog.hpp"
#include "JsonReader.hpp"
#include "Math.hpp"

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

void testReflectToJson() {
  //test1
  while(1) {
    ReflectData data = ReflectData::New();
    data->member1 = ReflectWriteMember::New();
    data->member2 = ReflectWriteMember::New();

    data->member1->intData = 1;
    data->member1->byteData = 2;
    data->member1->doubleData = 1.1;
    data->member1->floatData = 2.2;
    data->member1->longData = 3;
    data->member1->stringData = String::New("a");
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
    data->member2->stringData = String::New("b");
    data->member2->uint8Data = 14;
    data->member2->uint16Data = 15;
    data->member2->uint32Data = 16;
    data->member2->uint64Data = 17;
    data->member2->boolData = false;

    JsonValue jvalue = JsonValue::New();
    jvalue->importFrom(data);

    JsonWriter jwriter = JsonWriter::New("output1.json");
    jwriter->write(jvalue);

    JsonReader r = JsonReader::New()->loadFile(File::New("output1.json"));

    ReflectData result = ReflectData::New();
    JsonValue jvalue1 = r->get();
    jvalue1->reflectTo(result);
    if(result->member1 == nullptr || result->member2 == nullptr) {
      TEST_FAIL("testReflectToJson test1");
    }

    if(result->member1->intData != data->member1->intData) {
      TEST_FAIL("testReflectToJson test2");
    }

    if(result->member1->byteData != data->member1->byteData) {
      TEST_FAIL("testReflectToJson test3,data1 is %d,data2 is %d",result->member1->byteData,data->member1->byteData);
    }

    if(result->member1->byteData != data->member1->byteData) {
      TEST_FAIL("testReflectToJson test4");
    }

    if(result->member1->longData != data->member1->longData) {
      TEST_FAIL("testReflectToJson test5");
    }

    if(!result->member1->stringData->equals(data->member1->stringData)) {
      TEST_FAIL("testReflectToJson test6");
    }

    if(result->member1->uint8Data != data->member1->uint8Data) {
      TEST_FAIL("testReflectToJson test7");
    }

    if(result->member1->uint16Data != data->member1->uint16Data) {
      TEST_FAIL("testReflectToJson test8");
    }

    if(result->member1->uint32Data != data->member1->uint32Data) {
      TEST_FAIL("testReflectToJson test9");
    }

    if(result->member1->uint64Data != data->member1->uint64Data) {
      TEST_FAIL("testReflectToJson test10");
    }

    if(result->member1->boolData != data->member1->boolData) {
      TEST_FAIL("testReflectToJson test11");
    }

    if(st(Double)::Compare(result->member1->doubleData,result->member1->doubleData) != 0) {
      TEST_FAIL("testReflectToJson test12");
    }

    if(st(Float)::Compare(result->member1->floatData,result->member1->floatData) != 0) {
      TEST_FAIL("testReflectToJson test13");
    }

    if(result->member1->intData != data->member1->intData) {
      TEST_FAIL("testReflectToJson test2");
    }

    if(result->member1->byteData != data->member1->byteData) {
      TEST_FAIL("testReflectToJson test3");
    }

    if(result->member1->byteData != data->member1->byteData) {
      TEST_FAIL("testReflectToJson test4");
    }

    if(result->member1->longData != data->member1->longData) {
      TEST_FAIL("testReflectToJson test5");
    }

    if(!result->member1->stringData->equals(data->member1->stringData)) {
      TEST_FAIL("testReflectToJson test6");
    }

    if(result->member1->uint8Data != data->member1->uint8Data) {
      TEST_FAIL("testReflectToJson test7");
    }

    if(result->member1->uint16Data != data->member1->uint16Data) {
      TEST_FAIL("testReflectToJson test8");
    }

    if(result->member1->uint32Data != data->member1->uint32Data) {
      TEST_FAIL("testReflectToJson test9");
    }

    if(result->member1->uint64Data != data->member1->uint64Data) {
      TEST_FAIL("testReflectToJson test10");
    }

    if(result->member1->boolData != data->member1->boolData) {
      TEST_FAIL("testReflectToJson test11");
    }

    if(st(Double)::Compare(result->member1->doubleData,result->member1->doubleData) != 0) {
      TEST_FAIL("testReflectToJson test12");
    }

    if(st(Float)::Compare(result->member1->floatData,result->member1->floatData) != 0) {
      TEST_FAIL("testReflectToJson test13");
    }

    //member2
    if(result->member2->intData != data->member2->intData) {
      TEST_FAIL("testReflectToJson test14");
    }

    if(result->member2->byteData != data->member2->byteData) {
      TEST_FAIL("testReflectToJson test15");
    }

    if(result->member2->byteData != data->member2->byteData) {
      TEST_FAIL("testReflectToJson test16");
    }

    if(result->member2->longData != data->member2->longData) {
      TEST_FAIL("testReflectToJson test17");
    }

    if(!result->member2->stringData->equals(data->member2->stringData)) {
      TEST_FAIL("testReflectToJson test18");
    }

    if(result->member2->uint8Data != data->member2->uint8Data) {
      TEST_FAIL("testReflectToJson test19");
    }

    if(result->member2->uint16Data != data->member2->uint16Data) {
      TEST_FAIL("testReflectToJson test20");
    }

    if(result->member2->uint32Data != data->member2->uint32Data) {
      TEST_FAIL("testReflectToJson test21");
    }

    if(result->member2->uint64Data != data->member2->uint64Data) {
      TEST_FAIL("testReflectToJson test22");
    }

    if(result->member2->boolData != data->member2->boolData) {
      TEST_FAIL("testReflectToJson test23");
    }

    if(st(Double)::Compare(result->member2->doubleData,result->member2->doubleData) != 0) {
      TEST_FAIL("testReflectToJson test24");
    }

    if(st(Float)::Compare(result->member2->floatData,result->member2->floatData) != 0) {
      TEST_FAIL("testReflectToJson test25");
    }

    break;
  }
}
