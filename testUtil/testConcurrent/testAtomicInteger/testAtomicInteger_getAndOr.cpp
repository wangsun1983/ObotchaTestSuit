#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndOr() {
    while(1) {
      AtomicInteger integer = AtomicInteger::New(1);
      int v = integer->getAndOr(4);
      if(v != 1) {
        TEST_FAIL("AtomicInteger testGetAndOr test2");
        break;
      }

      if(integer->get() != 5) {
        TEST_FAIL("AtomicInteger testGetAndOr test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger testGetAndOr test100");
}
