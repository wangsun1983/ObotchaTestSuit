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
      Integer v1 = Integer::New(10);
      Integer v2 = Integer::New(10);
      if(v1 != v2){
          TEST_FAIL("Integer equal test1");
          break;
      }

      Integer v3 = Integer::New(10);
      Integer v4 = Integer::New(11);
      if(v3 == v4){
          TEST_FAIL("Integer equal test2");
          break;
      }

      TEST_OK("Integer equal test3");
      break;
  }



}
