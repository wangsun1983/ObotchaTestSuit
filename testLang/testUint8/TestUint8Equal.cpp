#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint8.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Uint8.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {

  while(1) {
      Uint8 v1 = createUint8(10);
      Uint8 v2 = createUint8(10);
      if(v1 != v2){
          TEST_FAIL("Uint8 equal test1");
          break;
      }

      Uint8 v3 = createUint8(10);
      Uint8 v4 = createUint8(11);
      if(v3 == v4){
          TEST_FAIL("Uint8 equal test2");
          break;
      }

      TEST_OK("Uint8 equal test3");
      break;
  }



}
