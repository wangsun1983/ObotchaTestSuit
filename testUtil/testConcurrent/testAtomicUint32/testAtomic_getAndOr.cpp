#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndOr() {
    while(1) {
      AtomicUint32 value = createAtomicUint32(1);
      long v = value->getAndOr(4);
      if(v != 1) {
        TEST_FAIL("AtomicUint32 testGetAndOr test2");
        break;
      }

      if(value->get() != 5) {
        TEST_FAIL("AtomicUint32 testGetAndOr test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint32 testGetAndOr test100");
}
