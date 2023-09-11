#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"
#include "String.hpp"
using namespace obotcha;

void testLinkedListPeekFirst() {

    //case1 string putLast
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        auto v1 = mList->peekFirst();
        auto v2 = mList->peekFirst();
        if(!v1->sameAs("a") || !v2->sameAs("a")) {
            TEST_FAIL("LinkedList PeekFirst case1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
        }
        
        if(mList->size() != 3) {
            TEST_FAIL("LinkedList PeekFirst case2");
        }
        break;
    }
    
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->takeFirst();
        
        auto v1 = mList->peekFirst();
        if(v1 != nullptr) {
            TEST_FAIL("LinkedList PeekFirst case3");
        }
        break;
    }

    TEST_OK("LinkedList PeekFirst case100");

}
