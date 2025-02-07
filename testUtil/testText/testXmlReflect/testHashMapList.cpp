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
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;


DECLARE_CLASS(ListItem1) {
public:
    int data1;
    long data2;
    DECLARE_REFLECT_FIELD(ListItem1,data1,data2)
};

void testHashMapList() {
    while(1) {
      HashMap<Integer,ArrayList<ListItem1>> map = HashMap<Integer,ArrayList<ListItem1>>::New();

      ArrayList<ListItem1> list1 = ArrayList<ListItem1>::New();
      ListItem1 item1 = ListItem1::New();
      item1->data1 = 1;
      item1->data2 = 2;

      ListItem1 item2 = ListItem1::New();
      item2->data1 = 3;
      item2->data2 = 4;

      ListItem1 item3 = ListItem1::New();
      item3->data1 = 5;
      item3->data2 = 6;

      list1->add(item1);
      list1->add(item2);
      list1->add(item3);

      ArrayList<ListItem1> list2 = ArrayList<ListItem1>::New();
      ListItem1 item2_1 = ListItem1::New();
      item2_1->data1 = 11;
      item2_1->data2 = 21;

      ListItem1 item2_2 = ListItem1::New();
      item2_2->data1 = 31;
      item2_2->data2 = 41;

      ListItem1 item2_3 = ListItem1::New();
      item2_3->data1 = 51;
      item2_3->data2 = 61;

      list2->add(item2_1);
      list2->add(item2_2);
      list2->add(item2_3);

      map->put(Integer::New(0),list1);
      map->put(Integer::New(1),list2);

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(map);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/hashmap_list_test1.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/hashmap_list_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Integer,ArrayList<ListItem1>> map2 = HashMap<Integer,ArrayList<ListItem1>>::New();
      doc2->reflectTo(map2);

      if(map2->size() != 2) {
        TEST_FAIL("[XmlReflect HashMap List Test case1]");
        break;
      }

      auto l1 = map2->get(Integer::New(0));
      if(l1->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap List Test case2] [FAILED],size is %d \n",l1->size());
        TEST_FAIL("data1 is %d,data2 is %d",l1->get(0)->data1,l1->get(1)->data1);
        break;
      }

      if(l1->get(0)->data1 != 1 ||l1->get(0)->data2 != 2) {
        TEST_FAIL("[XmlReflect HashMap List Test case3]");
        break;
      }

      if(l1->get(1)->data1 != 3 ||l1->get(1)->data2 != 4) {
        TEST_FAIL("[XmlReflect HashMap List Test case4]");
        break;
      }

      if(l1->get(2)->data1 != 5 ||l1->get(2)->data2 != 6) {
        TEST_FAIL("[XmlReflect HashMap List Test case5]");
        break;
      }

      auto l2 = map2->get(Integer::New(1));
      if(l2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap List Test case6]");
        break;
      }

      if(l2->get(0)->data1 != 11 ||l2->get(0)->data2 != 21) {
        TEST_FAIL("[XmlReflect HashMap List Test case7]");
        break;
      }

      if(l2->get(1)->data1 != 31 ||l2->get(1)->data2 != 41) {
        TEST_FAIL("[XmlReflect HashMap List Test case8]");
        break;
      }

      if(l2->get(2)->data1 != 51 ||l2->get(2)->data2 != 61) {
        TEST_FAIL("[XmlReflect HashMap List Test case9]");
        break;
      }
      break;
    }

    TEST_OK("[XmlReflect HashMap List Test case100]");
}
