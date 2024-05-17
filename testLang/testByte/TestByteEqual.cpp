#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Byte.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Byte.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {

  while(1) {
      Byte v1 = Byte::New(10);
      Byte v2 = Byte::New(10);
      if(v1 != v2){
          TEST_FAIL("Byte equal test1");
          break;
      }

      Byte v3 = Byte::New(10);
      Byte v4 = Byte::New(11);
      if(v3 == v4){
          TEST_FAIL("Byte equal test2");
          break;
      }

      TEST_OK("Byte equal test3");
      break;
  }



}
