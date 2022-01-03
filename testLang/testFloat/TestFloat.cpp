#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Float.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  //_Float(float v);
  while(1) {
      Float v1 = createFloat(10.12);
      if(v1->toValue() != 10.12f){
          TEST_FAIL("Float construct test1");
          break;
      }

      TEST_OK("Float construct test");
      break;
  }

  //  _Float(Float v);
  while(1) {
    Float v1 = createFloat(11.12f);
    Float v2 = createFloat(v1);
    if(v2->toValue() != 11.12f) {
      TEST_FAIL("Float construct test3");
      break;
    }

    TEST_OK("Float construct test5");
    break;
  }

  //float toValue();
  while(1) {
    Float v1 = createFloat(11.123f);
    Float v2 = createFloat(v1);
    if(v2->toValue() != 11.123f) {
      TEST_FAIL("Float toValue test1");
      break;
    }

    TEST_OK("Float toValue test1");
    break;
  }

  //bool equals(Float p);
  while(1) {
    Float v1 = createFloat(1.123f);
    Float v2 = createFloat(1.123f);
    if(!v1->equals(v2)) {
      TEST_FAIL("Float equals test1");
      break;
    }

    TEST_OK("Float equals test3");
    break;
  }

  //bool equals(float p);
  while(1) {
    Float v1 = createFloat(11.22);
    if(!v1->equals(11.22)) {
      TEST_FAIL("Float equals test4");
      break;
    }

    TEST_OK("Float equals test5");
    break;
  }

  //==
  while(1) {
    Float v1 = createFloat(12.1);
    Float v2 = createFloat(12.1);
    if(v1 != v2) {
      TEST_FAIL("Float [==] test1");
      break;
    }

    TEST_OK("Float [==] test1");
    break;
  }
}
