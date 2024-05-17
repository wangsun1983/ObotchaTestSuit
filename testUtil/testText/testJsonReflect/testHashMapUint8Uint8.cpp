#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint8.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint8.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint8) {
public:
  HashMap<Uint8,Uint8> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint8,maps)
};

void testHashMapUint8Uint8() {
    while(1) {
      HashMap<Uint8,Uint8> maps = HashMap<Uint8,Uint8>::New();
      maps->put(Uint8::New(1),Uint8::New(10));
      maps->put(Uint8::New(2),Uint8::New(20));
      maps->put(Uint8::New(3),Uint8::New(30));
      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Uint8_Uint8_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(maps);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Uint8_Uint8_test1.json"));
      JsonValue value2 = reader->get();

      HashMap<Uint8,Uint8> maps2 = HashMap<Uint8,Uint8>::New();
      value2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case1]  ");
        break;
      }

      auto v1 = maps2->get(Uint8::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case2]  ");
        break;
      }

      auto v2 = maps2->get(Uint8::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case3]  ");
        break;
      }

      auto v3 = maps2->get(Uint8::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case4]  ");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint8 data = HashmapDataUint8::New();
      HashMap<Uint8,Uint8> maps = HashMap<Uint8,Uint8>::New();
      maps->put(Uint8::New(1),Uint8::New(10));
      maps->put(Uint8::New(2),Uint8::New(20));
      maps->put(Uint8::New(3),Uint8::New(30));
      data->maps = maps;

      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Uint8_Uint8_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Uint8_Uint8_test2.json"));
      JsonValue value2 = reader->get();

      HashmapDataUint8 data2 = HashmapDataUint8::New();
      value2->reflectTo(data2);
      HashMap<Uint8,Uint8> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case5]  ");
        break;
      }

      auto v1 = maps2->get(Uint8::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case6]  ");
        break;
      }

      auto v2 = maps2->get(Uint8::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case7]  ");
        break;
      }

      auto v3 = maps2->get(Uint8::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint8 Uint8 Test case8]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect HashMap Uint8 Uint8 Test case100]");
}
