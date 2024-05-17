#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_ToArray() {
    while(1) {
      ConcurrentQueue<String> list = ConcurrentQueue<String>::New();
      list->add(String::New("a"));
      list->add(String::New("b"));
      list->add(String::New("c"));
      ArrayList<String> ll = list->toArray();
      if(ll->size() != 3 || !ll->get(0)->sameAs("a")
          || !ll->get(1)->sameAs("b")
          || !ll->get(2)->sameAs("c")) {
            TEST_FAIL("ConcurrentQueue toArray test1");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      list->add(1);
      list->add(2);
      list->add(3);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 3 || ll->get(0) != 1
          || ll->get(1) != 2
          || ll->get(2) != 3) {
            TEST_FAIL("ConcurrentQueue toArray test2");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 0) {
            TEST_FAIL("ConcurrentQueue toArray test3");
            break;
          }
      break;
    }

    TEST_OK("ConcurrentQueue toArray test100");
}
