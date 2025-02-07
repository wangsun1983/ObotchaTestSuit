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
#include "TestLog.hpp"

using namespace obotcha;


DECLARE_CLASS(StringStringMap) {
public:
    HashMap<String,String>maps;
    DECLARE_REFLECT_FIELD(StringStringMap,maps)
};

DECLARE_CLASS(StringStringMap2) {
public:
    HashMap<String,String>maps1;
    HashMap<String,String>maps2;
    DECLARE_REFLECT_FIELD(StringStringMap2,maps1,maps2)
};

void testHashMapStringString() {
    while(1) {
      HashMap<String,String> map = HashMap<String,String>::New();
      map->put("tag1","val1");
      map->put("tag2","val2");
      map->put("tag3","val3");
      map->put("tag4","val4");
      map->put("tag5","val5");

      JsonWriter writer = JsonWriter::New("./tmp/map_string_string_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(map);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/map_string_string_test1.json"));
      JsonValue value2 = reader->get();
/*
      auto iterator = value2->getIterator();
      TEST_FAIL("iterator tag is %s ",iterator->getTag()->toChars());
      TEST_FAIL("iterator value is %s ",iterator->getString()->toChars());

      JsonValue value3 = iterator->getValue();
      TEST_FAIL("value3 is %s ",value3->getString()->toChars());
      TEST_FAIL("value3 is %s ",value3->getName()->toChars());
*/

      HashMap<String,String>map2 = HashMap<String,String>::New();
      value2->reflectTo(map2);

      if(map2->size() != 5) {
        TEST_FAIL("[JsonReflect HashMap String String Test case1]  ");
        break;
      }

      if(!map2->get("tag1")->sameAs("val1")
        ||!map2->get("tag2")->sameAs("val2")
        ||!map2->get("tag3")->sameAs("val3")
        ||!map2->get("tag4")->sameAs("val4")
        ||!map2->get("tag5")->sameAs("val5")) {
          TEST_FAIL("[JsonReflect HashMap String String Test case2]  ");
          break;
      }
      break;
    }

    while(1) {
      StringStringMap map = StringStringMap::New();
      map->maps = HashMap<String,String>::New();
      map->maps->put("tag1","val1");
      map->maps->put("tag2","val2");
      map->maps->put("tag3","val3");
      map->maps->put("tag4","val4");
      map->maps->put("tag5","val5");
      JsonWriter writer = JsonWriter::New("./tmp/map_string_string_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(map);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/map_string_string_test2.json"));
      JsonValue value2 = reader->get();
      StringStringMap checkValue = StringStringMap::New();
      value2->reflectTo(checkValue);

      auto map2 = checkValue->maps;
      if(map2->size() != 5) {
        TEST_FAIL("[JsonReflect HashMap String String Test case3]  ");
        break;
      }

      if(!map2->get("tag1")->sameAs("val1")
        ||!map2->get("tag2")->sameAs("val2")
        ||!map2->get("tag3")->sameAs("val3")
        ||!map2->get("tag4")->sameAs("val4")
        ||!map2->get("tag5")->sameAs("val5")) {
          TEST_FAIL("[JsonReflect HashMap String String Test case4]  ");
          break;
      }
      break;
    }

    while(1) {
      HashMap<String,String> map = HashMap<String,String>::New();
      JsonWriter writer = JsonWriter::New("./tmp/map_string_string_test3.json");
      JsonValue value = JsonValue::New();
      value->importFrom(map);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/map_string_string_test3.json"));
      JsonValue value2 = reader->get();

      //HashMap<String,String>map2 = HashMap<String,String>::New();
      //value2->reflectTo(map2);

      if(value2 != nullptr) {
        TEST_FAIL("[JsonReflect HashMap String String Test case5]  ");
        break;
      }
      break;
    }

    while(1) {
      StringStringMap2 map = StringStringMap2::New();
      map->maps1 = HashMap<String,String>::New();
      map->maps1->put("tag1","val1");
      map->maps1->put("tag2","val2");
      map->maps1->put("tag3","val3");
      map->maps1->put("tag4","val4");
      map->maps1->put("tag5","val5");

      map->maps2 = HashMap<String,String>::New();
      map->maps2->put("2_tag1","2_val1");
      map->maps2->put("2_tag2","2_val2");
      map->maps2->put("2_tag3","2_val3");
      map->maps2->put("2_tag4","2_val4");
      map->maps2->put("2_tag5","2_val5");

      JsonWriter writer = JsonWriter::New("./tmp/map_string_string_test4.json");
      JsonValue value = JsonValue::New();
      value->importFrom(map);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/map_string_string_test4.json"));
      JsonValue value2 = reader->get();
      StringStringMap2 checkValue = StringStringMap2::New();
      value2->reflectTo(checkValue);

      auto map1 = checkValue->maps1;
      if(map1->size() != 5) {
        TEST_FAIL("[JsonReflect HashMap String String Test case6]  ");
        break;
      }

      if(!map1->get("tag1")->sameAs("val1")
        ||!map1->get("tag2")->sameAs("val2")
        ||!map1->get("tag3")->sameAs("val3")
        ||!map1->get("tag4")->sameAs("val4")
        ||!map1->get("tag5")->sameAs("val5")) {
          TEST_FAIL("[JsonReflect HashMap String String Test case7]  ");
          break;
      }

      auto map2 = checkValue->maps2;
      if(map2->size() != 5) {
        TEST_FAIL("[JsonReflect HashMap String String Test case8]  ");
        break;
      }

      if(!map2->get("2_tag1")->sameAs("2_val1")
        ||!map2->get("2_tag2")->sameAs("2_val2")
        ||!map2->get("2_tag3")->sameAs("2_val3")
        ||!map2->get("2_tag4")->sameAs("2_val4")
        ||!map2->get("2_tag5")->sameAs("2_val5")) {
          TEST_FAIL("[JsonReflect HashMap String String Test case9]  ");
          break;
      }
      break;
    }

    TEST_OK("[JsonReflect HashMap String String Test case100]");
}
