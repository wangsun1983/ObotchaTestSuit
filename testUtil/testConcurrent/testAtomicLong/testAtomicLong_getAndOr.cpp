#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndOr() {
    while(1) {
      AtomicLong value = AtomicLong::New(1);
      long v = value->getAndOr(4);
      if(v != 1) {
        TEST_FAIL("AtomicLong testGetAndOr test2");
        break;
      }

      if(value->get() != 5) {
        TEST_FAIL("AtomicLong testGetAndOr test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicLong testGetAndOr test100");
}
