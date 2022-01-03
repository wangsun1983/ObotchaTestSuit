#include <stdio.h>
#include <unistd.h>
#include <iostream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

const double EPSINON = 0.00001;

void hashtest() {
  Double d1 = createDouble(1.1);
  Double d2 = createDouble(1.1);
  if(d1->hashcode() != d2->hashcode()) {
    TEST_FAIL("Double hashcode test1");
  }

  Double d3 = createDouble(1.10);
  if(d1->hashcode() != d3->hashcode()) {
    TEST_FAIL("Double hashcode test2");
  }

  Double d4 = createDouble(1.100000001);
  if(d1->hashcode() == d4->hashcode()) {
    TEST_FAIL("Double hashcode test3");
  }

  TEST_OK("Double hashcode test100");
}
