#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
using namespace obotcha;

void testOrAndGet() {
    while(1) {
      AtomicUint16 value = AtomicUint16::New(1);
      long v = value->orAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicUint16 testOrAndGet test1");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint16 testOrAndGet test100");
}
