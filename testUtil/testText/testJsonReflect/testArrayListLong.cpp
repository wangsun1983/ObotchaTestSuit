#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Long.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(LongList) {
public:
    ArrayList<Long>lists;
    DECLARE_REFLECT_FIELD(LongList,lists)
};

DECLARE_CLASS(LongList2) {
public:
    ArrayList<Long>list1;
    ArrayList<Long>list2;
    DECLARE_REFLECT_FIELD(LongList2,list1,list2)
};

void testArrayListLong() {
    while(1) {
      ArrayList<Long> list = ArrayList<Long>::New();
      list->add(Long::New(1));
      list->add(Long::New(2));
      list->add(Long::New(3));
      list->add(Long::New(4));
      list->add(Long::New(5));

      JsonWriter writer = JsonWriter::New("./tmp/list_Long_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/list_Long_test1.json"));
      JsonValue value2 = reader->get();

      ArrayList<Long> list2 = ArrayList<Long>::New();
      value2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[JsonReflect ArrayList Long Test case1]  ");
        break;
      }

      if(list2->get(0)->toValue() != 1
        ||list2->get(1)->toValue() != 2
        ||list2->get(2)->toValue() != 3
        ||list2->get(3)->toValue() != 4
        ||list2->get(4)->toValue() != 5) {
          TEST_FAIL("[JsonReflect ArrayList Long Test case2]  ");
          break;
      }
      break;
    }

    while(1) {
      LongList2 list = LongList2::New();
      list->list1 = ArrayList<Long>::New();
      list->list2 = ArrayList<Long>::New();

      list->list1->add(Long::New(1));
      list->list1->add(Long::New(2));
      list->list1->add(Long::New(3));
      list->list1->add(Long::New(4));
      list->list1->add(Long::New(5));

      list->list2->add(Long::New(6));
      list->list2->add(Long::New(7));
      list->list2->add(Long::New(8));
      list->list2->add(Long::New(9));
      list->list2->add(Long::New(10));

      JsonWriter writer = JsonWriter::New("./tmp/list_Long_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/list_Long_test2.json"));
      JsonValue value2 = reader->get();

      LongList2 list2 = LongList2::New();
      value2->reflectTo(list2);

      if(list2->list1->get(0)->toValue() != 1
        ||list2->list1->get(1)->toValue() != 2
        ||list2->list1->get(2)->toValue() != 3
        ||list2->list1->get(3)->toValue() != 4
        ||list2->list1->get(4)->toValue() != 5) {
          TEST_FAIL("[JsonReflect ArrayList Long Test case3]  ");
          break;
      }

      if(list2->list2->get(0)->toValue() != 6
        ||list2->list2->get(1)->toValue() != 7
        ||list2->list2->get(2)->toValue() != 8
        ||list2->list2->get(3)->toValue() != 9
        ||list2->list2->get(4)->toValue() != 10) {
          TEST_FAIL("[JsonReflect ArrayList Long Test case4]  ");
          break;
      }
      break;
    }

    TEST_OK("[JsonReflect ArrayList Long Test case100]");
}
