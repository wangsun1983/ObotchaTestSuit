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
    TimeWatcher watcher = TimeWatcher::New();

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->takeLast();
        if(v == nullptr || !v->sameAs("c")) {
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
      BlockingQueue<String> list = BlockingQueue<String>::New(3);
      Thread t = Thread::New([&list] {
        usleep(100*1000);
        list->put(String::New("a"));
      });
      t->start();

      watcher->start();
      String v = list->takeLast();
      long interval = watcher->stop();
      if(v == nullptr || !v->sameAs("a")) {
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
