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

void testArrayList_InsertLast() {
  while(1) {
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("b"));

    ArrayList<String> list2 = createArrayList<String>();
    list2->add(createString("c"));
    list2->add(createString("d"));
    list->insertLast(list2);

    if(list->size() != 4
      || !list->get(0)->equals("a")
      || !list->get(1)->equals("b")
      || !list->get(2)->equals("c")
      || !list->get(3)->equals("d")) {
        TEST_FAIL("[ArrayList InsertLast test1]");
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

    list->insertLast(list2,2);
    //TEST_FAIL("size is %d \n",list->size());
    //TEST_FAIL("a1 %s,a2 %s,a3 %s,a4 %s \n",list->get(0)->toChars(),list->get(1)->toChars(),list->get(2)->toChars(),list->get(3)->toChars());
    if(list->size() != 4
      || !list->get(0)->equals("a")
      || !list->get(1)->equals("b")
      || !list->get(2)->equals("c")
      || !list->get(3)->equals("d")) {
      TEST_FAIL("[ArrayList InsertLast test2]");
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
      list->insertLast(list2,2);
    } catch(...) {
      isException = true;
    }
    if(!isException) {
      TEST_FAIL("[ArrayList InsertLast test3]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList InsertLast test100]");
}
