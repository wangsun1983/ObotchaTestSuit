#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_Size() {
    while(1) {
      ConcurrentQueue<int> queue = createConcurrentQueue<int>();
      if(queue->size() != 0) {
          TEST_FAIL("ConcurrentQueue size test1");
          break;
      }

      queue->putFirst(1);
      if(queue->size() != 1) {
          TEST_FAIL("ConcurrentQueue size test2");
          break;
      }

      ConcurrentQueue<int> queue2 = createConcurrentQueue<int>();
      for(int i = 0;i < 1024;i++) {
        queue2->putLast(i);
      }
      if(queue2->size() != 1024) {
        TEST_FAIL("ConcurrentQueue size test3");
        break;
      }

      break;
    }

    while(1) {
      ConcurrentQueue<String> queue = createConcurrentQueue<String>();
      if(queue->size() != 0) {
          TEST_FAIL("ConcurrentQueue size test4");
          break;
      }

      queue->putFirst(createString("a"));
      if(queue->size() != 1) {
          TEST_FAIL("ConcurrentQueue size test5");
          break;
      }

      ConcurrentQueue<String> queue2 = createConcurrentQueue<String>();
      for(int i = 0;i < 1024;i++) {
        queue2->putLast(createString(i));
      }

      if(queue2->size() != 1024) {
        TEST_FAIL("ConcurrentQueue size test6");
        break;
      }

      break;
    }
    TEST_OK("ConcurrentQueue size test100");
}
