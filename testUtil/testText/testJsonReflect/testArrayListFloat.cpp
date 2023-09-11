#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Float.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(FloatList) {
public:
    ArrayList<Float>lists;
    DECLARE_REFLECT_FIELD(FloatList,lists)
};

DECLARE_CLASS(FloatList2) {
public:
    ArrayList<Float>list1;
    ArrayList<Float>list2;
    DECLARE_REFLECT_FIELD(FloatList2,list1,list2)
};

void testArrayListFloat() {
    while(1) {
      ArrayList<Float> list = createArrayList<Float>();
      list->add(createFloat(1.1));
      list->add(createFloat(2.2));
      list->add(createFloat(3.3));
      list->add(createFloat(4.4));
      list->add(createFloat(5.5));

      JsonWriter writer = createJsonWriter("./tmp/list_Float_test1.json");
      JsonValue value = createJsonValue();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = createJsonReader()->loadFile(createFile("./tmp/list_Float_test1.json"));
      JsonValue value2 = reader->get();

      ArrayList<Float> list2 = createArrayList<Float>();
      value2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[JsonReflect ArrayList Float Test case1]");
        break;
      }

      if(st(Float)::Compare(list2->get(0)->toValue(),1.1) != 0
        ||st(Float)::Compare(list2->get(1)->toValue(),2.2) != 0
        ||st(Float)::Compare(list2->get(2)->toValue(),3.3) != 0
        ||st(Float)::Compare(list2->get(3)->toValue(),4.4) != 0
        ||st(Float)::Compare(list2->get(4)->toValue(),5.5) != 0) {
          TEST_FAIL("[JsonReflect ArrayList Float Test case2]");
          break;
      }
      break;
    }

    while(1) {
      FloatList2 list = createFloatList2();
      list->list1 = createArrayList<Float>();
      list->list2 = createArrayList<Float>();

      list->list1->add(createFloat(1.1));
      list->list1->add(createFloat(2.2));
      list->list1->add(createFloat(3.3));
      list->list1->add(createFloat(4.4));
      list->list1->add(createFloat(5.5));

      list->list2->add(createFloat(6.6));
      list->list2->add(createFloat(7.7));
      list->list2->add(createFloat(8.8));
      list->list2->add(createFloat(9.9));
      list->list2->add(createFloat(10.1));

      JsonWriter writer = createJsonWriter("./tmp/list_Float_test2.json");
      JsonValue value = createJsonValue();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = createJsonReader()->loadFile(createFile("./tmp/list_Float_test2.json"));
      JsonValue value2 = reader->get();

      FloatList2 list2 = createFloatList2();
      value2->reflectTo(list2);

      if(st(Float)::Compare(list2->list1->get(0)->toValue(),1.1) != 0
        ||st(Float)::Compare(list2->list1->get(1)->toValue(),2.2) != 0
        ||st(Float)::Compare(list2->list1->get(2)->toValue(),3.3) != 0
        ||st(Float)::Compare(list2->list1->get(3)->toValue(),4.4) != 0
        ||st(Float)::Compare(list2->list1->get(4)->toValue(),5.5) != 0) {
          TEST_FAIL("[JsonReflect ArrayList Float Test case3]");
          break;
      }

      if(st(Float)::Compare(list2->list2->get(0)->toValue(),6.6) != 0
        ||st(Float)::Compare(list2->list2->get(1)->toValue(),7.7) != 0
        ||st(Float)::Compare(list2->list2->get(2)->toValue(),8.8) != 0
        ||st(Float)::Compare(list2->list2->get(3)->toValue(),9.9) != 0
        ||st(Float)::Compare(list2->list2->get(4)->toValue(),10.1) != 0) {
          TEST_FAIL("[JsonReflect ArrayList Float Test case4]");
          break;
      }
      break;
    }

    TEST_OK("[JsonReflect ArrayList Float Test case100]");
}
