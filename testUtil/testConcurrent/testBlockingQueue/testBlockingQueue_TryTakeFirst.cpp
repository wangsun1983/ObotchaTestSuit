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
    TimeWatcher watcher = createTimeWatcher();

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        String v = list->tryTakeFirst();
        if(v != nullptr) {
          TEST_FAIL("BlockingQueue tryTakeFirst test1");
          break;
        }

        break;
    }

    while(1) {
      BlockingQueue<int> list = createBlockingQueue<int>();
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

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));

        String v1 = list->tryTakeFirst();
        String v2 = list->tryTakeFirst();
        String v3 = list->tryTakeFirst();
        if(v1 == nullptr || v2 == nullptr || v3 != nullptr) {
          TEST_FAIL("BlockingQueue tryTakeFirst test3");
          break;
        }

        if(!v1->equals("a") || !v2->equals("b")) {
          TEST_FAIL("BlockingQueue tryTakeFirst test4");
          break;
        }

        break;
    }

    TEST_OK("BlockingQueue tryTakeFirst test100");
}
