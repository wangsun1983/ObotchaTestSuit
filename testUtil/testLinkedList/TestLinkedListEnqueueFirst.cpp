#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPutFirst() {

    //case1
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        std::vector<std::string> list;
        list.push_back("a");
        list.push_back("b");
        list.push_back("c");

        mList->putFirst(createString("a"));
        mList->putFirst(createString("b"));
        mList->putFirst(createString("c"));

        if(mList->size() != 3) {
            TEST_FAIL("LinkedList Enqueue First test1");
            break;
        }

        String v1 = mList->at(0);
        String v2 = mList->at(1);
        String v3 = mList->at(2);

        if(!v1->sameAs("c") ||!v2->sameAs("b") ||!v3->sameAs("a")) {
            TEST_FAIL("LinkedList Enqueue First test2,v1 is %s ,v2 is %s,v3 is %s ",v1->toChars(),v2->toChars(),v3->toChars());
            
            break;
        }
        TEST_OK("LinkedList Enqueue First test3");
        break;
    }

    //case2
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();

        mList->putFirst(createString("a"));
        if(mList->size() != 1) {
            TEST_FAIL("LinkedList Enqueue First test4");
            break;
        }

        String v1 = mList->at(0);
        if(!v1->sameAs("a")) {
            TEST_FAIL("LinkedList Enqueue First test5,v1 is %s ",v1->toChars());
            
            break;
        }
        TEST_OK("LinkedList Enqueue First test6");
        break;
    }




}
