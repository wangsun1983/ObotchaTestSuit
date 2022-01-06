#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_MultiThread_Case1() {
    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      ArrayList<Thread> threads = createArrayList<Thread>();

      //get result
      long result = 0;
      for(int i = 1;i<1024*32;i++) {
        result += i;
      }

      for(int j = 0;j<16;j++) {
        Thread t = createThread([&list] {
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
        int v = list->takeFirst();
        if(v == -1) {
          finishCount++;
          continue;
        }
        sum += v;
      }

      if(sum != 16*result) {
        TEST_FAIL("ConcurrentQueue MultiThread Case1 test1");
      }
      break;
    }

    TEST_OK("ConcurrentQueue MultiThread Case1 test100");
}
