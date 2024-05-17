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

void testArrayList_Capacity() {
  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New(5);
    if(list1->capacity() != 5) {
      TEST_FAIL("[testArrayList capacity case1]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New();
    list1->add(String::New("a"));
    list1->add(String::New("b"));
    if(list1->capacity() != 2) {
      TEST_FAIL("[testArrayList capacity case2],capacity is %d",list1->capacity());
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New();
    list1->add(String::New("a"));
    list1->add(String::New("b"));
    list1->clear();
    if(list1->capacity() != 2) {
      TEST_FAIL("[testArrayList capacity case3],capacity is %d",list1->capacity());
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = ArrayList<String>::New(1);
    list1->add(String::New("a"));
    list1->add(String::New("b"));
    list1->clear();
    if(list1->capacity() != 2) {
      TEST_FAIL("[testArrayList capacity case4],capacity is %d",list1->capacity());
    }
    break;
  }


  TEST_OK("[ArrayList capacity test100]");
}
