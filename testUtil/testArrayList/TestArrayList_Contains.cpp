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

DECLARE_CLASS(ContainsTestData) {
public:
  int data1;
  String data2;

  _ContainsTestData(int v,String v2) {
    data1 = v;
    data2 = v2;
  }

  bool equals(sp<_ContainsTestData> v) {
    return data1 == v->data1 && data2->equals(v->data2);
  }
};

void testArrayList_Contains() {
  while(1) {
    ArrayList<ContainsTestData> list1 = ArrayList<ContainsTestData>::New();
    list1->add(ContainsTestData::New(1,String::New("hello")));
    if(!list1->contains(ContainsTestData::New(1,String::New("hello")))) {
        TEST_FAIL("ArrayList contains case1");
    }

    if(list1->contains(ContainsTestData::New(2,String::New("hello")))) {
        TEST_FAIL("ArrayList contains case2");
    }

    if(list1->contains(ContainsTestData::New(1,String::New("he1llo")))) {
        TEST_FAIL("ArrayList contains case3");
    }
    break;
  }

  while(1) {
    ArrayList<ContainsTestData> list1 = ArrayList<ContainsTestData>::New();
    auto t1 = ContainsTestData::New(1,String::New("hello"));
    if(list1->contains(t1)) {
      TEST_FAIL("ArrayList contains case4");
    }
    break;
  }

  while(1) {
    ArrayList<ContainsTestData> list1 = ArrayList<ContainsTestData>::New();
    auto t1 = ContainsTestData::New(1,String::New("hello"));
    list1->add(t1);
    list1->removeAt(0);

    if(list1->contains(t1)) {
      TEST_FAIL("ArrayList contains case5");
    }
    break;
  }

  TEST_OK("[ArrayList contains test100]");
}
