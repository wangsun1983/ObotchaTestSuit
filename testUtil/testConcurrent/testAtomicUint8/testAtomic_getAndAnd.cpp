#include <stdio.h>
#include <unistd.h>

#include "AtomicUint8.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAnd() {
    while(1) {
      AtomicUint8 value = createAtomicUint8(7);
      long v = value->getAndAnd(2);
      if(v != 7) {
        TEST_FAIL("AtomicUint8 testGetAndAnd test2");
        break;
      }

      if(value->get() != 2) {
        TEST_FAIL("AtomicUint8 testGetAndAnd test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint8 testGetAndAnd test100");
}