#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Long.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void hashcodeTest() {

  while(1) {
    Long t1 = createLong(1);
    Long t2 = createLong(1);
    if(t1->hashcode() != t2->hashcode()) {
      TEST_FAIL("Long hashcode test1");
      break;
    }

    Long t3 = createLong(2);
    if(t1->hashcode() == t3->hashcode()) {
      TEST_FAIL("Long hashcode test2");
      break;
    }

    TEST_OK("Long hashcode test3");
    break;
  }

}
