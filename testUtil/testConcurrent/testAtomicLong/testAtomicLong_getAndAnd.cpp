#include <stdio.h>
#include <unistd.h>

#include "AtomicLong.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicLong value = createAtomicLong(7);
      long v = value->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicLong testGetAndAnd test2");
        break;
      }

      if(value->get() != 2) {
        TEST_FAIL("AtomicLong testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicLong testGetAndAnd test100");
}
