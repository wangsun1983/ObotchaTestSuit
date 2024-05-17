#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentLinkedList_MultiThread_Case2() {
    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      ArrayList<Thread> threads = ArrayList<Thread>::New();

      //get result
      long result = 0;
      for(int i = 1;i<1024;i++) {
        result += i;
      }

      for(int j = 0;j<4;j++) {
        Thread t = Thread::New([&list] {
          for(int i = 1;i<1024;i++) {
            list->putLast(String::New(i));
          }
          list->putLast(String::New(-1));
        });
        t->start();
        threads->add(t);
      }

      long sum = 0;
      int finishCount = 0;
      while(finishCount != 4) {
        try {
          String str = list->takeFirst();
          int v = str->toBasicInt();
          if(v == -1) {
            finishCount++;
            continue;
          }
          sum += v;
        } catch(...) {
        }
      }

      if(sum != 4*result) {
        TEST_FAIL("ConcurrentLinkedList MultiThread Case2 test1");
      }
      break;
    }

    TEST_OK("ConcurrentLinkedList MultiThread Case2 test100");
}
