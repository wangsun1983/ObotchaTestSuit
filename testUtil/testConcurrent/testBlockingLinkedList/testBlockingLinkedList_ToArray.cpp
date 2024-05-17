#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListToArray() {
    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        ArrayList<String> ll = list->toArray();
        if(ll->size() != 3 || !ll->get(0)->sameAs("a")
        || !ll->get(1)->sameAs("b")
        || !ll->get(2)->sameAs("c")) {
          TEST_FAIL("BlockingLinkedList toArray test1 \n");
          break;
        }

        break;
    }

    while(1) {
        BlockingLinkedList<int> list =BlockingLinkedList<int>::New(3);
        ArrayList<int> ll = list->toArray();
        if(ll->size() != 0) {
          TEST_FAIL("BlockingLinkedList toArray test2 \n");
          break;
        }

        break;
    }

    while(1) {
        BlockingLinkedList<int> list =BlockingLinkedList<int>::New(128);
        for(int i = 0;i<128;i++) {
          list->putLast(i);
        }
        ArrayList<int> ll = list->toArray();
        auto iterator = ll->getIterator();
        int start = 0;
        while(iterator->hasValue()) {
          if(iterator->getValue() != start) {
            TEST_FAIL("BlockingLinkedList toArray test3 \n");
            break;
          }
          start++;
          iterator->next();
        }
        break;
    }

    TEST_OK("BlockingLinkedList destroy test100");
}
