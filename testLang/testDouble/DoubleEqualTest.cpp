#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

const double EPSINON = 0.00001;

void equaltest() {

  while(1) {
    //case 1
    Double d1 = Double::New(1.1);
    Double d1_1 = Double::New(1.1);

    if(!d1->equals(d1_1)) {
        TEST_FAIL("Double equal special test1");
        break;
    }

    //case 2
    Double d2 = Double::New(1.1);
    Double d2_1 = Double::New(1.2);

    if(d2->equals(d2_1)) {
        TEST_FAIL("Double equal special test2");
        break;
    }

    TEST_OK("Double equal special test4");
    break;
  }

  while(1) {
    //case 1
    Double d1 = Double::New(1.1);
    Double d1_1 = Double::New(1.1);

    if(d1!= d1_1) {
        TEST_FAIL("Double equal special test5");
        break;
    }

    //case 2
    Double d2 = Double::New(1.1);
    Double d2_1 = Double::New(1.2);

    if(d2 == d2_1) {
        TEST_FAIL("Double equal special test6");
        break;
    }

    //case 3
    Double d3 = Double::New(1.1);
    Double d3_1;
    if(d3 == d3_1) {
      TEST_FAIL("Double equal special test7");
    }


    TEST_OK("Double equal special test8");
    break;
  }
}
