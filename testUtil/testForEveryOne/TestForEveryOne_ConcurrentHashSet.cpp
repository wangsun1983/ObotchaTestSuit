#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ConcurrentHashSet.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "ConcurrentHashSet.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet() {
    while(1) {
      ConcurrentHashSet<int> list = ConcurrentHashSet<int>::New();
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
        TEST_FAIL("ForEveryOne ConcurrentHashSet case1");
      }

      break;
    }

    while(1) {
      ConcurrentHashSet<String> list = ConcurrentHashSet<String>::New();
      list->add(String::New("a"));
      list->add(String::New("b"));
      list->add(String::New("c"));
      list->add(String::New("d"));
      list->add(String::New("e"));
      list->add(String::New("f"));

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(abc->size() != 6) {
          TEST_FAIL("ForEveryOne ConcurrentHashSet case2");
      }
      
      if(!abc->contains("a") || !abc->contains("b") ||
        !abc->contains("c") || !abc->contains("d") ||
        !abc->contains("e") || !abc->contains("f")) {
        TEST_FAIL("ForEveryOne ConcurrentHashSet case3");
      }
      break;
    }

    while(1) {
      ConcurrentHashSet<String> list = ConcurrentHashSet<String>::New();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne ConcurrentHashSet case3");
      }
      break;
    }

    while(1) {
      ConcurrentHashSet<int> list = ConcurrentHashSet<int>::New();
      list->add(1);
      list->add(2);
      Thread t1 = Thread::New([&]{
        ForEveryOne(v,list) {
          sleep(1);
        }
      });

      Thread t2 = Thread::New([&]{
        sleep(1);
        TimeWatcher watcher = TimeWatcher::New();
        watcher->start();
        list->add(2);
        auto result = watcher->stop();
        if(result > 1005 || result < 995) {
          TEST_FAIL("ForEveryOne ConcurrentHashSet case4,result is %ld",result);
        }
      });
      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ForEveryOne ConcurrentHashSet case100");
}
