#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueuePeekFirst() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->peekFirst();
        if(v == nullptr || !v->sameAs("a")) {
          TEST_FAIL("BlockingQueue PeekFirst test1");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingQueue PeekFirst test2");
          break;
        }
        break;
    }

    while(1) {
      BlockingQueue<String> list = BlockingQueue<String>::New(3);

      String v = list->peekFirst();
      if(v != nullptr) {
        TEST_FAIL("BlockingQueue PeekFirst test3");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingQueue PeekFirst test4");
        break;
      }
      break;
    }

    TEST_OK("BlockingQueue PeekFirst test100");
}
