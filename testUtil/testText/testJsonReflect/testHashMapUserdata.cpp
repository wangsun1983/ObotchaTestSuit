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

DECLARE_CLASS(MapUserData) {
public:
  int data1;
  long data2;
  DECLARE_REFLECT_FIELD(MapUserData,data1,data2)
};

void testHashMapUserdata() {
    while(1) {
      HashMap<Integer,MapUserData> maps = HashMap<Integer,MapUserData>::New();
      MapUserData d1 = MapUserData::New();
      d1->data1 = 1;
      d1->data2 = 2;

      MapUserData d2 = MapUserData::New();
      d2->data1 = 3;
      d2->data2 = 4;

      MapUserData d3 = MapUserData::New();
      d3->data1 = 5;
      d3->data2 = 6;

      maps->put(Integer::New(1),d1);
      maps->put(Integer::New(2),d2);
      maps->put(Integer::New(3),d3);

      JsonWriter writer = JsonWriter::New("./tmp/hashmap_userdata_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(maps);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/hashmap_userdata_test1.json"));
      JsonValue value2 = reader->get();

      HashMap<Integer,MapUserData> maps2 = HashMap<Integer,MapUserData>::New();
      value2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[JsonReflect HashMap UserData Test case1]  ");
        break;
      }

      auto v1 = maps2->get(Integer::New(1));
      if(v1 == nullptr || v1->data1 != 1 || v1->data2 != 2) {
        TEST_FAIL("[JsonReflect HashMap UserData Test case2]  ");
        break;
      }

      auto v2 = maps2->get(Integer::New(2));
      if(v2 == nullptr || v2->data1 != 3 || v2->data2 != 4) {
        TEST_FAIL("[JsonReflect HashMap UserData Test case3]  ");
        break;
      }

      auto v3 = maps2->get(Integer::New(3));
      if(v3 == nullptr || v3->data1 != 5 || v3->data2 != 6) {
        TEST_FAIL("[JsonReflect HashMap UserData Test case4]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect HashMap UserData Test case100]");
}
