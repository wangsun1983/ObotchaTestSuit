#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint64.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ArrayItemUserdata) {
public:
    int data1;
    long data2;
    DECLARE_REFLECT_FIELD(ArrayItemUserdata,data1,data2)
};

DECLARE_CLASS(Userdatas) {
public:
    ArrayList<ArrayItemUserdata> item;
    DECLARE_REFLECT_FIELD(Userdatas,item)
};

void testArrayUserData() {
    while(1) {
      ArrayList<ArrayItemUserdata> list = ArrayList<ArrayItemUserdata>::New();
      ArrayItemUserdata d1 = ArrayItemUserdata::New();
      d1->data1 = 1;
      d1->data2 = 1;

      ArrayItemUserdata d2 = ArrayItemUserdata::New();
      d2->data1 = 2;
      d2->data2 = 2;

      ArrayItemUserdata d3 = ArrayItemUserdata::New();
      d3->data1 = 3;
      d3->data2 = 3;

      list->add(d1);
      list->add(d2);
      list->add(d3);

      JsonWriter writer = JsonWriter::New("./tmp/list_userdata_test1.json");
      JsonValue value = JsonValue::New();
      value->importFrom(list);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/list_userdata_test1.json"));
      JsonValue value2 = reader->get();

      ArrayList<ArrayItemUserdata> list2 = ArrayList<ArrayItemUserdata>::New();
      value2->reflectTo(list2);

      if(list2->size() != 3) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case1]  ");
        break;
      }

      if(list2->get(0)->data1 != 1 || list2->get(0)->data2 != 1) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case2]  ");
        break;
      }

      if(list2->get(1)->data1 != 2 || list2->get(1)->data2 != 2) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case3]  ");
        break;
      }

      if(list2->get(2)->data1 != 3 || list2->get(2)->data2 != 3) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case4]  ");
        break;
      }

      break;
    }

    while(1) {
      Userdatas data = Userdatas::New();
      ArrayList<ArrayItemUserdata> list = ArrayList<ArrayItemUserdata>::New();
      ArrayItemUserdata d1 = ArrayItemUserdata::New();
      d1->data1 = 1;
      d1->data2 = 1;

      ArrayItemUserdata d2 = ArrayItemUserdata::New();
      d2->data1 = 2;
      d2->data2 = 2;

      ArrayItemUserdata d3 = ArrayItemUserdata::New();
      d3->data1 = 3;
      d3->data2 = 3;

      list->add(d1);
      list->add(d2);
      list->add(d3);
      data->item = list;

      JsonWriter writer = JsonWriter::New("./tmp/list_userdata_test2.json");
      JsonValue value = JsonValue::New();
      value->importFrom(data);
      writer->write(value);

      JsonReader reader = JsonReader::New()->loadFile(File::New("./tmp/list_userdata_test2.json"));
      JsonValue value2 = reader->get();

      Userdatas data2 = Userdatas::New();
      value2->reflectTo(data2);

      ArrayList<ArrayItemUserdata> list2 = data2->item;

      if(list2->size() != 3) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case5]  ");
        break;
      }

      if(list2->get(0)->data1 != 1 || list2->get(0)->data2 != 1) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case6]  ");
        break;
      }

      if(list2->get(1)->data1 != 2 || list2->get(1)->data2 != 2) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case7]  ");
        break;
      }

      if(list2->get(2)->data1 != 3 || list2->get(2)->data2 != 3) {
        TEST_FAIL("[JsonReflect ArrayList Userdata Test case8]  ");
        break;
      }

      break;
    }

    TEST_OK("[JsonReflect ArrayList Userdata Test case100]");
}
