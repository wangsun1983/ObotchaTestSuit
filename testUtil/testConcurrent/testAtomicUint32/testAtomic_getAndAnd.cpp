#include <stdio.h>
#include <unistd.h>

#include "AtomicUint32.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicUint32 value = createAtomicUint32(7);
      long v = value->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicUint32 testGetAndAnd test2");
        break;
      }

      if(value->get() != 2) {
        TEST_FAIL("AtomicUint32 testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint32 testGetAndAnd test100");
}
