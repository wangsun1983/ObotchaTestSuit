#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "StrongPointer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  //Test Construct
  Double t0 = Double::New(100.01);
  Double t0_1 = Double::New(t0);
  if(t0 == t0_1){
    TEST_OK("Double construct test1");
  } else {
    TEST_FAIL("Double construct test1");
  }

  //Test bool equals(Double p);
  Double t1 = Double::New(1.2);
  Double t2 = Double::New(1.2);

  if(t1->equals(t2)) {
    TEST_OK("Double equal test1");
  } else {
    TEST_FAIL("Double equal test1");
  }

  if(t1 == t2) {
    TEST_OK("Double operator == test1");
  } else {
    TEST_FAIL("Double operator == test1");
  }

  //Test bool equals(int p);
  Double t3 = Double::New(1.1);
  if(t3->sameAs(1.1)) {
    TEST_OK("Double equal test2");
  } else {
    TEST_FAIL("Double equal test2");
  }
}
