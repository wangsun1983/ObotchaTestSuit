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
  Double d1 = Double::New(1.1);
  Double d2 = Double::New(1.1);
  if(d1->hashcode() != d2->hashcode()) {
    TEST_FAIL("Double hashcode test1");
  }

  Double d3 = Double::New(1.10);
  if(d1->hashcode() != d3->hashcode()) {
    TEST_FAIL("Double hashcode test2");
  }

  Double d4 = Double::New(1.100000001);
  if(d1->hashcode() == d4->hashcode()) {
    TEST_FAIL("Double hashcode test3");
  }

  TEST_OK("Double hashcode test100");
}
