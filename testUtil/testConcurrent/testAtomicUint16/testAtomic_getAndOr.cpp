#include <stdio.h>
#include <unistd.h>

#include "AtomicUint16.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndOr() {
    while(1) {
      AtomicUint16 value = createAtomicUint16(1);
      long v = value->getAndOr(4);
      if(v != 1) {
        TEST_FAIL("AtomicUint16 testGetAndOr test2");
        break;
      }

      if(value->get() != 5) {
        TEST_FAIL("AtomicUint16 testGetAndOr test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint16 testGetAndOr test100");
}
