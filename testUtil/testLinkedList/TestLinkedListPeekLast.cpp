#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkedListPeekLast() {

    //case1 string putLast
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        auto v1 = mList->peekLast();
        auto v2 = mList->peekLast();
        if(!v1->sameAs("c") || !v2->sameAs("c")) {
            TEST_FAIL("LinkedList PeekLast case1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
        }
        
        if(mList->size() != 3) {
            TEST_FAIL("LinkedList PeekLast case2");
        }
        break;
    }
    
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->takeFirst();
        
        auto v1 = mList->peekLast();
        if(v1 != nullptr) {
            TEST_FAIL("LinkedList PeekLast case3");
        }
        break;
    }

    TEST_OK("LinkedList PeekLast case100");

}
