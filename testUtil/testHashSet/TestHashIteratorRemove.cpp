#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashIteratorRemove() {

    //remove string
    while(1) {
        HashSet<String> set = HashSet<String>::New();
        set->add(String::New("abc"));
        set->add(String::New("abc1"));
        set->add(String::New("abc2"));
        set->add(String::New("abc3"));
        HashSetIterator<String> iterator = set->getIterator();
        while(iterator->hasValue()) {
          String v1 = iterator->getValue();
          if(v1->sameAs("abc2")) {
            iterator->remove();
            continue;
          }

          iterator->next();
        }

        if(set->size() != 3) {
          TEST_FAIL("HashSet iterator remove test1");
          break;
        }

        int count = 0;
        iterator = set->getIterator();
        while(iterator->hasValue()) {
          String v1 = iterator->getValue();
          if(!v1->sameAs("abc") && !v1->sameAs("abc1") && !v1->sameAs("abc3")) {
            iterator->next();
            continue;
          }
          count++;
          iterator->next();
        }

        if(count != 3) {
          TEST_FAIL("HashSet iterator remove test2");
        }

        break;
    }

    //remove int
    while(1) {
        HashSet<int> set = HashSet<int>::New();
        set->add(1);
        set->add(2);
        set->add(3);
        set->add(4);
        HashSetIterator<int> iterator = set->getIterator();
        while(iterator->hasValue()) {
          int v1 = iterator->getValue();
          if(v1 == 2) {
            iterator->remove();
            continue;
          }

          iterator->next();
        }

        if(set->size() != 3) {
          TEST_FAIL("HashSet iterator remove test3");
          break;
        }

        int count = 0;
        iterator = set->getIterator();
        while(iterator->hasValue()) {
          int v1 = iterator->getValue();
          if(v1!=1 && v1!=3 && v1!=4) {
            iterator->next();
            continue;
          }
          count++;
          iterator->next();
        }

        if(count != 3) {
          TEST_FAIL("HashSet iterator remove test4");
        }

        break;
    }
    TEST_OK("HashSet iterator remove test100");
}
