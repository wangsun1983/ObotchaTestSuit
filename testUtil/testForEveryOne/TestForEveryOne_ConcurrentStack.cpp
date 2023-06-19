#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "ConcurrentStack.hpp"
#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentStack() {
    while(1) {
      ConcurrentStack<int> list = createConcurrentStack<int>();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->push(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne ConcurrentStack case1");
      }

      break;
    }

    while(1) {
      ConcurrentStack<String> list = createConcurrentStack<String>();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne ConcurrentStack case3");
      }
      break;
    }

    while(1) {
      ConcurrentStack<int> list = createConcurrentStack<int>();
      list->push(1);
      list->push(2);
      Thread t1 = createThread([&]{
        ForEveryOne(v,list) {
          sleep(1);
        }
      });

      Thread t2 = createThread([&]{
        sleep(1);
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        list->push(2);
        auto result = watcher->stop();
        if(result > 1005 || result < 995) {
          TEST_FAIL("ForEveryOne ConcurrentStack case4,result is %ld",result);
        }
      });
      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ForEveryOne ConcurrentStack case100");
}
