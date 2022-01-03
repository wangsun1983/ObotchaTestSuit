#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void hashcodeTest() {

  while(1) {
    Integer t1 = createInteger(1);
    Integer t2 = createInteger(1);
    if(t1->hashcode() != t2->hashcode()) {
      TEST_FAIL("Integer hashcode test1");
      break;
    }

    Integer t3 = createInteger(2);
    if(t1->hashcode() == t3->hashcode()) {
      TEST_FAIL("Integer hashcode test2");
      break;
    }

    TEST_OK("Integer hashcode test3");
    break;
  }

}
