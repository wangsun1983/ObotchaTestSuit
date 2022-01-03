#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Float.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

const float EPSINON = 0.00001;

void equaltest() {

  while(1) {
    //case 1
    Float d1 = createFloat(1.1);
    Float d1_1 = createFloat(1.1);

    if(!d1->equals(d1_1)) {
        TEST_FAIL("Float equal special test1");
        break;
    }

    //case 2
    Float d2 = createFloat(1.1);
    Float d2_1 = createFloat(1.2);

    if(d2->equals(d2_1)) {
        TEST_FAIL("Float equal special test2");
        break;
    }

    TEST_OK("Float equal special test4");
    break;
  }

  while(1) {
    //case 1
    Float d1 = createFloat(1.1);
    Float d1_1 = createFloat(1.1);

    if(d1!= d1_1) {
        TEST_FAIL("Float equal special test5");
        break;
    }

    //case 2
    Float d2 = createFloat(1.1);
    Float d2_1 = createFloat(1.2);

    if(d2 == d2_1) {
        TEST_FAIL("Float equal special test6");
        break;
    }

    //case 3
    Float d3 = createFloat(1.1);
    Float d3_1;
    if(d3 == d3_1) {
      TEST_FAIL("Float equal special test7");
    }


    TEST_OK("Float equal special test8");
    break;
  }
}
