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

void testBlockingQueueTakeLast() {
    TimeWatcher watcher = createTimeWatcher();

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        String v = list->takeLast();
        if(v == nullptr || !v->equals("c")) {
          TEST_FAIL("BlockingQueue TakeLast test1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingQueue TakeLast test2");
          break;
        }
        break;
    }

    while(1) {
      BlockingQueue<String> list = createBlockingQueue<String>(3);
      Thread t = createThread([&list] {
        usleep(100*1000);
        list->put(createString("a"));
      });
      t->start();

      watcher->start();
      String v = list->takeLast();
      long interval = watcher->stop();
      if(v == nullptr || !v->equals("a")) {
        TEST_FAIL("BlockingQueue TakeLast test3");
        break;
      }

      if(interval < 100 || interval > 105) {
        TEST_FAIL("BlockingQueue TakeLast test4");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingQueue TakeLast test5");
        break;
      }
      break;
    }

    TEST_OK("BlockingQueue TakeLast test100");
}
