#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndOr() {
    while(1) {
      AtomicByte value = createAtomicByte(1);
      long v = value->getAndOr(4);
      if(v != 1) {
        TEST_FAIL("AtomicByte testGetAndOr test2");
        break;
      }

      if(value->get() != 5) {
        TEST_FAIL("AtomicByte testGetAndOr test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicByte testGetAndOr test100");
}
