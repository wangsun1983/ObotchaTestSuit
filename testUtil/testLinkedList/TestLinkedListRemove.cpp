#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"
#include "String.hpp"
using namespace obotcha;

void testLinkedListRemove() {

    //case1 string putLast
    while(1) {
        LinkedList<String> mList = LinkedList<String>::New();
        mList->putLast(String::New("a"));
        mList->putLast(String::New("b"));
        mList->putLast(String::New("c"));

        int index = mList->remove(String::New("b"));
        if(index != 1) {
          TEST_FAIL("LinkedList Remove test1");
          break;
        }

        index = mList->remove(String::New("a"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test2");
          break;
        }

        index = mList->remove(String::New("c"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test3");
          break;
        }
        break;
    }

    while(1) {
        LinkedList<String> mList = LinkedList<String>::New();
        mList->putLast(String::New("a"));
        mList->putLast(String::New("b"));
        mList->putLast(String::New("c"));

        int index = mList->remove(String::New("a"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test4");
          break;
        }

        index = mList->remove(String::New("b"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test5");
          break;
        }

        index = mList->remove(String::New("c"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test6");
          break;
        }
        break;
    }

    while(1) {
        LinkedList<String> mList = LinkedList<String>::New();
        mList->putLast(String::New("a"));
        mList->putLast(String::New("b"));
        mList->putLast(String::New("c"));

        int index = mList->remove(String::New("c"));
        if(index != 2) {
          TEST_FAIL("LinkedList Remove test7");
          break;
        }

        index = mList->remove(String::New("b"));
        if(index != 1) {
          TEST_FAIL("LinkedList Remove test8");
          break;
        }

        index = mList->remove(String::New("a"));
        if(index != 0) {
          TEST_FAIL("LinkedList Remove test9");
          break;
        }
        break;
    }

    while(1) {
        LinkedList<String> mList = LinkedList<String>::New();
        mList->putLast(String::New("a"));
        mList->putLast(String::New("b"));
        mList->putLast(String::New("c"));

        int index = mList->remove(String::New("d"));
        if(index != -1) {
          TEST_FAIL("LinkedList Remove test1");
          break;
        }
        break;
    }

    TEST_OK("LinkedList Remove test100");

}
