#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Integer.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "Float.hpp"
#include "Double.hpp"

using namespace obotcha;

DECLARE_CLASS(ReflectUserData) {
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

    DECLARE_REFLECT_FIELD(ReflectUserData,intData,byteData,doubleData,
                          floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                          uint64Data,boolData)
};

DECLARE_CLASS(ReflectUserObjData) {
public:
    Integer intObjData;
    Long longObjData;
    Uint8 uint8ObjData;
    Uint16 uint16ObjData;
    Uint32 uint32ObjData;
    Uint64 uint64ObjData;
    Boolean boolObjData;
    Float floatObjData;
    Double doubleObjData;
    Byte byteObjData;

    DECLARE_REFLECT_FIELD(ReflectUserObjData,intObjData,longObjData,uint8ObjData,
                          uint16ObjData,uint32ObjData,uint64ObjData,boolObjData,
                          floatObjData,doubleObjData,byteObjData)
};

void testUserDataReflect() {
    while(1) {
      ReflectUserData data = ReflectUserData::New();
      data->intData = 100;
      data->byteData = 25;
      data->doubleData = 100.10;
      data->floatData = 101.10;
      data->longData = 102;
      data->stringData = S("hhh");
      data->uint8Data = 103;
      data->uint16Data = 104;
      data->uint32Data = 105;
      data->uint64Data = 107;
      data->boolData = true;

      JsonWriter writer = JsonWriter::New("./tmp/userdata_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/userdata_test1.json"));
      JsonValue value2 = reader->get();
      ReflectUserData data2 = ReflectUserData::New();
      value2->reflectTo(data2);
      if(data2->intData != 100 ||
          data2->byteData != 25 ||
          data2->longData != 102 ||
         !data2->stringData->sameAs("hhh") ||
          data2->uint8Data != 103 ||
          data2->uint16Data != 104 ||
          data2->uint32Data != 105 ||
          data2->uint64Data != 107 ||
          !data2->boolData) {
            TEST_FAIL("[JsonReflect UserData Reflect Test case1]  ");
      }

      if(st(Double)::Compare(data2->doubleData,100.10) != 0) {
          TEST_FAIL("[JsonReflect UserData Reflect Test case1_1]  ");
      }

      if(st(Float)::Compare(data2->floatData,101.10) != 0) {
          TEST_FAIL("[JsonReflect UserData Reflect Test case1_2]  ");
      }
      break;
    }

    while(1) {
      ReflectUserObjData data = ReflectUserObjData::New();
      data->intObjData = Integer::New(100);
      data->longObjData = Long::New(101);
      data->uint8ObjData = Uint8::New(102);
      data->uint16ObjData = Uint16::New(103);
      data->uint32ObjData = Uint32::New(104);
      data->uint64ObjData = Uint64::New(105);
      data->boolObjData = Boolean::New(true);
      data->floatObjData = Float::New(102.10);
      data->doubleObjData = Double::New(103.20);
      data->byteObjData = Byte::New(23);

      JsonWriter writer = JsonWriter::New("./tmp/userdata_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/userdata_test2.json"));
      JsonValue value2 = reader->get();
      ReflectUserData data2 = ReflectUserData::New();
      value2->reflectTo(data2);

      if(data->intObjData == nullptr ||
        data->longObjData == nullptr ||
        data->uint8ObjData == nullptr ||
        data->uint16ObjData == nullptr ||
        data->uint32ObjData == nullptr ||
        data->uint64ObjData == nullptr ||
        data->boolObjData == nullptr||
        data->floatObjData == nullptr ||
        data->doubleObjData == nullptr ||
        data->byteObjData == nullptr) {
          TEST_FAIL("[JsonReflect UserData Reflect Test case2]  ");
        }

      if(data->intObjData->toValue() != 100 ||
        data->longObjData->toValue() != 101 ||
        data->uint8ObjData->toValue() != 102 ||
        data->uint16ObjData->toValue() != 103 ||
        data->uint32ObjData->toValue() != 104 ||
        data->uint64ObjData->toValue() != 105 ||
        !data->boolObjData->toValue() ||
        data->byteObjData->toValue() != 23) {
          TEST_FAIL("[JsonReflect UserData Reflect Test case3]  ");
        }

        if(st(Float)::Compare(data->floatObjData->toValue(),102.10) != 0) {
            TEST_FAIL("[JsonReflect UserData Reflect Test case3_1]  ");
        }

        if(st(Double)::Compare(data->doubleObjData->toValue(),103.20) != 0) {
            TEST_FAIL("[JsonReflect UserData Reflect Test case3_2]  ");
        }
        break;
    }
    TEST_OK("[JsonReflect UserData Reflect Test case100]");
}
