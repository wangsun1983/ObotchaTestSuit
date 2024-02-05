#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAndAndGet() {
    while(1) {
      AtomicUint16 Long = createAtomicUint16(3);
      long v = Long->andAndGet(2);
      if(v != 2) {
        TEST_FAIL("AtomicUint16 testAndAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint16 testAndAndGet test100");
}
