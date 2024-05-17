#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueTryPutFirst() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        bool result = list->tryPutFirst(String::New("d"));
        if(result) {
          TEST_FAIL("BlockingQueue TryPutFirst test1");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingQueue TryPutFirst test1_1");
          break;
        }
        break;
    }

    while(1) {
      BlockingQueue<String> list = BlockingQueue<String>::New(3);
      list->tryPutFirst(String::New("a"));
      list->tryPutFirst(String::New("b"));
      list->tryPutFirst(String::New("c"));

      ArrayList<String> result = ArrayList<String>::New();
      result->add(String::New("c"));
      result->add(String::New("b"));
      result->add(String::New("a"));
      auto iterator = result->getIterator();
      while(iterator->hasValue()) {
        auto v = iterator->getValue();
        auto v2 = list->takeFirst();
        if(!v->equals(v2)) {
          TEST_FAIL("BlockingQueue TryPutFirst test2");
          break;
        }
        iterator->next();
      }
      break;
    }

    TEST_OK("BlockingQueue TryPutFirst test100");
}
