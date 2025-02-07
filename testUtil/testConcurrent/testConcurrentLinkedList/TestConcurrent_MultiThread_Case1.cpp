#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentLinkedList_MultiThread_Case1() {
    while(1) {
      ConcurrentLinkedList<int> list = ConcurrentLinkedList<int>::New();
      ArrayList<Thread> threads = ArrayList<Thread>::New();

      //get result
      long result = 0;
      for(int i = 1;i<1024*32;i++) {
        result += i;
      }

      for(int j = 0;j<16;j++) {
        Thread t = Thread::New([&list] {
          for(int i = 1;i<1024*32;i++) {
            list->putLast(i);
          }
          list->putLast(-1);
        });
        t->start();
        threads->add(t);
      }

      long sum = 0;
      int finishCount = 0;
      while(finishCount != 16) {
        try {
          int v = list->takeFirst();
          if(v == -1) {
            finishCount++;
            continue;
          }
          sum += v;
        } catch(...) {}
      }

      if(sum != 16*result) {
        TEST_FAIL("ConcurrentLinkedList MultiThread Case1 test1");
      }
      break;
    }

    TEST_OK("ConcurrentLinkedList MultiThread Case1 test100");
}
