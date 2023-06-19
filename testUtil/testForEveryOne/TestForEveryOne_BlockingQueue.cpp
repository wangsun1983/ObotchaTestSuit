#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "BlockingQueue.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testBlockingQueue() {
    while(1) {
      BlockingQueue<int> list = createBlockingQueue<int>();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->putFirst(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne BlockingQueue case1");
      }

      break;
    }

    while(1) {
      BlockingQueue<String> list = createBlockingQueue<String>();
      list->putFirst(createString("a"));
      list->putFirst(createString("b"));
      list->putFirst(createString("c"));
      list->putFirst(createString("d"));
      list->putFirst(createString("e"));
      list->putFirst(createString("f"));

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(!abc->equals("fedcba")) {
        TEST_FAIL("ForEveryOne BlockingQueue case2,abc is %s",abc->toChars());
      }

      break;
    }

    while(1) {
      BlockingQueue<String> list = createBlockingQueue<String>();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne BlockingQueue case3");
      }
      break;
    }


    while(1) {
      BlockingQueue<String> list = createBlockingQueue<String>();
      list->put(createString("a"));
      list->put(createString("b"));
      Thread t1 = createThread([&]{
        ForEveryOne(v,list) {
          sleep(1);
        }
      });

      Thread t2 = createThread([&]{
        sleep(1);
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        list->put(createString("c"));
        auto result = watcher->stop();
        if(result > 1005 || result < 995) {
          TEST_FAIL("ForEveryOne BlockingQueue case4,result is %ld",result);
        }
      });
      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ForEveryOne BlockingQueue case100");
}
