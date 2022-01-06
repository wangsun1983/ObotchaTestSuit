#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_TakeFirst() {
    while(1) {
      ConcurrentQueue<String> list = createConcurrentQueue<String>();
      list->add(createString("a"));
      list->add(createString("b"));
      list->add(createString("c"));
      ArrayList<String> ll = list->toArray();
      for(int i = 0;i < 3;i++) {
        auto v = list->takeFirst();
        if(v != ll->get(i)) {
          TEST_FAIL("ConcurrentQueue takeFirst test1");
          break;
        }
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->add(1);
      list->add(2);
      list->add(3);
      ArrayList<int> ll = list->toArray();
      for(int i = 0;i < 3;i++) {
        auto v = list->takeFirst();
        if(v != ll->get(i)) {
          TEST_FAIL("ConcurrentQueue takeFirst test100");
          break;
        }
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      bool isException = false;
      try {
        list->takeFirst();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("ConcurrentQueue takeFirst test100");
        break;
      }
      break;
    }

    TEST_OK("ConcurrentQueue takeFirst test100");
}
