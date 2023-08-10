#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashAdd() {

    //case string
    while(1) {
        HashSet<String> set = createHashSet<String>();
        set->add(createString("abc"));
        set->add(createString("abc"));
        set->add(createString("abc1"));
        set->add(createString("abc2"));
        set->add(createString("abc3"));

        if(set->size() != 4) {
          TEST_FAIL("HashSet base test1");
          break;
        }

        HashSetIterator<String> it = set->getIterator();
        int count = 0;
        while(it->hasValue()) {
          String vv = it->getValue();
          if(!vv->sameAs("abc") && !vv->sameAs("abc1") && !vv->sameAs("abc2") && !vv->sameAs("abc3")) {
            it->next();
            continue;
          }
          count++;
          it->next();
        }

        if(count != 4) {
          TEST_FAIL("HashSet base test2");
          break;
        }

        set->remove(createString("abc"));
        it = set->getIterator();
        count = 0;
        while(it->hasValue()) {
          String vv = it->getValue();
          if(!vv->sameAs("abc1") && !vv->sameAs("abc2") && !vv->sameAs("abc3")) {
            it->next();
            continue;
          }
          count++;
          it->next();
        }

        if(count != 3) {
          TEST_FAIL("HashSet base test3");
          break;
        }

        break;
    }

    //case int
    while(1) {
        HashSet<int> set = createHashSet<int>();
        set->add(1);
        set->add(2);
        set->add(2);
        set->add(3);
        set->add(4);

        if(set->size() != 4) {
          TEST_FAIL("HashSet base test4");
          break;
        }

        HashSetIterator<int> it = set->getIterator();
        int count = 0;
        while(it->hasValue()) {
          int vv = it->getValue();
          if(vv != 1 && vv != 2 && vv != 3 && vv != 4) {
            it->next();
            continue;
          }
          count++;
          it->next();
        }

        if(count != 4) {
          TEST_FAIL("HashSet base test5");
          break;
        }

        set->remove(2);
        it = set->getIterator();
        count = 0;
        while(it->hasValue()) {
          int vv = it->getValue();
          if(vv != 1 && vv != 3 && vv !=4) {
            it->next();
            continue;
          }
          count++;
          it->next();
        }

        if(count != 3) {
          TEST_FAIL("HashSet base test6");
          break;
        }

        break;
    }

    //case string
    while(1) {
        HashSet<String> set = createHashSet<String>();
        set->add(createString("abc"));
        set->add(createString("abc"));
        set->add(createString("abc1"));
        set->add(createString("abc2"));
        set->add(createString("abc3"));

        if(set->size() != 4) {
          TEST_FAIL("HashSet base test7");
          break;
        }

        set->remove(createString("abc"));
        set->remove(createString("abc1"));
        set->remove(createString("abc2"));
        set->remove(createString("abc3"));

        if(set->size() != 0) {
          TEST_FAIL("HashSet base test8");
        }
        break;
    }

    //case int
    while(1) {
        HashSet<int> set = createHashSet<int>();
        set->add(1);
        set->add(2);
        set->add(1);
        set->add(3);
        set->add(4);

        if(set->size() != 4) {
          TEST_FAIL("HashSet base test8");
          break;
        }

        set->remove(1);
        set->remove(2);
        set->remove(3);
        set->remove(4);

        if(set->size() != 0) {
          TEST_FAIL("HashSet base test9");
        }
        break;
    }

    TEST_OK("HashSet base test100");
}
