#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueRemoveAt() {

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        String v = list->removeAt(1);
        if(v == nullptr || !v->equals("b")) {
          TEST_FAIL("BlockingQueue removeAt test1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingQueue removeAt test2");
          break;
        }
        break;
    }

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        bool isException = false;
        try {
          String v = list->removeAt(1);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingQueue removeAt test3");
          break;
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        bool isException = false;
        try {
          String v = list->removeAt(0);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingQueue removeAt test4");
          break;
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->put(createString("a"));
        bool isException = false;
        try {
          String v = list->removeAt(2);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingQueue removeAt test5");
          break;
        }

        break;
    }

    TEST_OK("BlockingQueue removeAt test100");
}
