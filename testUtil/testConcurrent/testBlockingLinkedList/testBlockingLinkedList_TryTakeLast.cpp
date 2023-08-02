#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListTryTakeLast() {
    TimeWatcher watcher = createTimeWatcher();

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        String v = list->tryTakeLast();
        if(v != nullptr) {
          TEST_FAIL("BlockingLinkedList tryTakeLast test1 \n");
          break;
        }

        break;
    }

    while(1) {
      BlockingLinkedList<int> list = createBlockingLinkedList<int>();
      bool isException = false;
      try {
        int v = list->tryTakeLast();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("BlockingLinkedList tryTakeLast test2 \n");
        break;
      }
      break;
    }

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));

        String v1 = list->tryTakeLast();
        String v2 = list->tryTakeLast();
        String v3 = list->tryTakeLast();
        if(v1 == nullptr || v2 == nullptr || v3 != nullptr) {
          TEST_FAIL("BlockingLinkedList tryTakeLast test3 \n");
          break;
        }

        if(!v1->sameAs("b") || !v2->sameAs("a")) {
          TEST_FAIL("BlockingLinkedList tryTakeLast test4 \n");
          break;
        }

        break;
    }

    TEST_OK("BlockingLinkedList tryTakeLast test100");
}
