#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAndAndGet() {
    while(1) {
      AtomicUint8 Long = AtomicUint8::New(3);
      long v = Long->andAndGet(2);
      if(v != 2) {
        TEST_FAIL("AtomicUint8 testAndAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint8 testAndAndGet test100");
}
