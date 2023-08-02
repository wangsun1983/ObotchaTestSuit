#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListTakeLast() {
    TimeWatcher watcher = createTimeWatcher();

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        String v = list->takeLast();
        if(v == nullptr || !v->sameAs("c")) {
          TEST_FAIL("BlockingLinkedList TakeLast test1 \n");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingLinkedList TakeLast test2 \n");
          break;
        }
        break;
    }

    while(1) {
      BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
      Thread t = createThread([&list] {
        usleep(100*1000);
        list->put(createString("a"));
      });
      t->start();

      watcher->start();
      String v = list->takeLast();
      long interval = watcher->stop();
      if(v == nullptr || !v->sameAs("a")) {
        TEST_FAIL("BlockingLinkedList TakeLast test3 \n");
        break;
      }

      if(interval < 100 || interval > 105) {
        TEST_FAIL("BlockingLinkedList TakeLast test4 \n");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingLinkedList TakeLast test5 \n");
        break;
      }
      break;
    }

    TEST_OK("BlockingLinkedList TakeLast test100");
}
