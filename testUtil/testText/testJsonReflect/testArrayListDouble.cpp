#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Double.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(DoubleList) {
public:
    ArrayList<Double>lists;
    DECLARE_REFLECT_FIELD(DoubleList,lists)
};

DECLARE_CLASS(DoubleList2) {
public:
    ArrayList<Double>list1;
    ArrayList<Double>list2;
    DECLARE_REFLECT_FIELD(DoubleList2,list1,list2)
};

void testArrayListDouble() {
    while(1) {
      ArrayList<Double> list = createArrayList<Double>();
      list->add(createDouble(1.1));
      list->add(createDouble(2.2));
      list->add(createDouble(3.3));
      list->add(createDouble(4.4));
      list->add(createDouble(5.5));

      JsonWriter writer = createJsonWriter("./tmp/list_Double_test1.json");
      JsonValue value = createJsonValue();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = createJsonReader()->loadFile(createFile("./tmp/list_Double_test1.json"));
      JsonValue value2 = reader->get();

      ArrayList<Double> list2 = createArrayList<Double>();
      value2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[JsonReflect ArrayList Double Test case1]");
        break;
      }

      if(st(Double)::Compare(list2->get(0)->toValue(),1.1) != 0
        ||st(Double)::Compare(list2->get(1)->toValue(),2.2) != 0
        ||st(Double)::Compare(list2->get(2)->toValue(),3.3) != 0
        ||st(Double)::Compare(list2->get(3)->toValue(),4.4) != 0
        ||st(Double)::Compare(list2->get(4)->toValue(),5.5) != 0) {
          TEST_FAIL("[JsonReflect ArrayList Double Test case2]");
          break;
      }
      break;
    }

    while(1) {
      DoubleList2 list = createDoubleList2();
      list->list1 = createArrayList<Double>();
      list->list2 = createArrayList<Double>();

      list->list1->add(createDouble(1.1));
      list->list1->add(createDouble(2.2));
      list->list1->add(createDouble(3.3));
      list->list1->add(createDouble(4.4));
      list->list1->add(createDouble(5.5));

      list->list2->add(createDouble(6.6));
      list->list2->add(createDouble(7.7));
      list->list2->add(createDouble(8.8));
      list->list2->add(createDouble(9.9));
      list->list2->add(createDouble(10.1));

      JsonWriter writer = createJsonWriter("./tmp/list_Double_test2.json");
      JsonValue value = createJsonValue();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = createJsonReader()->loadFile(createFile("./tmp/list_Double_test2.json"));
      JsonValue value2 = reader->get();

      DoubleList2 list2 = createDoubleList2();
      value2->reflectTo(list2);

      if(st(Double)::Compare(list2->list1->get(0)->toValue(),1.1) != 0
        ||st(Double)::Compare(list2->list1->get(1)->toValue(),2.2) != 0
        ||st(Double)::Compare(list2->list1->get(2)->toValue(),3.3) != 0
        ||st(Double)::Compare(list2->list1->get(3)->toValue(),4.4) != 0
        ||st(Double)::Compare(list2->list1->get(4)->toValue(),5.5) != 0) {
          TEST_FAIL("[JsonReflect ArrayList Double Test case3]");
          break;
      }

      if(st(Double)::Compare(list2->list2->get(0)->toValue(),6.6) != 0
        ||st(Double)::Compare(list2->list2->get(1)->toValue(),7.7) != 0
        ||st(Double)::Compare(list2->list2->get(2)->toValue(),8.8) != 0
        ||st(Double)::Compare(list2->list2->get(3)->toValue(),9.9) != 0
        ||st(Double)::Compare(list2->list2->get(4)->toValue(),10.1) != 0) {
          TEST_FAIL("[JsonReflect ArrayList Double Test case4]");
          break;
      }
      break;
    }

    TEST_OK("[JsonReflect ArrayList Double Test case100]");
}
