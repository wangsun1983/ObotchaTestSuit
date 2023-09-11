#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"
#include "String.hpp"
using namespace obotcha;

void testTakeFirst() {

    //case1
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        if(mList->size() != 3) {
            TEST_FAIL("LinkedList Dequeue First test1");
            break;
        }

        String v1 = mList->takeFirst();
        String v2 = mList->takeFirst();
        String v3 = mList->takeFirst();

        if(!v1->sameAs("a") ||!v2->sameAs("b") ||!v3->sameAs("c")) {
            TEST_FAIL("LinkedList Dequeue First test2,v1 is %s ,v2 is %s,v3 is %s ",v1->toChars(),v2->toChars(),v3->toChars());
            
            break;
        }

        if(mList->takeFirst() != nullptr) {
            TEST_FAIL("LinkedList Dequeue First test3");
            break;
        }

        TEST_OK("LinkedList Dequeue First test4");
        break;
    }

    //case2
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();

        mList->putLast(createString("a"));
        if(mList->size() != 1) {
            TEST_FAIL("LinkedList Dequeue First test5");
            break;
        }

        String v1 = mList->takeFirst();
        if(!v1->sameAs("a")) {
            TEST_FAIL("LinkedList Dequeue First test6,v1 is %s ",v1->toChars());
            
            break;
        }

        if(mList->takeFirst() != nullptr) {
            TEST_FAIL("LinkedList Dequeue First test7");
            break;
        }

        TEST_OK("LinkedList Enqueue Last test8");
        break;
    }

}
