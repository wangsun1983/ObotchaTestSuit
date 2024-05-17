#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListPeekFirst() {

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->peekFirst();
        if(v == nullptr || !v->sameAs("a")) {
          TEST_FAIL("BlockingLinkedList PeekFirst test1 \n");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingLinkedList PeekFirst test2 \n");
          break;
        }
        break;
    }

    while(1) {
      BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);

      String v = list->peekFirst();
      if(v != nullptr) {
        TEST_FAIL("BlockingLinkedList PeekFirst test3 \n");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingLinkedList PeekFirst test4 \n");
        break;
      }
      break;
    }

    TEST_OK("BlockingLinkedList PeekFirst test100");
}
