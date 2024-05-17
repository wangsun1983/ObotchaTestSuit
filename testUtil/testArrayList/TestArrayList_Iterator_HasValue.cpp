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

void testArrayList_Iterator_HasValue() {
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    auto iterator = list->getIterator();
    if(iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test1]");
      break;
    }

    list->add(String::New("a")); //this may case crash~~~.haha
    if(!iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test2]");
      break;
    }

#if 0
    iterator->remove();
    if(iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test2_1]");
      break;
    }

    if(list->size() != 0) {
      TEST_FAIL("[ArrayList Iterator HasValue test2_2]");
      break;
    }
#endif

    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    auto iterator = list->getIterator();
    if(!iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test3]");
      break;
    }

    iterator->remove();
    if(iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test4] ");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    auto iterator = list->getIterator();
    if(!iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test5] ");
      break;
    }

    iterator->next();
    if(iterator->hasValue()) {
      TEST_FAIL("[ArrayList Iterator HasValue test6] ");
      break;
    }

    break;
  }

  TEST_OK("[ArrayList Iterator HasValue test100]");
}
