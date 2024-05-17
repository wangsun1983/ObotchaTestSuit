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
#include "ConcurrentLinkedList.hpp"
#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList() {
    while(1) {
      ConcurrentLinkedList<int> list = ConcurrentLinkedList<int>::New();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->putLast(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne ConcurrentLinkedList case1");
      }

      break;
    }

    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      list->putLast(String::New("a"));
      list->putLast(String::New("b"));
      list->putLast(String::New("c"));
      list->putLast(String::New("d"));
      list->putLast(String::New("e"));
      list->putLast(String::New("f"));

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(!abc->sameAs("abcdef")) {
        TEST_FAIL("ForEveryOne ConcurrentLinkedList case2");
      }

      break;
    }

    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne ConcurrentLinkedList case3");
      }
      break;
    }

    while(1) {
      ConcurrentLinkedList<int> list = ConcurrentLinkedList<int>::New();
      list->putLast(1);
      list->putLast(2);
      Thread t1 = Thread::New([&]{
        ForEveryOne(v,list) {
          sleep(1);
        }
      });

      Thread t2 = Thread::New([&]{
        sleep(1);
        TimeWatcher watcher = TimeWatcher::New();
        watcher->start();
        list->putLast(2);
        auto result = watcher->stop();
        if(result > 1005 || result < 995) {
          TEST_FAIL("ForEveryOne ConcurrentLinkedQueue case4,result is %ld",result);
        }
      });
      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ForEveryOne ConcurrentLinkedList case100");
}
