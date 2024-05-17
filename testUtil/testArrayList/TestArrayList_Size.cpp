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

void testArrayList_Size() {
  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New();
    if(list1->size() != 0) {
      TEST_FAIL("[testArrayList size case1]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New();
    list1->add(String::New("a"));
    list1->add(String::New("b"));
    if(list1->size() != 2) {
      TEST_FAIL("[testArrayList size case2]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New();
    list1->add(String::New("a"));
    list1->add(String::New("b"));
    list1->clear();
    if(list1->size() != 0) {
      TEST_FAIL("[testArrayList size case3]");
    }
    break;
  }

  TEST_OK("[ArrayList Size test100]");
}
