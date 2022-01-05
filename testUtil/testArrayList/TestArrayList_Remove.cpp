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
};

void testArrayList_Remove() {
  while(1) {
    ArrayList<RemoveTestData> list = createArrayList<RemoveTestData>();
    RemoveTestData d1 = createRemoveTestData();
    d1->data1 = 1;
    d1->data2 = 2;

    RemoveTestData d2 = createRemoveTestData();
    d2->data1 = 3;
    d2->data2 = 4;

    RemoveTestData d3 = createRemoveTestData();
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

  TEST_OK("[ArrayList remove test100]");
}
