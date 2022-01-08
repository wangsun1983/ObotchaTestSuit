#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint16.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint16.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint16) {
public:
  HashMap<Uint16,Uint16> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint16,maps)
};

void testHashMapUint16Uint16() {
    while(1) {
      HashMap<Uint16,Uint16> maps = createHashMap<Uint16,Uint16>();
      maps->put(createUint16(1),createUint16(10));
      maps->put(createUint16(2),createUint16(20));
      maps->put(createUint16(3),createUint16(30));
      JsonWriter writer = createJsonWriter("./tmp/hashmap_Uint16_Uint16_test1.json");
      JsonValue value = createJsonValue();
      value->importFrom(maps);
      writer->write(value);

      JsonReader reader = createJsonReader(createFile("./tmp/hashmap_Uint16_Uint16_test1.json"));
      JsonValue value2 = reader->get();

      HashMap<Uint16,Uint16> maps2 = createHashMap<Uint16,Uint16>();
      value2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case1]  ");
        break;
      }

      auto v1 = maps2->get(createUint16(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case2]  ");
        break;
      }

      auto v2 = maps2->get(createUint16(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case3]  ");
        break;
      }

      auto v3 = maps2->get(createUint16(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case4]  ");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint16 data = createHashmapDataUint16();
      HashMap<Uint16,Uint16> maps = createHashMap<Uint16,Uint16>();
      maps->put(createUint16(1),createUint16(10));
      maps->put(createUint16(2),createUint16(20));
      maps->put(createUint16(3),createUint16(30));
      data->maps = maps;

      JsonWriter writer = createJsonWriter("./tmp/hashmap_Uint16_Uint16_test2.json");
      JsonValue value = createJsonValue();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = createJsonReader(createFile("./tmp/hashmap_Uint16_Uint16_test2.json"));
      JsonValue value2 = reader->get();

      HashmapDataUint16 data2 = createHashmapDataUint16();
      value2->reflectTo(data2);
      HashMap<Uint16,Uint16> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case5]  ");
        break;
      }

      auto v1 = maps2->get(createUint16(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case6]  ");
        break;
      }

      auto v2 = maps2->get(createUint16(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case7]  ");
        break;
      }

      auto v3 = maps2->get(createUint16(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[JsonReflect HashMap Uint16 Uint16 Test case8]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect HashMap Uint16 Uint16 Test case100]");
}
