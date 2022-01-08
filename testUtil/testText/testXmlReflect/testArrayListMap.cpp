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
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ListMapItem) {
public:
    int data1;
    long data2;
    DECLARE_REFLECT_FIELD(ListMapItem,data1,data2)
};

DECLARE_CLASS(ListMapData) {
public:
  ArrayList<HashMap<Integer,ListMapItem>> list;
  DECLARE_REFLECT_FIELD(ListMapData,list)
};

void testArrayListMap() {
    while(1) {
      ArrayList<HashMap<Integer,ListMapItem>> list = createArrayList<HashMap<Integer,ListMapItem>>();
      HashMap<Integer,ListMapItem> item1 = createHashMap<Integer,ListMapItem>();
      ListMapItem d1 = createListMapItem();
      d1->data1 = 1;
      d1->data2 = 2;

      ListMapItem d2 = createListMapItem();
      d2->data1 = 3;
      d2->data2 = 4;

      ListMapItem d3 = createListMapItem();
      d3->data1 = 5;
      d3->data2 = 6;

      item1->put(createInteger(0),d1);
      item1->put(createInteger(1),d2);
      item1->put(createInteger(2),d3);
      list->add(item1);

      HashMap<Integer,ListMapItem> item2 = createHashMap<Integer,ListMapItem>();
      ListMapItem d2_1 = createListMapItem();
      d2_1->data1 = 11;
      d2_1->data2 = 21;

      ListMapItem d2_2 = createListMapItem();
      d2_2->data1 = 31;
      d2_2->data2 = 41;

      ListMapItem d2_3 = createListMapItem();
      d2_3->data1 = 51;
      d2_3->data2 = 61;

      item2->put(createInteger(0),d2_1);
      item2->put(createInteger(1),d2_2);
      item2->put(createInteger(2),d2_3);
      list->add(item2);

      XmlDocument doc = createXmlDocument();
      doc->importFrom(list);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/list_map_test1.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/list_map_test1.xml"));
      XmlDocument doc2 = reader->get();

      ArrayList<HashMap<Integer,ListMapItem>> list2 = createArrayList<HashMap<Integer,ListMapItem>>();
      doc2->reflectTo(list2);

      if(list2->size() != 2) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case1]");
        break;
      }

      auto ll1 = list2->get(0);
      if(ll1->size() != 3) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case2]");
        break;
      }

      if(ll1->get(createInteger(0))->data1 != 1 ||ll1->get(createInteger(0))->data2 != 2) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case3]");
        break;
      }

      if(ll1->get(createInteger(1))->data1 != 3 ||ll1->get(createInteger(1))->data2 != 4) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case3]");
        break;
      }

      if(ll1->get(createInteger(2))->data1 != 5 ||ll1->get(createInteger(2))->data2 != 6) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case4]");
        break;
      }

      auto ll2 = list2->get(1);
      if(ll2->size() != 3) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case5]");
        break;
      }

      if(ll2->get(createInteger(0))->data1 != 11 ||ll2->get(createInteger(0))->data2 != 21) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case6]");
        break;
      }

      if(ll2->get(createInteger(1))->data1 != 31 ||ll2->get(createInteger(1))->data2 != 41) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case7]");
        break;
      }

      if(ll2->get(createInteger(2))->data1 != 51 ||ll2->get(createInteger(2))->data2 != 61) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case8]");
        break;
      }

      break;
    }

    while(1) {
      ListMapData data = createListMapData();
      ArrayList<HashMap<Integer,ListMapItem>> list = createArrayList<HashMap<Integer,ListMapItem>>();
      HashMap<Integer,ListMapItem> item1 = createHashMap<Integer,ListMapItem>();
      ListMapItem d1 = createListMapItem();
      d1->data1 = 1;
      d1->data2 = 2;

      ListMapItem d2 = createListMapItem();
      d2->data1 = 3;
      d2->data2 = 4;

      ListMapItem d3 = createListMapItem();
      d3->data1 = 5;
      d3->data2 = 6;

      item1->put(createInteger(0),d1);
      item1->put(createInteger(1),d2);
      item1->put(createInteger(2),d3);
      list->add(item1);

      HashMap<Integer,ListMapItem> item2 = createHashMap<Integer,ListMapItem>();
      ListMapItem d2_1 = createListMapItem();
      d2_1->data1 = 11;
      d2_1->data2 = 21;

      ListMapItem d2_2 = createListMapItem();
      d2_2->data1 = 31;
      d2_2->data2 = 41;

      ListMapItem d2_3 = createListMapItem();
      d2_3->data1 = 51;
      d2_3->data2 = 61;

      item2->put(createInteger(0),d2_1);
      item2->put(createInteger(1),d2_2);
      item2->put(createInteger(2),d2_3);
      list->add(item2);
      data->list = list;

      XmlDocument doc = createXmlDocument();
      doc->importFrom(data);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/list_map_test2.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/list_map_test2.xml"));
      XmlDocument doc2 = reader->get();

      ListMapData data2 = createListMapData();
      doc2->reflectTo(data2);
      ArrayList<HashMap<Integer,ListMapItem>> list2 = data->list;

      if(list2->size() != 2) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case9]");
        break;
      }

      auto ll1 = list2->get(0);
      if(ll1->size() != 3) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case10]");
        break;
      }

      if(ll1->get(createInteger(0))->data1 != 1 ||ll1->get(createInteger(0))->data2 != 2) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case11]");
        break;
      }

      if(ll1->get(createInteger(1))->data1 != 3 ||ll1->get(createInteger(1))->data2 != 4) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case12]");
        break;
      }

      if(ll1->get(createInteger(2))->data1 != 5 ||ll1->get(createInteger(2))->data2 != 6) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case13]");
        break;
      }

      auto ll2 = list2->get(1);
      if(ll2->size() != 3) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case14]");
        break;
      }

      if(ll2->get(createInteger(0))->data1 != 11 ||ll2->get(createInteger(0))->data2 != 21) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case15]");
        break;
      }

      if(ll2->get(createInteger(1))->data1 != 31 ||ll2->get(createInteger(1))->data2 != 41) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case16]");
        break;
      }

      if(ll2->get(createInteger(2))->data1 != 51 ||ll2->get(createInteger(2))->data2 != 61) {
        TEST_FAIL("[XmlReflect ArrayList Map Test case17]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect ArrayList Map Test case100]");
}
