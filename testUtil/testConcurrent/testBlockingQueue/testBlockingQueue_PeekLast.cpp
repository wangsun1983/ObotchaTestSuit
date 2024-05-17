#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueuePeekLast() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->peekLast();
        if(v == nullptr || !v->sameAs("c")) {
          TEST_FAIL("BlockingQueue PeekLast test1");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingQueue PeekLast test2");
          break;
        }
        break;
    }

    while(1) {
      BlockingQueue<String> list = BlockingQueue<String>::New(3);

      String v = list->peekLast();
      if(v != nullptr) {
        TEST_FAIL("BlockingQueue PeekLast test3");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingQueue PeekLast test4");
        break;
      }
      break;
    }

    TEST_OK("BlockingQueue PeekLast test100");
}
