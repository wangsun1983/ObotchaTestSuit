#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_Remove() {
    while(1) {
      ConcurrentQueue<String> list = ConcurrentQueue<String>::New();
      list->add(String::New("a"));
      list->add(String::New("b"));
      list->add(String::New("c"));

      int index = list->remove(String::New("b"));
      if(index != 1) {
        TEST_FAIL("ConcurrentQueue Remove test1");
        break;
      }
      ArrayList<String> ll = list->toArray();
      if(ll->size() != 2 || !ll->get(0)->sameAs("a")
          || !ll->get(1)->sameAs("c")) {
            TEST_FAIL("ConcurrentQueue Remove test1_1");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      list->add(1);
      list->add(2);
      list->add(3);
      int index = list->remove(2);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 2 || ll->get(0)!= 1
          || ll->get(1) != 3) {
            TEST_FAIL("ConcurrentQueue Remove test2");
            break;
      }

      if(index != 1) {
        TEST_FAIL("ConcurrentQueue Remove test2_1");
        break;
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      list->add(1);
      list->add(2);
      list->add(3);
      int index = list->remove(1);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 2 || ll->get(0)!= 2
          || ll->get(1) != 3) {
            TEST_FAIL("ConcurrentQueue Remove test3_1");
            break;
      }

      if(index != 0) {
        TEST_FAIL("ConcurrentQueue Remove test3");
        break;
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      list->add(1);
      list->add(2);
      list->add(3);
      int index = list->remove(5);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 3 || ll->get(0)!= 1
          || ll->get(1) != 2
          || ll->get(2) != 3) {
            TEST_FAIL("ConcurrentQueue Remove test4");
            break;
      }

      if(index != -1) {
        TEST_FAIL("ConcurrentQueue Remove test4");
        break;
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
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

    TEST_OK("ConcurrentQueue Remove test100");
}
