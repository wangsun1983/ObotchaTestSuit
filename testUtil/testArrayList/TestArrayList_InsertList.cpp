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


void testArrayList_InsertList() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    ArrayList<String> l1 = createArrayList<String>();
    l1->add(createString("l1_a"));
    l1->add(createString("l1_b"));
    list->insert(1,l1);
    if(list->size() != 4) {
      TEST_FAIL("ArrayList InsertList case1");
      break;
    }

    if(!list->get(0)->sameAs("a") ||!list->get(1)->sameAs("l1_a") ||!list->get(2)->sameAs("l1_b")
      ||!list->get(3)->sameAs("b")) {
        TEST_FAIL("ArrayList InsertList case2");
    }
    break;
  }

  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    ArrayList<String> l1 = createArrayList<String>();
    l1->add(createString("l1_a"));
    l1->add(createString("l1_b"));
    l1->add(createString("l1_c"));

    list->insert(1,l1,2);
    if(list->size() != 4) {
      TEST_FAIL("ArrayList InsertList case3");
      break;
    }

    if(!list->get(0)->sameAs("a") ||!list->get(1)->sameAs("l1_a") ||!list->get(2)->sameAs("l1_b")
      ||!list->get(3)->sameAs("b")) {
        TEST_FAIL("ArrayList InsertList case4");
    }
    break;
  }

  TEST_OK("[ArrayList Insert List test100]");
}
