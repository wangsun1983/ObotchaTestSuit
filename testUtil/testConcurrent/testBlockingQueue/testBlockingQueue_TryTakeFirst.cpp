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

void testBlockingQueueTryTakeFirst() {
    TimeWatcher watcher = TimeWatcher::New();

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        String v = list->tryTakeFirst();
        if(v != nullptr) {
          TEST_FAIL("BlockingQueue tryTakeFirst test1");
          break;
        }

        break;
    }
#if 0
    while(1) {
      BlockingQueue<int> list = BlockingQueue<int>::New();
      bool isException = false;
      try {
        int v = list->tryTakeFirst();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("BlockingQueue tryTakeFirst test2");
        break;
      }
      break;
    }
#endif
    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        String v1 = list->tryTakeFirst();
        String v2 = list->tryTakeFirst();
        String v3 = list->tryTakeFirst();
        if(v1 == nullptr) {
          TEST_FAIL("BlockingQueue tryTakeFirst test3_1");
          break;
        }

        if(v2 == nullptr) {
          TEST_FAIL("BlockingQueue tryTakeFirst test3_2");
          break;
        }

        if(v3 != nullptr) {
          TEST_FAIL("BlockingQueue tryTakeFirst test3_3");
          break;
        }

        if(!v1->sameAs("a") || !v2->sameAs("b")) {
          TEST_FAIL("BlockingQueue tryTakeFirst test4");
          break;
        }

        break;
    }

    TEST_OK("BlockingQueue tryTakeFirst test100");
}
