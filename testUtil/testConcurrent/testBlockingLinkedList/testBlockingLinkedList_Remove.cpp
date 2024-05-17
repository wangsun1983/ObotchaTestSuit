#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListRemove() {

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));
        list->remove(String::New("b"));

        if(list->size() != 2) {
          TEST_FAIL("BlockingLinkedList remove test1,size is %d",list->size());
          break;
        }

        ArrayList<String> ll = list->toArray();
        if(ll->size() != 2) {
          TEST_FAIL("BlockingLinkedList remove test2");
          break;
        }

        if(!ll->get(0)->sameAs("a") || !ll->get(1)->sameAs("c")) {
          TEST_FAIL("BlockingLinkedList remove test3");
          break;
        }

        if(list->remove("f") != -1) {
          TEST_FAIL("BlockingLinkedList remove test3_1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingLinkedList remove test3_2");
          break;
        }

        break;
    }

    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
        if(list->remove(String::New("a"))!= -1) {
          TEST_FAIL("BlockingLinkedList remove test4");
          break;
        }

        break;
    }


    TEST_OK("BlockingLinkedList remove test100");
}
