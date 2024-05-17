#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint32.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint32.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint32) {
public:
  HashMap<Uint32,Uint32> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint32,maps)
};

void testHashMapUint32Uint32() {
    while(1) {
      HashMap<Uint32,Uint32> maps = HashMap<Uint32,Uint32>::New();
      maps->put(Uint32::New(1),Uint32::New(10));
      maps->put(Uint32::New(2),Uint32::New(20));
      maps->put(Uint32::New(3),Uint32::New(30));
      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Uint32_Uint32_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(maps);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Uint32_Uint32_test1.json"));
      JsonValue value2 = reader->get();

      HashMap<Uint32,Uint32> maps2 = HashMap<Uint32,Uint32>::New();
      value2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case1]  ");
        break;
      }

      auto v1 = maps2->get(Uint32::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case2]  ");
        break;
      }

      auto v2 = maps2->get(Uint32::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case3]  ");
        break;
      }

      auto v3 = maps2->get(Uint32::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case4]  ");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint32 data = HashmapDataUint32::New();
      HashMap<Uint32,Uint32> maps = HashMap<Uint32,Uint32>::New();
      maps->put(Uint32::New(1),Uint32::New(10));
      maps->put(Uint32::New(2),Uint32::New(20));
      maps->put(Uint32::New(3),Uint32::New(30));
      data->maps = maps;

      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Uint32_Uint32_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Uint32_Uint32_test2.json"));
      JsonValue value2 = reader->get();

      HashmapDataUint32 data2 = HashmapDataUint32::New();
      value2->reflectTo(data2);
      HashMap<Uint32,Uint32> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case5]  ");
        break;
      }

      auto v1 = maps2->get(Uint32::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case6]  ");
        break;
      }

      auto v2 = maps2->get(Uint32::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case7]  ");
        break;
      }

      auto v3 = maps2->get(Uint32::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint32 Uint32 Test case8]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect HashMap Uint32 Uint32 Test case100]");
}
