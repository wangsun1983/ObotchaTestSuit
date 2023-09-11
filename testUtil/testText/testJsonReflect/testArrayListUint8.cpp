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
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(Uint8List) {
public:
    ArrayList<Uint8>lists;
    DECLARE_REFLECT_FIELD(Uint8List,lists)
};

DECLARE_CLASS(Uint8List2) {
public:
    ArrayList<Uint8>list1;
    ArrayList<Uint8>list2;
    DECLARE_REFLECT_FIELD(Uint8List2,list1,list2)
};

void testArrayListUint8() {
    while(1) {
      ArrayList<Uint8> list = createArrayList<Uint8>();
      list->add(createUint8(1));
      list->add(createUint8(2));
      list->add(createUint8(3));
      list->add(createUint8(4));
      list->add(createUint8(5));

      JsonWriter writer = createJsonWriter("./tmp/list_Uint8_test1.json");
      JsonValue value = createJsonValue();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = createJsonReader()->loadFile(createFile("./tmp/list_Uint8_test1.json"));
      JsonValue value2 = reader->get();

      ArrayList<Uint8> list2 = createArrayList<Uint8>();
      value2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[JsonReflect ArrayList Uint8 Test case1]  ");
        break;
      }

      if(list2->get(0)->toValue() != 1
        ||list2->get(1)->toValue() != 2
        ||list2->get(2)->toValue() != 3
        ||list2->get(3)->toValue() != 4
        ||list2->get(4)->toValue() != 5) {
          TEST_FAIL("[JsonReflect ArrayList Uint8 Test case2]  ");
          break;
      }
      break;
    }

    while(1) {
      Uint8List2 list = createUint8List2();
      list->list1 = createArrayList<Uint8>();
      list->list2 = createArrayList<Uint8>();

      list->list1->add(createUint8(1));
      list->list1->add(createUint8(2));
      list->list1->add(createUint8(3));
      list->list1->add(createUint8(4));
      list->list1->add(createUint8(5));

      list->list2->add(createUint8(6));
      list->list2->add(createUint8(7));
      list->list2->add(createUint8(8));
      list->list2->add(createUint8(9));
      list->list2->add(createUint8(10));

      JsonWriter writer = createJsonWriter("./tmp/list_Uint8_test2.json");
      JsonValue value = createJsonValue();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = createJsonReader()->loadFile(createFile("./tmp/list_Uint8_test2.json"));
      JsonValue value2 = reader->get();

      Uint8List2 list2 = createUint8List2();
      value2->reflectTo(list2);

      if(list2->list1->get(0)->toValue() != 1
        ||list2->list1->get(1)->toValue() != 2
        ||list2->list1->get(2)->toValue() != 3
        ||list2->list1->get(3)->toValue() != 4
        ||list2->list1->get(4)->toValue() != 5) {
          TEST_FAIL("[JsonReflect ArrayList Uint8 Test case3]  ");
          break;
      }

      if(list2->list2->get(0)->toValue() != 6
        ||list2->list2->get(1)->toValue() != 7
        ||list2->list2->get(2)->toValue() != 8
        ||list2->list2->get(3)->toValue() != 9
        ||list2->list2->get(4)->toValue() != 10) {
          TEST_FAIL("[JsonReflect ArrayList Uint8 Test case4]  ");
          break;
      }
      break;
    }

    TEST_OK("[JsonReflect ArrayList Uint8 Test case100]");
}
