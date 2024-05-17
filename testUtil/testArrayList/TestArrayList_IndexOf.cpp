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

DECLARE_CLASS(IndexTestData) {
public:
  _IndexTestData(int v) {
    value = v;
  }

  int value;
};

DECLARE_CLASS(IndexTestData2) {
public:
  _IndexTestData2(int v) {
    value = v;
  }

  bool equals(IndexTestData2 v) {
    return value == v->value;
  }

  int value;
};

void testArrayList_IndexOf() {
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    if(list->indexOf(String::New("a")) != 0) {
      TEST_FAIL("[ArrayList IndexOf test1]");
      break;
    }

    if(list->indexOf(String::New("b")) != 1) {
      TEST_FAIL("[ArrayList IndexOf test2]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<Integer> list = ArrayList<Integer>::New();
    list->add(Integer::New(100));
    list->add(Integer::New(200));
    if(list->indexOf(Integer::New(100)) != 0) {
      TEST_FAIL("[ArrayList IndexOf test3]");
      break;
    }

    if(list->indexOf(Integer::New(200)) != 1) {
      TEST_FAIL("[ArrayList IndexOf test4]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<IndexTestData> list = ArrayList<IndexTestData>::New();
    IndexTestData t1 = IndexTestData::New(100);
    list->add(t1);

    IndexTestData t2 = IndexTestData::New(200);
    list->add(t2);

    if(list->indexOf(t1) != 0) {
      TEST_FAIL("[ArrayList IndexOf test5]");
      break;
    }

    if(list->indexOf(t2) != 1) {
      TEST_FAIL("[ArrayList IndexOf test6]");
      break;
    }

    if(list->indexOf(IndexTestData::New(100)) != -1) {
      TEST_FAIL("[ArrayList IndexOf test7]");
      break;
    }

    if(list->indexOf(IndexTestData::New(200)) != -1) {
      TEST_FAIL("[ArrayList IndexOf test8]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<IndexTestData2> list = ArrayList<IndexTestData2>::New();
    IndexTestData2 t1 = IndexTestData2::New(100);
    list->add(t1);

    IndexTestData2 t2 = IndexTestData2::New(200);
    list->add(t2);

    if(list->indexOf(IndexTestData2::New(100)) != 0) {
      TEST_FAIL("[ArrayList IndexOf test9]");
      break;
    }

    if(list->indexOf(IndexTestData2::New(200)) != 1) {
      TEST_FAIL("[ArrayList IndexOf test10]");
      break;
    }

    break;
  }

  TEST_OK("[ArrayList IndexOf test100]");
}
