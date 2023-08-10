#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_RemoveAt() {
    while(1) {
      ConcurrentQueue<String> list = createConcurrentQueue<String>();
      list->add(createString("a"));
      list->add(createString("b"));
      list->add(createString("c"));

      String v = list->removeAt(2);
      if(v != "b") {
        TEST_FAIL("ConcurrentQueue RemoveAt test1");
        break;
      }
      ArrayList<String> ll = list->toArray();
      if(ll->size() != 2 || !ll->get(0)->sameAs("a")
          || !ll->get(1)->sameAs("c")) {
            TEST_FAIL("ConcurrentQueue RemoveAt test1_1");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->add(1);
      list->add(2);
      list->add(3);
      int value = list->removeAt(1);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 2 || ll->get(0)!= 1
          || ll->get(1) != 3) {
            TEST_FAIL("ConcurrentQueue RemoveAt test2");
            break;
      }

      if(value != 2) {
        TEST_FAIL("ConcurrentQueue RemoveAt test2_1");
        break;
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->add(1);
      list->add(2);
      list->add(3);
      int value = list->removeAt(0);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 2 || ll->get(0)!= 2
          || ll->get(1) != 3) {
            TEST_FAIL("ConcurrentQueue RemoveAt test3_1");
            break;
      }

      if(value != 1) {
        TEST_FAIL("ConcurrentQueue RemoveAt test3");
        break;
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->add(1);
      list->add(2);
      list->add(3);

      bool isException = false;
      try {
        int index = list->removeAt(5);
      }catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("ConcurrentQueue RemoveAt test4");
        break;
      }

      ArrayList<int> ll = list->toArray();
      if(ll->size() != 3 || ll->get(0)!= 1
          || ll->get(1) != 2
          || ll->get(2) != 3) {
            TEST_FAIL("ConcurrentQueue RemoveAt test4");
            break;
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      list->add(1);
      list->add(2);
      list->add(3);
      int index = list->remove(3);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 2 || ll->get(0)!= 1
          || ll->get(1) != 2) {
            TEST_FAIL("ConcurrentQueue Remove test5");
            break;
      }

      if(index != 2) {
        TEST_FAIL("ConcurrentQueue Remove test6");
        break;
      }
      break;
    }

    TEST_OK("ConcurrentQueue RemoveAt test100");
}
