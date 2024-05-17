#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListPeekLast() {

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->peekLast();
        if(v == nullptr || !v->sameAs("c")) {
          TEST_FAIL("BlockingLinkedList PeekLast test1 \n");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingLinkedList PeekLast test2 \n");
          break;
        }
        break;
    }

    while(1) {
      BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);

      String v = list->peekLast();
      if(v != nullptr) {
        TEST_FAIL("BlockingLinkedList PeekLast test3 \n");
        break;
      }

      if(list->size() != 0) {
        TEST_FAIL("BlockingLinkedList PeekLast test4 \n");
        break;
      }
      break;
    }

    TEST_OK("BlockingLinkedList PeekLast test100");
}
