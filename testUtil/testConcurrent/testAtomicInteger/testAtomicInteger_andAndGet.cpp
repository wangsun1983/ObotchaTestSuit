#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAndAndGet() {
    while(1) {
      AtomicInteger integer = AtomicInteger::New(3);
      int v = integer->andAndGet(2);
      if(v != 2) {
        TEST_FAIL("AtomicInteger testAndAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger testAndAndGet test100");
}
