#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testOrAndGet() {
    while(1) {
      AtomicInteger integer = AtomicInteger::New(1);
      int v = integer->orAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicInteger testOrAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger testOrAndGet test100");
}
