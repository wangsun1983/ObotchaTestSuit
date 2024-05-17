#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint32.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Uint32.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {

  while(1) {
      Uint32 v1 = Uint32::New(10);
      Uint32 v2 = Uint32::New(10);
      if(v1 != v2){
          TEST_FAIL("Uint32 equal test1");
          break;
      }

      Uint32 v3 = Uint32::New(10);
      Uint32 v4 = Uint32::New(11);
      if(v3 == v4){
          TEST_FAIL("Uint32 equal test2");
          break;
      }

      TEST_OK("Uint32 equal test3");
      break;
  }



}
