#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueTryPutLast() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        bool result = list->tryPutLast(String::New("d"));
        if(result) {
          TEST_FAIL("BlockingQueue tryPutLast test1");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingQueue tryPutLast test1_1");
          break;
        }
        break;
    }

    while(1) {
      BlockingQueue<String> list = BlockingQueue<String>::New(3);
      list->tryPutLast(String::New("a"));
      list->tryPutLast(String::New("b"));
      list->tryPutLast(String::New("c"));
      list->tryPutLast(String::New("d"));
      if(list->size() != 3) {
        TEST_FAIL("BlockingQueue tryPutLast test2");
        break;
      }

      ArrayList<String> result = ArrayList<String>::New();
      result->add(String::New("a"));
      result->add(String::New("b"));
      result->add(String::New("c"));
      auto iterator = result->getIterator();
      while(iterator->hasValue()) {
        auto v = iterator->getValue();
        auto v2 = list->takeFirst();
        if(!v->equals(v2)) {
          TEST_FAIL("BlockingQueue tryPutLast test3");
          break;
        }
        iterator->next();
      }

      list->tryPutLast(String::New("a"));
      list->tryPutLast(String::New("b"));
      list->tryPutLast(String::New("c"));
      list->tryPutLast(String::New("d"));
      list->takeFirst();
      list->putLast(String::New("e"));
      ArrayList<String> ll2 = list->toArray();
      if(ll2->size() != 3 || !ll2->get(0)->sameAs("b")|| !ll2->get(1)->sameAs("c")|| !ll2->get(2)->sameAs("e")) {
        TEST_FAIL("BlockingQueue tryPutLast test4");
        break;
      }
      break;
    }

    TEST_OK("BlockingQueue tryPutLast test100");
}
