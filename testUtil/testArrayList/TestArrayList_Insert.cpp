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
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->insert(0,String::New("c"));
    if(list->size() != 3 || !list->get(0)->sameAs("c")
      || !list->get(1)->sameAs("a")|| !list->get(2)->sameAs("b")) {
      TEST_FAIL("[ArrayList Insert test1]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->insert(0,String::New("c"));
    if(list->size() != 1 || !list->get(0)->sameAs("c")) {
      TEST_FAIL("[ArrayList Insert test2]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->insert(0,String::New("c"));
    list->insert(1,String::New("d"));
    if(list->size() != 2 || !list->get(0)->sameAs("c") || !list->get(1)->sameAs("d")) {
      TEST_FAIL("[ArrayList Insert test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    bool isException = false;
    try {
      list->insert(1,String::New("c"));
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
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("c"));
    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("a"));
    list2->add(String::New("b"));
    list->insert(0,list2);
    if(list->size() != 3 || !list->get(0)->sameAs("a")
      || !list->get(1)->sameAs("b")|| !list->get(2)->sameAs("c")) {
      TEST_FAIL("[ArrayList Insert test5]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("a"));
    list2->add(String::New("b"));
    list->insert(0,list2);
    if(list->size() != 2 || !list->get(0)->sameAs("a")
      || !list->get(1)->sameAs("b")) {
      TEST_FAIL("[ArrayList Insert test6]");
      break;
    }

    list2->clear();
    if(list->size() != 2 || !list->get(0)->sameAs("a")
      || !list->get(1)->sameAs("b")) {
      TEST_FAIL("[ArrayList Insert test7]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("c"));
    list->add(String::New("d"));
    list->add(String::New("e"));

    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("a"));
    list2->add(String::New("b"));
    list->insert(2,list2);
    if(list->size() != 5 || !list->get(0)->sameAs("c")
      || !list->get(1)->sameAs("d")
      || !list->get(2)->sameAs("a")
      || !list->get(3)->sameAs("b")
      || !list->get(4)->sameAs("e")
      ) {
      TEST_FAIL("[ArrayList Insert test8]");
      break;
    }
    break;
  }

  //int insert(int index,const ArrayList<T> &list,int length)
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("c"));
    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("a"));
    list2->add(String::New("b"));
    list->insert(0,list2,1);
    if(list->size() != 2 || !list->get(0)->sameAs("a")
      || !list->get(1)->sameAs("c")) {
      TEST_FAIL("[ArrayList Insert test9]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("a"));
    list2->add(String::New("b"));
    list->insert(0,list2,1);
    if(list->size() != 1 || !list->get(0)->sameAs("a")) {
      TEST_FAIL("[ArrayList Insert test10]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("a"));
    list2->add(String::New("b"));
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

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->insert(0,String::New("b"));
    list->insert(1,String::New("c"));

    if(!list->get(0)->sameAs("b")) {
      TEST_FAIL("[ArrayList Insert test12]");
    }

    if(!list->get(1)->sameAs("c")) {
      TEST_FAIL("[ArrayList Insert test13]");
    }

    if(!list->get(2)->sameAs("a")) {
      TEST_FAIL("[ArrayList Insert test14]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->insert(0,String::New("a"));
    if(list->size() != 1) {
      TEST_FAIL("[ArrayList Insert test15]");
    }

    auto v1 = list->get(0);
    if(!v1->sameAs("a")) {
      TEST_FAIL("[ArrayList Insert test16]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->insert(2,String::New("c"));
    if(list->size() != 3) {
      TEST_FAIL("[ArrayList Insert test17]");
    }

    if(!list->get(0)->sameAs("a") ||!list->get(1)->sameAs("b")
      ||!list->get(2)->sameAs("c")) {
        TEST_FAIL("[ArrayList Insert test17]");
    }
    
    break;
  }


  TEST_OK("[ArrayList Insert test100]");
}
