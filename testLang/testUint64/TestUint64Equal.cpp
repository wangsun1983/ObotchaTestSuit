#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint64.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Uint64.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {

  while(1) {
      Uint64 v1 = Uint64::New(10);
      Uint64 v2 = Uint64::New(10);
      if(v1 != v2){
          TEST_FAIL("Uint64 equal test1");
          break;
      }

      Uint64 v3 = Uint64::New(10);
      Uint64 v4 = Uint64::New(11);
      if(v3 == v4){
          TEST_FAIL("Uint64 equal test2");
          break;
      }

      TEST_OK("Uint64 equal test3");
      break;
  }
}
