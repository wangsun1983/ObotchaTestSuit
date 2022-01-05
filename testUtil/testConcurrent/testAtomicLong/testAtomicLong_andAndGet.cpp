#include <stdio.h>
#include <unistd.h>

#include "AtomicLong.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAndAndGet() {
    while(1) {
      AtomicLong Long = createAtomicLong(3);
      long v = Long->andAndGet(2);
      if(v != 2) {
        TEST_FAIL("AtomicLong testAndAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicLong testAndAndGet test100");
}
