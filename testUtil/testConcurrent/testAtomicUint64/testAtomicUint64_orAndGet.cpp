#include <stdio.h>
#include <unistd.h>

#include "AtomicUint64.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
using namespace obotcha;

void testOrAndGet() {
    while(1) {
      AtomicUint64 value = createAtomicUint64(1);
      long v = value->orAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicUint64 testOrAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint64 testOrAndGet test100");
}
