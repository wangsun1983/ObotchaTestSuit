#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_PutLast() {
    while(1) {
      ConcurrentQueue<String> list = createConcurrentQueue<String>();
      list->putLast(createString("a"));
      list->putLast(createString("b"));
      list->putLast(createString("c"));
      ArrayList<String> ll = list->toArray();
      if(ll->size() != 3 || !ll->get(0)->sameAs("a")
          || !ll->get(1)->sameAs("b")
          || !ll->get(2)->sameAs("c")) {
            TEST_FAIL("ConcurrentQueue putLast test1");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->putLast(1);
      list->putLast(2);
      list->putLast(3);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 3 || ll->get(0) != 1
          || ll->get(1) != 2
          || ll->get(2) != 3) {
            TEST_FAIL("ConcurrentQueue putLast test2");
            break;
          }
      break;
    }

    TEST_OK("ConcurrentQueue putLast test100");
}
