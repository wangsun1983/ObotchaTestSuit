#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkedListRemoveAt() {

    //case1 string putLast
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        auto str1 = mList->removeAt(1);
        if(!str1->sameAs("b")) {
          TEST_FAIL("LinkedList RemoveAt test1");
          break;
        }

        auto str2 = mList->removeAt(1);
        if(!str2->sameAs("c")) {
          TEST_FAIL("LinkedList RemoveAt test2");
          break;
        }

        auto str3 = mList->removeAt(0);
        if(!str3->sameAs("a")) {
          TEST_FAIL("LinkedList RemoveAt test3");
          break;
        }

        break;
    }

    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        auto str1 = mList->removeAt(0);
        if(!str1->sameAs("a")) {
          TEST_FAIL("LinkedList RemoveAt test4");
          break;
        }

        auto str2 = mList->removeAt(0);
        if(!str2->sameAs("b")) {
          TEST_FAIL("LinkedList RemoveAt test5");
          break;
        }

        auto str3 = mList->removeAt(0);
        if(!str3->sameAs("c")) {
          TEST_FAIL("LinkedList RemoveAt test6");
          break;
        }

        break;
    }

    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        String v = mList->removeAt(5);
        if(v != nullptr) {
          TEST_FAIL("LinkedList RemoveAt test7");
          break;
        }

        break;
    }

    TEST_OK("LinkedList RemoveAt test100");

}
