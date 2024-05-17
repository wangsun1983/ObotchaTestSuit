#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAndAndGet() {
    while(1) {
      AtomicByte Long = AtomicByte::New(3);
      long v = Long->andAndGet(2);
      if(v != 2) {
        TEST_FAIL("AtomicByte testAndAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicByte testAndAndGet test100");
}
