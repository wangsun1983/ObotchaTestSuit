#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashRemove() {
    //case int
    while(1) {
        HashSet<String> set = HashSet<String>::New();
        set->add(String::New("a"));
        set->add(String::New("b"));
        set->add(String::New("c"));
        
        if(set->size() != 3) {
            TEST_FAIL("HashSet Remove case1,size is %d",set->size());
        }

        set->remove(String::New("b"));
        if(set->size() != 2) {
            TEST_FAIL("HashSet Remove case2,size is %d",set->size());
        }
        
        if(set->contains(String::New("b"))) {
            TEST_FAIL("HashSet Remove case3");
        }
        break;
    }

    TEST_OK("HashSet Remove case100");
}
