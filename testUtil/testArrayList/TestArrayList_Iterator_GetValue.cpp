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

void testArrayList_Iterator_GetValue() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    auto iterator = list->getIterator();
    auto v = iterator->getValue();
    if(v == nullptr || !v->sameAs("a")) {
      TEST_FAIL("[ArrayList Iterator GetValue test1]");
      break;
    }

    iterator->next();
    v = iterator->getValue();
    if(v == nullptr || !v->sameAs("b")) {
      TEST_FAIL("[ArrayList Iterator GetValue test2]");
      break;
    }

    iterator->next();
    bool isExcpetion = false;
    try {
      v = iterator->getValue();
    } catch(...) {
      isExcpetion = true;
    }

    if(!isExcpetion) {
      TEST_FAIL("[ArrayList Iterator GetValue test3]");
      break;
    }

    break;
  }

  while(1) {
      ArrayList<String> list = createArrayList<String>();
      auto iterator = list->getIterator();
      bool isExcpetion = false;
      try {
        auto v = iterator->getValue();
      } catch(...) {
        isExcpetion = true;
      }

      if(!isExcpetion) {
        TEST_FAIL("[ArrayList Iterator GetValue test4]");
        break;
      }
      break;
  }

  TEST_OK("[ArrayList Iterator GetValue test100]");
}
