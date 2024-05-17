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

DECLARE_CLASS(RemoveTestData) {
public:
  int data1;
  int data2;

  _RemoveTestData(int d1,int d2) {
    data1 = d1;
    data2 = d2;
  }

  _RemoveTestData() {
    data1 = 0;
    data2 = 0;
  }
};

void testArrayList_Remove() {
  while(1) {
    ArrayList<RemoveTestData> list = ArrayList<RemoveTestData>::New();
    RemoveTestData d1 = RemoveTestData::New();
    d1->data1 = 1;
    d1->data2 = 2;

    RemoveTestData d2 = RemoveTestData::New();
    d2->data1 = 3;
    d2->data2 = 4;

    RemoveTestData d3 = RemoveTestData::New();
    d3->data1 = 5;
    d3->data2 = 6;

    list->add(d1);
    list->add(d2);
    list->add(d3);

    if(list->size() != 3) {
      TEST_FAIL("[ArrayList remvoe test1]");
      break;
    }

    int index = list->remove(d2);
    if(list->size() != 2 || index != 1) {
      TEST_FAIL("[ArrayList remvoe test2]");
      break;
    }

    auto ll_d1 = list->get(0);
    if(ll_d1->data1 != 1 || ll_d1->data2 != 2) {
      TEST_FAIL("[ArrayList remvoe test2]");
      break;
    }

    auto ll_d2 = list->get(1);
    if(ll_d2->data1 != 5 || ll_d2->data2 != 6) {
      TEST_FAIL("[ArrayList remvoe test3]");
      break;
    }

    index = list->remove(d3);
    if(index != 1) {
      TEST_FAIL("[ArrayList remvoe test4]");
      break;
    }

    index = list->remove(d1);
    if(index != 0) {
      TEST_FAIL("[ArrayList remvoe test5]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<RemoveTestData> list = ArrayList<RemoveTestData>::New();
    auto t1 = RemoveTestData::New(1,1);
    if(list->remove(t1) != -1) {
      TEST_FAIL("[ArrayList remvoe test6]");
    }

    if(list->remove(nullptr) != -1) {
      TEST_FAIL("[ArrayList remvoe test7]");
    }
    break;
  }

  TEST_OK("[ArrayList remove test100]");
}
