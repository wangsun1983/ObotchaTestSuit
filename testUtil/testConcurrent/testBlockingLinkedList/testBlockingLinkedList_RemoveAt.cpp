#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListRemoveAt() {

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->removeAt(1);
        if(v == nullptr || !v->sameAs("b")) {
          TEST_FAIL("BlockingLinkedList removeAt test1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingLinkedList removeAt test2");
          break;
        }
        break;
    }

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        bool isException = false;
        try {
          String v = list->removeAt(1);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingLinkedList removeAt test3");
          break;
        }

        break;
    }

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        bool isException = false;
        try {
          String v = list->removeAt(0);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingLinkedList removeAt test4");
          break;
        }

        break;
    }

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        list->put(String::New("a"));
        bool isException = false;
        try {
          String v = list->removeAt(2);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingLinkedList removeAt test5");
          break;
        }

        break;
    }

    TEST_OK("BlockingLinkedList removeAt test100");
}
