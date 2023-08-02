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

void testArrayList_Construct() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    if(list->size() != 0) {
      TEST_FAIL("[ArrayList construct test1]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));
    list->add(createString("c"));

    ArrayList<String> list2 = createArrayList<String>(list);
    if(list2->size() != 3) {
      TEST_FAIL("[ArrayList construct test2] ");
      break;
    }

    if(!list2->get(0)->sameAs("a") ||!list2->get(1)->sameAs("b") ||!list2->get(2)->sameAs("c")) {
      TEST_FAIL("[ArrayList construct test3] ");
      break;
    }

    list->add(createString("d"));
    if(list2->size() != 3 || list->size() != 4) {
      TEST_FAIL("[ArrayList construct test4] ");
      break;
    }

    break;
  }
  TEST_OK("[ArrayList construct test100]");
}
