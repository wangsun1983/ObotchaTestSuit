#include <stdio.h>
#include <unistd.h>

#include "AtomicUint32.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAndAndGet() {
    while(1) {
      AtomicUint32 Long = createAtomicUint32(3);
      long v = Long->andAndGet(2);
      if(v != 2) {
        TEST_FAIL("AtomicUint32 testAndAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint32 testAndAndGet test100");
}
