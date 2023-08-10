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


void testArrayList_InsertFirst() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("c"));
    list2->add(createString("d"));
    list->insertFirst(list2);

    if(list->size() != 4
      || !list->get(0)->sameAs("c")
      || !list->get(1)->sameAs("d")
      || !list->get(2)->sameAs("a")
      || !list->get(3)->sameAs("b")) {
        TEST_FAIL("[ArrayList insertFirst test1]");
        break;
      }

    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("c"));
    list2->add(createString("d"));
    list2->add(createString("e"));
    list2->add(createString("f"));

    list->insertFirst(list2,2);
    if(list->size() != 4
      || !list->get(0)->sameAs("c")
      || !list->get(1)->sameAs("d")
      || !list->get(2)->sameAs("a")
      || !list->get(3)->sameAs("b")) {
      TEST_FAIL("[ArrayList insertFirst test2]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("c"));
    bool isException = false;
    try {
      list->insertFirst(list2,2);
    } catch(...) {
      isException = true;
    }
    if(!isException) {
      TEST_FAIL("[ArrayList insertFirst test3]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = createArrayList<String>();

    ArrayList<String>list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list2->add(createString("c"));

    list1->insertFirst(list2);
    if(list1->size() != 3) {
      TEST_FAIL("[ArrayList insertFirst test4]");
    }

    if(!list1->get(0)->sameAs("a") || !list1->get(1)->sameAs("b")
      ||!list1->get(2)->sameAs("c")) {
        TEST_FAIL("[ArrayList insertFirst test5]");
    }
    break;
  }

  while(1) {
    ArrayList<String> list1 = createArrayList<String>(1);
    ArrayList<String>list2 = createArrayList<String>();
    list2->add(createString("a"));
    list2->add(createString("b"));
    list2->add(createString("c"));

    list1->insertFirst(list2);
    if(list1->size() != 3) {
      TEST_FAIL("[ArrayList insertFirst test6]");
    }

    if(!list1->get(0)->sameAs("a") || !list1->get(1)->sameAs("b")
      ||!list1->get(2)->sameAs("c")) {
        TEST_FAIL("[ArrayList insertFirst test7]");
    }
    break;
  }

  TEST_OK("[ArrayList insertFirst test100]");
}
