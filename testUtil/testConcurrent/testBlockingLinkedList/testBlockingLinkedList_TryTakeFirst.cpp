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

void testBlockingLinkedListTryTakeFirst() {
    TimeWatcher watcher = createTimeWatcher();

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        String v = list->tryTakeFirst();
        if(v != nullptr) {
          TEST_FAIL("BlockingLinkedList tryTakeFirst test1 \n");
          break;
        }

        break;
    }

    while(1) {
      BlockingLinkedList<int> list = createBlockingLinkedList<int>();
      bool isException = false;
      try {
        int v = list->tryTakeFirst();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("BlockingLinkedList tryTakeFirst test2 \n");
        break;
      }
      break;
    }

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));

        String v1 = list->tryTakeFirst();
        String v2 = list->tryTakeFirst();
        String v3 = list->tryTakeFirst();
        if(v1 == nullptr || v2 == nullptr || v3 != nullptr) {
          TEST_FAIL("BlockingLinkedList tryTakeFirst test3 \n");
          break;
        }

        if(!v1->sameAs("a") || !v2->sameAs("b")) {
          TEST_FAIL("BlockingLinkedList tryTakeFirst test4 \n");
          break;
        }

        break;
    }

    TEST_OK("BlockingLinkedList tryTakeFirst test100");
}
