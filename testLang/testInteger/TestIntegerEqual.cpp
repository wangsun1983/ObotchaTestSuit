#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void equaltest() {

  while(1) {
      Integer v1 = createInteger(10);
      Integer v2 = createInteger(10);
      if(v1 != v2){
          TEST_FAIL("Integer equal test1");
          break;
      }

      Integer v3 = createInteger(10);
      Integer v4 = createInteger(11);
      if(v3 == v4){
          TEST_FAIL("Integer equal test2");
          break;
      }

      TEST_OK("Integer equal test3");
      break;
  }



}
