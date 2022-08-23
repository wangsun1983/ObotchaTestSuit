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

void parseWrongTest() {

  while(1) {
      String s = createString("xx.123");
      Float f = s->toFloat();
      if(f != nullptr) {
        TEST_FAIL("Parse wrong float string case1");
      }

      s = createString("1.2.123");
      f = s->toFloat();
      if(f != nullptr) {
        TEST_FAIL("Parse wrong float string case2");
      }

      s = createString(".123");
      f = s->toFloat();
      if(f == nullptr) {
        TEST_FAIL("Parse wrong float string case3,s is %lf",f->toValue());
      }

      if(!st(Float)::isEqual(f->toValue(),0.123)) {
        TEST_FAIL("Parse wrong float string case4");
      }
      break;
  }

  TEST_OK("Parse wrong float string case3");
}
