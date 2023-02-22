#include <stdio.h>
#include <unistd.h>

#include "AtomicByte.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
using namespace obotcha;

void testOrAndGet() {
    while(1) {
      AtomicByte value = createAtomicByte(1);
      long v = value->orAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicByte testOrAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicByte testOrAndGet test100");
}
