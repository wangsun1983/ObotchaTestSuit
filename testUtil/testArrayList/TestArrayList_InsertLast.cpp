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

void testArrayList_InsertLast() {
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));

    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("c"));
    list2->add(String::New("d"));
    list->insertLast(list2);

    if(list->size() != 4
      || !list->get(0)->sameAs("a")
      || !list->get(1)->sameAs("b")
      || !list->get(2)->sameAs("c")
      || !list->get(3)->sameAs("d")) {
        TEST_FAIL("[ArrayList InsertLast test1]");
        break;
      }

    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));

    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("c"));
    list2->add(String::New("d"));
    list2->add(String::New("e"));
    list2->add(String::New("f"));

    list->insertLast(list2,2);
    //TEST_FAIL("size is %d \n",list->size());
    //TEST_FAIL("a1 %s,a2 %s,a3 %s,a4 %s \n",list->get(0)->toChars(),list->get(1)->toChars(),list->get(2)->toChars(),list->get(3)->toChars());
    if(list->size() != 4
      || !list->get(0)->sameAs("a")
      || !list->get(1)->sameAs("b")
      || !list->get(2)->sameAs("c")
      || !list->get(3)->sameAs("d")) {
      TEST_FAIL("[ArrayList InsertLast test2]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));

    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("c"));
    bool isException = false;
    try {
      list->insertLast(list2,2);
    } catch(...) {
      isException = true;
    }
    if(!isException) {
      TEST_FAIL("[ArrayList InsertLast test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();

    list->insertLast(String::New("c"));
    list->insertLast(String::New("d"));

    if(list->size() != 2) {
      TEST_FAIL("[ArrayList InsertLast test4]");
      break;
    }

    if(!list->get(0)->sameAs("c") ||!list->get(1)->sameAs("d")) {
        TEST_FAIL("[ArrayList InsertLast test5]");
        break;
    }
    break;
  }

  TEST_OK("[ArrayList InsertLast test100]");
}
