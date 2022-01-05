#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testArrayListForEach() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString(1));
    list->add(createString(2));
    list->add(createString(3));

    int index = 1;
    list->foreach([&index](String value) {
      if(value->toBasicInt() != index) {
        TEST_FAIL("[ArrayList Foreach test1]");
        return Global::Break;
      }
      index++;
      return Global::Continue;
    });
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString(1));
    list->add(createString(2));
    list->add(createString(3));
    int index = 1;
    list->foreach([&index](String value) {
      if(index == 2) {
        return Global::Break;
      }
      index++;
      return Global::Continue;
    });

    if(index != 2) {
      TEST_FAIL("[ArrayList Foreach test2]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList Foreach test100]");
}
