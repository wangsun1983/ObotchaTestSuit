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


void testArrayList_Insert() {
  //int insert(int index,const T val)
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));
    list->insert(0,createString("c"));
    if(list->size() != 3 || !list->get(0)->equals("c")
      || !list->get(1)->equals("a")|| !list->get(2)->equals("b")) {
      TEST_FAIL("[ArrayList Insert test1]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->insert(0,createString("c"));
    if(list->size() != 1 || !list->get(0)->equals("c")) {
      TEST_FAIL("[ArrayList Insert test2]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->insert(0,createString("c"));
    list->insert(1,createString("d"));
    if(list->size() != 2 || !list->get(0)->equals("c") || !list->get(1)->equals("d")) {
      TEST_FAIL("[ArrayList Insert test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    bool isException = false;
    try {
      list->insert(1,createString("c"));
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList Insert test4]");
      break;
    }
    break;
  }

  //int insert(int index,const ArrayList<T> &list)
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("c"));
    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list->insert(0,list2);
    if(list->size() != 3 || !list->get(0)->equals("a")
      || !list->get(1)->equals("b")|| !list->get(2)->equals("c")) {
      TEST_FAIL("[ArrayList Insert test5]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list->insert(0,list2);
    if(list->size() != 2 || !list->get(0)->equals("a")
      || !list->get(1)->equals("b")) {
      TEST_FAIL("[ArrayList Insert test6]");
      break;
    }

    list2->clear();
    if(list->size() != 2 || !list->get(0)->equals("a")
      || !list->get(1)->equals("b")) {
      TEST_FAIL("[ArrayList Insert test7]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("c"));
    list->add(createString("d"));
    list->add(createString("e"));

    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list->insert(2,list2);
    if(list->size() != 5 || !list->get(0)->equals("c")
      || !list->get(1)->equals("d")
      || !list->get(2)->equals("a")
      || !list->get(3)->equals("b")
      || !list->get(4)->equals("e")
      ) {
      TEST_FAIL("[ArrayList Insert test8]");
      break;
    }
    break;
  }

  //int insert(int index,const ArrayList<T> &list,int length)
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("c"));
    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list->insert(0,list2,1);
    if(list->size() != 2 || !list->get(0)->equals("a")
      || !list->get(1)->equals("c")) {
      TEST_FAIL("[ArrayList Insert test9]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list->insert(0,list2,1);
    if(list->size() != 1 || !list->get(0)->equals("a")) {
      TEST_FAIL("[ArrayList Insert test10]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    bool isException = false;
    try {
      list->insert(0,list2,12);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList Insert test11]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList Insert test100]");
}
