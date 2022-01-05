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

void testArrayList_Iterator_Next() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    auto iterator = list->getIterator();
    if(iterator->next()) {
      TEST_FAIL("[ArrayList Iterator Next test1]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    auto iterator = list->getIterator();
    if(iterator->next()) {
      TEST_FAIL("[ArrayList Iterator Next test2]");
      break;
    }

    if(iterator->next()) {
      TEST_FAIL("[ArrayList Iterator Next test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    auto iterator = list->getIterator();
    if(!iterator->next()) {
      TEST_FAIL("[ArrayList Iterator Next test4]");
      break;
    }

    if(iterator->next()) {
      TEST_FAIL("[ArrayList Iterator Next test5]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList Iterator Next test100]");
}
