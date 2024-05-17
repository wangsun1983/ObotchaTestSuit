#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint64.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint64.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint64) {
public:
  HashMap<Uint64,Uint64> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint64,maps)
};

void testHashMapUint64Uint64() {
    while(1) {
      HashMap<Uint64,Uint64> maps = HashMap<Uint64,Uint64>::New();
      maps->put(Uint64::New(1),Uint64::New(10));
      maps->put(Uint64::New(2),Uint64::New(20));
      maps->put(Uint64::New(3),Uint64::New(30));
      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Uint64_Uint64_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(maps);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Uint64_Uint64_test1.json"));
      JsonValue value2 = reader->get();

      HashMap<Uint64,Uint64> maps2 = HashMap<Uint64,Uint64>::New();
      value2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case1]  ");
        break;
      }

      auto v1 = maps2->get(Uint64::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case2]  ");
        break;
      }

      auto v2 = maps2->get(Uint64::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case3]  ");
        break;
      }

      auto v3 = maps2->get(Uint64::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case4]  ");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint64 data = HashmapDataUint64::New();
      HashMap<Uint64,Uint64> maps = HashMap<Uint64,Uint64>::New();
      maps->put(Uint64::New(1),Uint64::New(10));
      maps->put(Uint64::New(2),Uint64::New(20));
      maps->put(Uint64::New(3),Uint64::New(30));
      data->maps = maps;

      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Uint64_Uint64_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Uint64_Uint64_test2.json"));
      JsonValue value2 = reader->get();

      HashmapDataUint64 data2 = HashmapDataUint64::New();
      value2->reflectTo(data2);
      HashMap<Uint64,Uint64> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case5]  ");
        break;
      }

      auto v1 = maps2->get(Uint64::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case6]  ");
        break;
      }

      auto v2 = maps2->get(Uint64::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case7]  ");
        break;
      }

      auto v3 = maps2->get(Uint64::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint64 Uint64 Test case8]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect HashMap Uint64 Uint64 Test case100]");
}
