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
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));
    if(list->indexOf(createString("a")) != 0) {
      TEST_FAIL("[ArrayList IndexOf test1]");
      break;
    }

    if(list->indexOf(createString("b")) != 1) {
      TEST_FAIL("[ArrayList IndexOf test2]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<Integer> list = createArrayList<Integer>();
    list->add(createInteger(100));
    list->add(createInteger(200));
    if(list->indexOf(createInteger(100)) != 0) {
      TEST_FAIL("[ArrayList IndexOf test3]");
      break;
    }

    if(list->indexOf(createInteger(200)) != 1) {
      TEST_FAIL("[ArrayList IndexOf test4]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<IndexTestData> list = createArrayList<IndexTestData>();
    IndexTestData t1 = createIndexTestData(100);
    list->add(t1);

    IndexTestData t2 = createIndexTestData(200);
    list->add(t2);

    if(list->indexOf(t1) != 0) {
      TEST_FAIL("[ArrayList IndexOf test5]");
      break;
    }

    if(list->indexOf(t2) != 1) {
      TEST_FAIL("[ArrayList IndexOf test6]");
      break;
    }

    if(list->indexOf(createIndexTestData(100)) != -1) {
      TEST_FAIL("[ArrayList IndexOf test7]");
      break;
    }

    if(list->indexOf(createIndexTestData(200)) != -1) {
      TEST_FAIL("[ArrayList IndexOf test8]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<IndexTestData2> list = createArrayList<IndexTestData2>();
    IndexTestData2 t1 = createIndexTestData2(100);
    list->add(t1);

    IndexTestData2 t2 = createIndexTestData2(200);
    list->add(t2);

    if(list->indexOf(createIndexTestData2(100)) != 0) {
      TEST_FAIL("[ArrayList IndexOf test9]");
      break;
    }

    if(list->indexOf(createIndexTestData2(200)) != 1) {
      TEST_FAIL("[ArrayList IndexOf test10]");
      break;
    }

    break;
  }

  TEST_OK("[ArrayList IndexOf test100]");
}
