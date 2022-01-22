#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "CountDownLatch.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Error.hpp"
using namespace obotcha;

void testCountDownLatch_Construct() {
    while(1) {
      bool isException  = false;
      try {
        CountDownLatch l = createCountDownLatch(0);
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("[TestCountDownLatch Construct case1]");
        break;
      }

      break;
    }

    TEST_OK("[TestCountDownLatch Construct case100]");
}
