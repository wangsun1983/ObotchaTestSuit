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

void testArrayList_Iterator_Remove() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    auto iterator = list->getIterator();
    if(!iterator->remove()) {
      TEST_FAIL("[ArrayList Iterator Remove test1]");
      break;
    }

    String value = iterator->getValue();
    if(value == nullptr || !value->sameAs("b") || list->size() != 1) {
      TEST_FAIL("[ArrayList Iterator Remove test2]");
      break;
    }

    if(list->size() != 1) {
      TEST_FAIL("[ArrayList Iterator Remove test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    auto iterator = list->getIterator();
    if(iterator->remove()) {
      TEST_FAIL("[ArrayList Iterator Remove test4]");
      break;
    }
    break;
  }
  TEST_OK("[ArrayList Iterator Remove test100]");
}
