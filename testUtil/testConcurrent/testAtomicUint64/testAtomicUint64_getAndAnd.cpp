#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicUint64 value = createAtomicUint64(7);
      long v = value->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicUint64 testGetAndAnd test2");
        break;
      }

      if(value->get() != 2) {
        TEST_FAIL("AtomicUint64 testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint64 testGetAndAnd test100");
}
