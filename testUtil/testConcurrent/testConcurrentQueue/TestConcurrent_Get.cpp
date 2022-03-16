#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_Get() {
    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      bool isException = false;
      try {
        list->get(10);
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("ConcurrentQueue get test2");
        break;
      }
      break;
    }

    TEST_OK("ConcurrentQueue get test100");
}
