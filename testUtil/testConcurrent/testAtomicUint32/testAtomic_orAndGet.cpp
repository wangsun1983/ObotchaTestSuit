#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
using namespace obotcha;

void testOrAndGet() {
    while(1) {
      AtomicUint32 value = createAtomicUint32(1);
      long v = value->orAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicUint32 testOrAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint32 testOrAndGet test100");
}
