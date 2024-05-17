#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Byte.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Byte.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataByte) {
public:
  HashMap<Byte,Byte> maps;
  DECLARE_REFLECT_FIELD(HashmapDataByte,maps)
};

void testHashMapByteByte() {
    while(1) {
      HashMap<Byte,Byte> maps = HashMap<Byte,Byte>::New();
      maps->put(Byte::New(1),Byte::New(10));
      maps->put(Byte::New(2),Byte::New(20));
      maps->put(Byte::New(3),Byte::New(30));
      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Byte_Byte_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(maps);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Byte_Byte_test1.json"));
      JsonValue value2 = reader->get();

      HashMap<Byte,Byte> maps2 = HashMap<Byte,Byte>::New();
      value2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case1]  ");
        break;
      }

      auto v1 = maps2->get(Byte::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case2]  ");
        break;
      }

      auto v2 = maps2->get(Byte::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case3]  ");
        break;
      }

      auto v3 = maps2->get(Byte::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case4]  ");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataByte data = HashmapDataByte::New();
      HashMap<Byte,Byte> maps = HashMap<Byte,Byte>::New();
      maps->put(Byte::New(1),Byte::New(10));
      maps->put(Byte::New(2),Byte::New(20));
      maps->put(Byte::New(3),Byte::New(30));
      data->maps = maps;

      JsonWriter writer = JsonWriter::New("./tmp/hashmap_Byte_Byte_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_Byte_Byte_test2.json"));
      JsonValue value2 = reader->get();

      HashmapDataByte data2 = HashmapDataByte::New();
      value2->reflectTo(data2);
      HashMap<Byte,Byte> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case5]  ");
        break;
      }

      auto v1 = maps2->get(Byte::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case6]  ");
        break;
      }

      auto v2 = maps2->get(Byte::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case7]  ");
        break;
      }

      auto v3 = maps2->get(Byte::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Byte Byte Test case8]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect HashMap Byte Byte Test case100]");
}
