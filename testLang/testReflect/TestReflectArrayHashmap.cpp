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
#include "JsonReader.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ItemData) {
public:
  int data1;
  int data2;
  DECLARE_REFLECT_FIELD(ItemData,data1,data2)
};

DECLARE_CLASS(ArrayHashMap) {
public:
  ArrayList<HashMap<String,ItemData>> datas;
  DECLARE_REFLECT_FIELD(ArrayHashMap,datas)
};


void testReflectArrayHashmap() {
  while(1) {
    ArrayHashMap map = ArrayHashMap::New();
    map->datas = ArrayList<HashMap<String,ItemData>>::New();

    HashMap<String,ItemData> map1 = HashMap<String,ItemData>::New();
    ItemData d1 = ItemData::New();
    d1->data1 = 1;
    d1->data2 = 2;

    ItemData d2 = ItemData::New();
    d2->data1 = 3;
    d2->data2 = 4;

    map1->put(String::New("value1"),d1);
    map1->put(String::New("value2"),d2);
    map->datas->add(map1);


    HashMap<String,ItemData> map2 = HashMap<String,ItemData>::New();
    ItemData d3 = ItemData::New();
    d3->data1 = 5;
    d3->data2 = 6;

    ItemData d4 = ItemData::New();
    d4->data1 = 7;
    d4->data2 = 8;

    map2->put(String::New("data1"),d3);
    map2->put(String::New("data2"),d4);
    map->datas->add(map2);

    JsonValue jvalue = JsonValue::New();
    jvalue->importFrom(map);

    JsonWriter jwriter = JsonWriter::New("output_array_hashmap_case1_1.json");
    jwriter->write(jvalue);


    JsonReader reader = JsonReader::New()->loadFile(File::New("output_array_hashmap_case1_1.json"));
    JsonValue readValue = reader->get();
    ArrayHashMap result = ArrayHashMap::New();
    readValue->reflectTo(result);

    if(result->datas == nullptr || result->datas->size() != 2) {
      TEST_FAIL("Reflect Array HashMap test1");
      break;
    }

    HashMap<String,ItemData> m1 = result->datas->get(0);
    ItemData item1 = m1->get(String::New("value1"));
    if(item1 == nullptr || item1->data1 != 1 || item1->data2 != 2) {
      TEST_FAIL("Reflect Array HashMap test2");
      break;
    }

    ItemData item2 = m1->get(String::New("value2"));
    if(item2 == nullptr || item2->data1 != 3 || item2->data2 != 4) {
      TEST_FAIL("Reflect Array HashMap test3");
      break;
    }

    HashMap<String,ItemData> m2 = result->datas->get(1);
    ItemData item3 = m2->get(String::New("data1"));
    if(item3 == nullptr || item3->data1 != 5 || item3->data2 != 6) {
      TEST_FAIL("Reflect Array HashMap test4");
      break;
    }

    ItemData item4 = m2->get(String::New("data2"));
    if(item4 == nullptr || item4->data1 != 7 || item4->data2 != 8) {
      TEST_FAIL("Reflect Array HashMap test5");
      break;
    }

    TEST_OK("Reflect Array HashMap test6");
    break;
  }
}
