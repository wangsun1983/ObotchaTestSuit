#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ConcurrentQueue.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "ConcurrentQueue.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentQueue() {
    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->add(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne ConcurrentQueue case1");
      }

      break;
    }

    while(1) {
      ConcurrentQueue<String> list = createConcurrentQueue<String>();
      list->add(createString("a"));
      list->add(createString("b"));
      list->add(createString("c"));
      list->add(createString("d"));
      list->add(createString("e"));
      list->add(createString("f"));

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(!abc->sameAs("abcdef")) {
        TEST_FAIL("ForEveryOne ConcurrentQueue case2");
      }

      break;
    }

    while(1) {
      ConcurrentQueue<String> list = createConcurrentQueue<String>();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne ConcurrentQueue case3");
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->add(1);
      list->add(2);
      Thread t1 = createThread([&]{
        ForEveryOne(v,list) {
          sleep(1);
        }
      });

      Thread t2 = createThread([&]{
        sleep(1);
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        list->add(2);
        auto result = watcher->stop();
        if(result > 1005 || result < 995) {
          TEST_FAIL("ForEveryOne ConcurrentQueue case4,result is %ld",result);
        }
      });
      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ForEveryOne ConcurrentQueue case100");
}
