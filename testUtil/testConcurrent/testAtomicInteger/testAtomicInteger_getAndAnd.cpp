#include <stdio.h>
#include <unistd.h>

#include "AtomicInteger.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicInteger integer = createAtomicInteger(7);
      int v = integer->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicInteger testGetAndAnd test2");
        break;
      }

      if(integer->get() != 2) {
        TEST_FAIL("AtomicInteger testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger testGetAndAnd test100");
}
