#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testTakeLast() {

    //case1
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        if(mList->size() != 3) {
            TEST_FAIL("LinkedList Dequeue Last test1");
            break;
        }

        String v1 = mList->takeLast();
        String v2 = mList->takeLast();
        String v3 = mList->takeLast();

        if(!v1->sameAs("c") ||!v2->sameAs("b") ||!v3->sameAs("a")) {
            TEST_FAIL("LinkedList Dequeue Last test2,v1 is %s ,v2 is %s,v3 is %s",v1->toChars(),v2->toChars(),v3->toChars());
            break;
        }

        if(mList->takeLast() != nullptr) {
            TEST_FAIL("LinkedList Dequeue Last test3");
            break;
        }

        TEST_OK("LinkedList Dequeue Last test4");
        break;
    }

    //case2
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();

        mList->putLast(createString("a"));
        if(mList->size() != 1) {
            TEST_FAIL("LinkedList Dequeue Last test5");
            break;
        }

        String v1 = mList->takeLast();
        if(!v1->sameAs("a")) {
            TEST_FAIL("LinkedList Dequeue Last test6,v1 is %s ",v1->toChars());
            
            break;
        }

        if(mList->takeLast() != nullptr) {
            TEST_FAIL("LinkedList Dequeue Last test7");
            break;
        }

        TEST_OK("LinkedList Enqueue Last test8");
        break;
    }

}
