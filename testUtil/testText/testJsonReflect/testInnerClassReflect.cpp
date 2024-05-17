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

using namespace obotcha;

DECLARE_CLASS(InnerData1) {
  public:
    int intData;
    DECLARE_REFLECT_FIELD(InnerData1,intData)
};

DECLARE_CLASS(InnerData2) {
  public:
    String stringData;
    DECLARE_REFLECT_FIELD(InnerData2,stringData)
};

DECLARE_CLASS(OuterData) {
public:
    InnerData1 data1;
    InnerData2 data2;

    DECLARE_REFLECT_FIELD(OuterData,data1,data2)
};

void testInnerClassReflect() {
    while(1) {
        OuterData data = OuterData::New();
        data->data1 = InnerData1::New();
        data->data1->intData = 1000;
        data->data2 = InnerData2::New();
        data->data2->stringData = String::New("hello world");

        JsonWriter writer = JsonWriter::New("./tmp/inner_class_test1.json");
        JsonValue value = JsonValue::New();
        value->importFrom(data);
        writer->write(value);

        JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/inner_class_test1.json"));
        JsonValue value2 = reader->get();
        OuterData data2 = OuterData::New();
        value2->reflectTo(data2);

        if(data2->data1 == nullptr ||
          data2->data2 == nullptr) {
            TEST_FAIL("[JsonReflect Inner Data Reflect Test case1]  ");
        }

        if(data2->data1->intData != 1000 ||
          !data2->data2->stringData->sameAs("hello world")) {
            TEST_FAIL("[JsonReflect Inner Data Reflect Test case2]  ");
        }
        break;
    }

    TEST_OK("[JsonReflect UserData Reflect Test case100]");
}
