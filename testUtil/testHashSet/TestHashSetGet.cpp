#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashSetGet() {

    //case string
    while(1) {
        HashSet<String> set = createHashSet<String>();
        set->add(createString("abc"));
        set->add(createString("abc"));
        set->add(createString("abc1"));
        set->add(createString("abc2"));
        set->add(createString("abc3"));

        auto iterator = set->getIterator();
        int count = 0;
        while(iterator->hasValue()) {
            if(iterator->getValue() != set->get(count)) {
                TEST_FAIL("HashSet get test case1");
            }
            count++;
            iterator->next();
        }
        
        if(count != set->size()) {
            TEST_FAIL("HashSet get test case2");
        }
        break;
    }

    TEST_OK("HashSet get test case100");
}
