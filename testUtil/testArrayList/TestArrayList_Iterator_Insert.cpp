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

void testArrayList_Iterator_Insert() {
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));

    auto iterator = list->getIterator();
    iterator->insert(String::New("a1"));
    if(list->size() != 2 || !list->get(0)->sameAs("a1") || !list->get(1)->sameAs("a")) {
      TEST_FAIL("[ArrayList Iterator Insert test1]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    auto iterator = list->getIterator();
    iterator->next();
    iterator->insert(String::New("a1"));
    if(list->size() != 3 || !list->get(0)->sameAs("a") || !list->get(1)->sameAs("a1") ||!list->get(2)->sameAs("b")) {
      TEST_FAIL("[ArrayList Iterator Insert test2]");
      break;
    }

    auto value = iterator->getValue();
    if(value == nullptr || !value->sameAs("a1")) {
      TEST_FAIL("[ArrayList Iterator Insert test3]");
      break;
    }

    break;
  }

  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    auto iterator = list->getIterator();
    iterator->next();
    iterator->insert(String::New("c"));
    iterator->insert(String::New("d"));
    if(list->size() != 4
    || !list->get(0)->equals(String::New("a"))
    || !list->get(1)->equals(String::New("d"))
    || !list->get(2)->equals(String::New("c"))
    || !list->get(3)->equals(String::New("b"))) {
      TEST_FAIL("[ArrayList Iterator Insert test4]");
      break;
    }
    break;
  }

  while(1) {
    ArrayList<int> list =ArrayList<int>::New();
    list->add(1);
    list->add(2);
    auto iterator = list->getIterator();

    int sum = 0;
    bool isFirst = true;
    while(iterator->hasValue()) {
      sum += iterator->getValue();
      if(iterator->getValue() == 2 && isFirst) {
        iterator->insert(3);
        isFirst = false;
        continue;
      }
      iterator->next();
    }

    if(sum != 8) {
      TEST_FAIL("[ArrayList Iterator Insert test5]");
      break;
    }
    break;
  }

  TEST_OK("[ArrayList Iterator Insert test100]");
}
