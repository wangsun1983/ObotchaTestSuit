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
#include "HashMap.hpp"
#include "OStdInstanceOf.hpp"
#include "JsonValue.hpp"
#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashMapValue) {
public:
  int data1;
  int data2;
  DECLARE_REFLECT_FIELD(HashMapValue,data1,data2)
};

DECLARE_CLASS(Container) {
public:
  HashMap<String,HashMapValue> map;
  DECLARE_REFLECT_FIELD(Container,map)
};

DECLARE_CLASS(ContainerLists) {
public:
  ArrayList<HashMap<String,HashMapValue>> lists;
  DECLARE_REFLECT_FIELD(ContainerLists,lists)
};

void testReflectHashMapFieldWrite() {
    //json update
    while(1) {
        Container c = createContainer();
        c->map = createHashMap<String,HashMapValue>();

        HashMapValue v1 = createHashMapValue();
        v1->data1 = 123;
        v1->data2 = 456;

        HashMapValue v2 = createHashMapValue();
        v2->data1 = 789;
        v2->data2 = 999;

        c->map->put(createString("tag1"),v1);
        c->map->put(createString("tag2"),v2);

        JsonValue jvalue = createJsonValue();
        jvalue->importFrom(c);

        JsonWriter jwriter = createJsonWriter("output_hashmap_1.json");
        jwriter->write(jvalue);

        JsonReader reader = createJsonReader()->loadFile(createFile("output_hashmap_1.json"));
        JsonValue readValue = reader->get();

        Container rdata3 = createContainer();
        readValue->reflectTo(rdata3);

        HashMapValue val1 = rdata3->map->get("tag1");
        if(val1 == nullptr) {
          TEST_FAIL("Reflect HashMap Write test1");
          break;
        }

        if(val1->data1 != 123 || val1->data2 != 456) {
          TEST_FAIL("Reflect HashMap Write test2");
          break;
        }

        HashMapValue val2 = rdata3->map->get("tag2");
        if(val2 == nullptr) {
          TEST_FAIL("Reflect HashMap Write test3");
          break;
        }

        if(val2->data1 != 789 || val2->data2 != 999) {
          TEST_FAIL("Reflect HashMap Write test4");
          break;
        }

        TEST_OK("Reflect HashMap Write test5");
        break;
    }

    //case2
    while(1) {
      ContainerLists ll = createContainerLists();
      ll->lists = createArrayList<HashMap<String,HashMapValue>>();
      HashMap<String,HashMapValue> map1 = createHashMap<String,HashMapValue>();
      HashMapValue vv1 = createHashMapValue();
      vv1->data1 = 1;
      vv1->data2 = 2;

      HashMapValue vv2 = createHashMapValue();
      vv2->data1 = 3;
      vv2->data2 = 4;

      map1->put(createString("T1"),vv1);
      map1->put(createString("T2"),vv2);
      ll->lists->add(map1);

      HashMap<String,HashMapValue> map2 = createHashMap<String,HashMapValue>();
      HashMapValue uu1 = createHashMapValue();
      uu1->data1 = 11;
      uu1->data2 = 12;

      HashMapValue uu2 = createHashMapValue();
      uu2->data1 = 13;
      uu2->data2 = 14;

      map2->put(createString("T1"),uu1);
      map2->put(createString("T2"),uu2);

      ll->lists->add(map2);
      JsonValue jvalue = createJsonValue();
      jvalue->importFrom(ll);

      JsonWriter jwriter = createJsonWriter("output_hashmap_2.json");
      jwriter->write(jvalue);

      JsonReader reader = createJsonReader()->loadFile(createFile("output_hashmap_2.json"));
      JsonValue readValue = reader->get();
      ContainerLists ll2 = createContainerLists();
      readValue->reflectTo(ll2);

      if(ll2 == nullptr) {
        TEST_FAIL("Reflect HashMap Write test6");
        break;
      }

      if(ll2->lists == nullptr) {
        TEST_FAIL("Reflect HashMap Write test7");
        break;
      }

      if(ll2->lists->size() != 2) {
        TEST_FAIL("Reflect HashMap Write test8");
        break;
      }

      HashMap<String,HashMapValue> chkmap1 = ll2->lists->get(0);
      HashMapValue qq1 = chkmap1->get(createString("T1"));
      if(qq1 == nullptr || qq1->data1 != 1 ||qq1->data2 != 2) {
        TEST_FAIL("Reflect HashMap Write test9");
        break;
      }

      HashMapValue qq2 = chkmap1->get(createString("T2"));
      if(qq2 == nullptr || qq2->data1 != 3 ||qq2->data2 != 4) {
        TEST_FAIL("Reflect HashMap Write test10");
        break;
      }

      HashMap<String,HashMapValue> chkmap2 = ll2->lists->get(1);
      HashMapValue tt1 = chkmap2->get(createString("T1"));
      if(tt1 == nullptr || tt1->data1 != 11 ||tt1->data2 != 12) {
        TEST_FAIL("Reflect HashMap Write test11");
        break;
      }

      HashMapValue tt2 = chkmap2->get(createString("T2"));
      if(tt2 == nullptr || tt2->data1 != 13 ||tt2->data2 != 14) {
        TEST_FAIL("Reflect HashMap Write test12");
        break;
      }

      TEST_OK("Reflect HashMap Write test13");
      break;
    }

}
