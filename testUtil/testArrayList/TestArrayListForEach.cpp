#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testArrayListForEach() {
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New(1));
    list->add(String::New(2));
    list->add(String::New(3));

    int index = 1;
    //list->foreach([&index](String value) {
    //  if(value->toBasicInt() != index) {
    //    TEST_FAIL("[ArrayList Foreach test1]");
    //    return Global::Break;
    //  }
    //  index++;
    //  return Global::Continue;
    //});
    ForEveryOne(value,list) {
      if(value->toBasicInt() != index) {
        TEST_FAIL("[ArrayList Foreach test1]");
        break;
      }
      index++;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New(1));
    list->add(String::New(2));
    list->add(String::New(3));
    int index = 1;
    //list->foreach([&index](String value) {
    //  if(index == 2) {
    //    return Global::Break;
    //  }
    //  index++;
    //  return Global::Continue;
    //});
    ForEveryOne(value,list) {
      if(index == 2) {
        break;
      }
      index++;
    }

    if(index != 2) {
      TEST_FAIL("[ArrayList Foreach test2]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList Foreach test100]");
}
