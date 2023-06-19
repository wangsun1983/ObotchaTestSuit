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
#include "ConcurrentHashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashMap() {
    while(1) {
      ConcurrentHashMap<int,String> map = createConcurrentHashMap<int,String>();
      int sum = 0;
      for(int i = 0; i < 10;i++) {
        map->put(i,createString(i));
        sum += i;
      }

      int sum2 = 0;
      String s = "";
      ForEveryOne(pair,map) {
        sum2 += pair->getKey();
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne ConcurrentHashMap case1");
      }

      break;
    }

    while(1) {
      ConcurrentHashMap<int,String> map = createConcurrentHashMap<int,String>();
      int count = 0;
      ForEveryOne(pair,map) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne ConcurrentHashMap case3");
      }
      break;
    }

    while(1) {
      ConcurrentHashMap<int,String> list = createConcurrentHashMap<int,String>();
      list->put(1,createString("a"));
      list->put(2,createString("b"));
      Thread t1 = createThread([&]{
        ForEveryOne(v,list) {
          sleep(1);
        }
      });

      Thread t2 = createThread([&]{
        sleep(1);
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        list->put(3,createString("c"));
        auto result = watcher->stop();
        if(result > 1005 || result < 995) {
          TEST_FAIL("ForEveryOne ConcurrentHashMap case4,result is %ld",result);
        }
      });
      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }


    TEST_OK("ForEveryOne ConcurrentHashMap case100");
}
