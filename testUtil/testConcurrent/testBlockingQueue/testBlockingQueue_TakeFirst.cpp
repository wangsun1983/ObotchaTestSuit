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

void testBlockingQueueTakeFirst() {
    TimeWatcher watcher = createTimeWatcher();

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        String v = list->takeFirst();
        if(v == nullptr || !v->equals("a")) {
          TEST_FAIL("BlockingQueue takeFirst test1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingQueue takeFirst test2");
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
      String v = list->takeFirst();
      long interval = watcher->stop();
      if(v == nullptr || !v->equals("a")) {
        TEST_FAIL("BlockingQueue takeFirst test3");
        break;
      }

      if(interval < 100 || interval > 105) {
        TEST_FAIL("BlockingQueue takeFirst test4");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingQueue takeFirst test5");
        break;
      }
      break;
    }

    TEST_OK("BlockingQueue takeFirst test100");
}
