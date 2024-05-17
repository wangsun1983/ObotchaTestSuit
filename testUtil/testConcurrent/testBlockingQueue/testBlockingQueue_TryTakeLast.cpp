#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueTryTakeLast() {
    TimeWatcher watcher = TimeWatcher::New();

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        String v = list->tryTakeLast();
        if(v != nullptr) {
          TEST_FAIL("BlockingQueue tryTakeLast test1");
          break;
        }

        break;
    }
#if 0
    while(1) {
      BlockingQueue<int> list = BlockingQueue<int>::New();
      bool isException = false;
      try {
        int v = list->tryTakeLast();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("BlockingQueue tryTakeLast test2");
        break;
      }
      break;
    }
#endif
    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));

        String v1 = list->tryTakeLast();
        String v2 = list->tryTakeLast();
        String v3 = list->tryTakeLast();
        if(v1 == nullptr || v2 == nullptr || v3 != nullptr) {
          TEST_FAIL("BlockingQueue tryTakeLast test3");
          break;
        }

        if(!v1->sameAs("b") || !v2->sameAs("a")) {
          TEST_FAIL("BlockingQueue tryTakeLast test4");
          break;
        }

        break;
    }

    TEST_OK("BlockingQueue tryTakeLast test100");
}
