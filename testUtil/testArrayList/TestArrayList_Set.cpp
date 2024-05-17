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

void testArrayList_Set() {
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();

    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    list->set(0,"t1");
    list->set(1,"t2");
    list->set(2,"t3");

    if(list->size() != 3) {
      TEST_FAIL("[testArrayList_Set Test case1]");
    }

    if(!list->get(0)->sameAs("t1") ||
      !list->get(1)->sameAs("t2") ||
      !list->get(2)->sameAs("t3")) {
      TEST_FAIL("[testArrayList_Set Test case2]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New(10);
    try {
      list->set(2,String::New("a"));
    } catch(...) {
      break;
    }
    TEST_FAIL("[testArrayList_Set Test case3]");
  }

  TEST_OK("[testArrayList_Set Test case100]");
  
}
