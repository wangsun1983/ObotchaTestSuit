#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkedListRemove() {

    //case1 string putLast
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        int index = mList->remove(createString("b"));
        if(index != 1) {
          TEST_FAIL("LinkedList Remove test1");
          break;
        }

        index = mList->remove(createString("a"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test2");
          break;
        }

        index = mList->remove(createString("c"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test3");
          break;
        }
        break;
    }

    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        int index = mList->remove(createString("a"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test4");
          break;
        }

        index = mList->remove(createString("b"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test5");
          break;
        }

        index = mList->remove(createString("c"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test6");
          break;
        }
        break;
    }

    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        int index = mList->remove(createString("c"));
        if(index != 2) {
          TEST_FAIL("LinkedList Remove test7");
          break;
        }

        index = mList->remove(createString("b"));
        if(index != 1) {
          TEST_FAIL("LinkedList Remove test8");
          break;
        }

        index = mList->remove(createString("a"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test9");
          break;
        }
        break;
    }

    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        int index = mList->remove(createString("d"));
        if(index != -1) {
          TEST_FAIL("LinkedList Remove test1");
          break;
        }
        break;
    }

    TEST_OK("LinkedList Remove test100");

}
