#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "NullPointerException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TestRemoveData) {
public:
  _TestRemoveData(int v1,int v2) {
    value1 = v1;
    value2 = v2;
  }

  int value1;
  int value2;
};

void testArrayList_removeList() {
  while(1) {
    TestRemoveData d1 = TestRemoveData::New(1,2);
    TestRemoveData d2 = TestRemoveData::New(3,4);
    TestRemoveData d3 = TestRemoveData::New(5,6);

    ArrayList<TestRemoveData> list = ArrayList<TestRemoveData>::New();
    list->add(d1);
    list->add(d2);
    list->add(d3);

    ArrayList<TestRemoveData> list2 = ArrayList<TestRemoveData>::New();
    list2->add(d2);
    list2->add(d1);

    list->removeAll(list2);
    if(list->size() != 1) {
      TEST_FAIL("[ArrayList remvoe list test1]");
    }

    auto lastvalue = list->get(0);
    if(lastvalue->value1 != 5 || lastvalue->value2 != 6) {
      TEST_FAIL("[ArrayList remvoe list test2]");
    }
    break;
  }

  while(1) {
    TestRemoveData d1 = TestRemoveData::New(1,2);
    TestRemoveData d2 = TestRemoveData::New(3,4);
    TestRemoveData d3 = TestRemoveData::New(5,6);

    ArrayList<TestRemoveData> list = ArrayList<TestRemoveData>::New();
    list->add(d1);
    list->add(d2);
    list->add(d3);

    TestRemoveData d4 = TestRemoveData::New(88,88);
    ArrayList<TestRemoveData> list2 = ArrayList<TestRemoveData>::New();
    list2->add(d4);
    list->removeAll(list2);

    if(list->size() != 3) {
      TEST_FAIL("[ArrayList remvoe list test3]");
    }
    break;
  }

  while(1) {
    TestRemoveData d1 = TestRemoveData::New(1,2);

    ArrayList<TestRemoveData> list = ArrayList<TestRemoveData>::New();
    list->add(d1);

    ArrayList<TestRemoveData> list2 = ArrayList<TestRemoveData>::New();
    list2->add(d1);
    list2->add(d1);

    list->removeAll(list2);

    if(list->size() != 0) {
      TEST_FAIL("[ArrayList remvoe list test4]");
    }
    break;
  }

  TEST_OK("[ArrayList remvoe list test1]");
}
