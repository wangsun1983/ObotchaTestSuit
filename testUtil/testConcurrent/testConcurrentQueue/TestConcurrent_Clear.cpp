#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_Clear() {
    while(1) {
      ConcurrentQueue<String> list = ConcurrentQueue<String>::New();
      list->add(String::New("a"));
      list->add(String::New("b"));
      list->add(String::New("c"));
      if(list->size() != 3) {
        TEST_FAIL("ConcurrentQueue clear test1");
        break;
      }

      list->clear();
      if(list->size() != 0) {
        TEST_FAIL("ConcurrentQueue clear test2");
        break;
      }
      break;
    }
    TEST_OK("ConcurrentQueue clear test100");
}
