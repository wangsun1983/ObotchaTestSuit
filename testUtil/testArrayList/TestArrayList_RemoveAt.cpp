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

void testArrayList_RemoveAt() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    auto value = list->removeAt(0);
    if(value == nullptr || !value->equals("a")) {
      TEST_FAIL("[ArrayList removeAt test1]");
      break;
    }

    if(list->size() != 1) {
      TEST_FAIL("[ArrayList removeAt test2]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    bool isException = false;
    try {
      list->removeAt(0);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList removeAt test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));
    bool isException = false;
    try {
      list->removeAt(100);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList removeAt test4]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));
    bool isException = false;
    try {
      list->removeAt(-1);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList removeAt test5]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));
    list->clear();
    bool isException = false;
    try {
      list->removeAt(0);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList removeAt test6]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList removeAt test100]");
}
