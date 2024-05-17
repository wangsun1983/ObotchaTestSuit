#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "Boolean.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(AddTestData) {
public:
  int data1;
  int data2;
};

void testArrayList_Add_Lists() {
  while(1) {
    ArrayList<AddTestData> list1 = ArrayList<AddTestData>::New();
    AddTestData d1 = AddTestData::New();
    d1->data1 = 1;
    d1->data2 = 2;

    AddTestData d2 = AddTestData::New();
    d2->data1 = 3;
    d2->data2 = 4;
    list1->add(d1);
    list1->add(d2);

    ArrayList<AddTestData> list2 = ArrayList<AddTestData>::New();
    list2->add(list1);

    AddTestData data = list2->get(0);
    if(data == nullptr || data->data1 != 1 ||data->data2 != 2) {
      TEST_FAIL("[ArrayList add test1]");
    }

    data = list2->get(1);
    if(data == nullptr || data->data1 != 3 ||data->data2 != 4) {
      TEST_FAIL("[ArrayList add test2]");
    }
    break;
  }

  while(1) {
    ArrayList<ArrayList<AddTestData>> list1 = ArrayList<ArrayList<AddTestData>>::New();
    AddTestData d1 = AddTestData::New();
    d1->data1 = 1;
    d1->data2 = 2;

    AddTestData d2 = AddTestData::New();
    d2->data1 = 3;
    d2->data2 = 4;

    ArrayList<AddTestData> l1 = ArrayList<AddTestData>::New();
    l1->add(d1);

    ArrayList<AddTestData> l2 = ArrayList<AddTestData>::New();
    l2->add(d2);

    list1->add(l1);
    list1->add(l2);

    ArrayList<ArrayList<AddTestData>> list2 = ArrayList<ArrayList<AddTestData>>::New();
    list2->add(list1);

    if(list2->size() != 2) {
      TEST_FAIL("[ArrayList add test3]");
      break;
    }

    ArrayList<AddTestData> ll1 = list2->get(0);
    AddTestData ll1_data = ll1->get(0);
    if(ll1_data->data1 != 1 || ll1_data->data2 != 2) {
      TEST_FAIL("[ArrayList add test4]");
      break;
    }

    ArrayList<AddTestData> ll2 = list2->get(1);
    AddTestData ll2_data = ll2->get(0);
    if(ll2_data->data1 != 3 || ll2_data->data2 != 4) {
      TEST_FAIL("[ArrayList add test5] [FAILED]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList add test100]");
}
