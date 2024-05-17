#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "InitializeException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  //_Long(long v);
  while(1) {
      Long v1 = Long::New(10);
      if(v1->toValue() != 10){
          TEST_FAIL("Long construct test1");
          break;
      }

      TEST_OK("Long construct test");
      break;
  }

  // _Long(Long v);
  while(1) {
    Long v1 = Long::New(11);
    Long v2 = Long::New(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Long construct test3");
      break;
    }

    // Long v3;
    // try {
    //     Long v4 = Long::New(v3);
    //     TEST_FAIL("Long construct test4");
    // } catch(InitializeException e) {}

    TEST_OK("Long construct test5");
    break;
  }

  //int toValue();
  while(1) {
    Long v1 = Long::New(11);
    Long v2 = Long::New(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Long toValue test1");
      break;
    }

    TEST_OK("Long toValue test1");
    break;
  }

  //bool equals(Integer p);
  while(1) {
    Long v1 = Long::New(11);
    Long v2 = Long::New(11);
    if(!v1->equals(v2)) {
      TEST_FAIL("Long equals test2");
      break;
    }

    TEST_OK("Long equals test2");
    break;
  }

  //bool equals(int p);
  while(1) {
    Long v1 = Long::New(11);
    if(!v1->sameAs(11)) {
      TEST_FAIL("Long equals test4");
      break;
    }

    TEST_OK("Long equals test5");
    break;
  }

  //==
  while(1) {
    Long v1 = Long::New(12);
    Long v2 = Long::New(12);
    if(v1 != v2) {
      TEST_FAIL("Long [==] test1");
      break;
    }

    TEST_OK("Long [==] test1");
    break;
  }

}
