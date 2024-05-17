#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashContains() {

    HashSet<String> set = HashSet<String>::New();
    set->add(String::New("abc"));
    set->add(String::New("abc"));
    set->add(String::New("abc1"));
    set->add(String::New("abc2"));
    set->add(String::New("abc3"));
    if(!set->contains(String::New("abc1"))) {
        TEST_FAIL("HashSet Contains test1");
    }

    if(set->contains(String::New("abcd"))) {
        TEST_FAIL("HashSet Contains test2");
    }

    TEST_OK("HashSet Contains test100");
}
