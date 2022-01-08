#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashContains() {

    HashSet<String> set = createHashSet<String>();
    set->add(createString("abc"));
    set->add(createString("abc"));
    set->add(createString("abc1"));
    set->add(createString("abc2"));
    set->add(createString("abc3"));
    if(!set->contains(createString("abc1"))) {
        TEST_FAIL("HashSet Contains test1");
    }

    if(set->contains(createString("abcd"))) {
        TEST_FAIL("HashSet Contains test2");
    }

    TEST_OK("HashSet Contains test100");
}
