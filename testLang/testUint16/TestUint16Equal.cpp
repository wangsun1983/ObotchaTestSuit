#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Uint16.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {
  while(1) {
      Uint16 v1 = Uint16::New(10);
      Uint16 v2 = Uint16::New(10);
      if(v1 != v2){
          TEST_FAIL("Uint16 equal test1");
          break;
      }

      Uint16 v3 = Uint16::New(10);
      Uint16 v4 = Uint16::New(11);
      if(v3 == v4){
          TEST_FAIL("Uint16 equal test2");
          break;
      }

      TEST_OK("Uint16 equal test3");
      break;
  }
}
