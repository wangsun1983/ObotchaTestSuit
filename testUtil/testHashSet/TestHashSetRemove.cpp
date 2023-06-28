#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashRemove() {
    //case int
    while(1) {
        HashSet<String> set = createHashSet<String>();
        set->add(createString("a"));
        set->add(createString("b"));
        set->add(createString("c"));
        
        if(set->size() != 3) {
            TEST_FAIL("HashSet Remove case1,size is %d",set->size());
        }

        set->remove(createString("b"));
        if(set->size() != 2) {
            TEST_FAIL("HashSet Remove case2,size is %d",set->size());
        }
        
        if(set->contains(createString("b"))) {
            TEST_FAIL("HashSet Remove case3");
        }
        break;
    }

    TEST_OK("HashSet Remove case100");
}
