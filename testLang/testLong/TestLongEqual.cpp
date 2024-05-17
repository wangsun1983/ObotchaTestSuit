#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Long.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Long.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {

  while(1) {
      Long v1 = Long::New(10);
      Long v2 = Long::New(10);
      if(v1 != v2){
          TEST_FAIL("Long equal test1");
          break;
      }

      Long v3 = Long::New(10);
      Long v4 = Long::New(11);
      if(v3 == v4){
          TEST_FAIL("Long equal test2");
          break;
      }

      TEST_OK("Long equal test3");
      break;
  }



}
