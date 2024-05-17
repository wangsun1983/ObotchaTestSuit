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

DECLARE_CLASS(TestGetData) {
public:
  int data1;
  int data2;
  _TestGetData(int v1,int v2) {
    data1 = v1;
    data2 = v2;
  }
};

void testArrayList_Get() {
  while(1) {
    ArrayList<TestGetData> list = ArrayList<TestGetData>::New();
    TestGetData t1 = TestGetData::New(1,2);
    TestGetData t2 = TestGetData::New(3,4);
    list->add(t1);
    list->add(t2);

    auto t_1 = list->get(0);
    if(t_1->data1 != 1 || t_1->data2 != 2) {
      TEST_FAIL("[ArrayList Get test1]");
    }

    auto t_2 = list->get(1);
    if(t_2->data1 != 3 || t_2->data2 != 4) {
      TEST_FAIL("[ArrayList Get test2]");
    }

    t1->data1 = 100;
    t1->data2 = 101;

    t_1 = list->get(0);
    if(t_1->data1 != 100 || t_1->data2 != 101) {
      TEST_FAIL("[ArrayList Get test3]");
    }
    break;
  }

  TEST_OK("[testArrayList_Get Test case100]");

}
