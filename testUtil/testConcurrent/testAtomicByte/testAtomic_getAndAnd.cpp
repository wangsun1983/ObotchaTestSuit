#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicByte value = createAtomicByte(7);
      long v = value->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicByte testGetAndAnd test2");
        break;
      }

      if(value->get() != 2) {
        TEST_FAIL("AtomicByte testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicByte testGetAndAnd test100");
}
