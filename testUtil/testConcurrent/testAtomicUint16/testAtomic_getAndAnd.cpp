#include <stdio.h>
#include <unistd.h>

#include "AtomicUint16.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicUint16 value = createAtomicUint16(7);
      long v = value->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicUint16 testGetAndAnd test2");
        break;
      }

      if(value->get() != 2) {
        TEST_FAIL("AtomicUint16 testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint16 testGetAndAnd test100");
}
