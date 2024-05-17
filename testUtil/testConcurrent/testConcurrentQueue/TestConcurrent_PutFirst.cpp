#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_PutFirst() {
    while(1) {
      ConcurrentQueue<String> list = ConcurrentQueue<String>::New();
      list->putFirst(String::New("a"));
      list->putFirst(String::New("b"));
      list->putFirst(String::New("c"));
      ArrayList<String> ll = list->toArray();
      if(ll->size() != 3 || !ll->get(0)->sameAs("c")
          || !ll->get(1)->sameAs("b")
          || !ll->get(2)->sameAs("a")) {
            TEST_FAIL("ConcurrentQueue putFirst test1");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      list->putFirst(1);
      list->putFirst(2);
      list->putFirst(3);
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 3 || ll->get(0) != 3
          || ll->get(1) != 2
          || ll->get(2) != 1) {
            TEST_FAIL("ConcurrentQueue putFirst test2");
            break;
          }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
      ArrayList<int> ll = list->toArray();
      if(ll->size() != 0) {
            TEST_FAIL("ConcurrentQueue putFirst test3");
            break;
          }
      break;
    }

    TEST_OK("ConcurrentQueue putFirst test100");
}
