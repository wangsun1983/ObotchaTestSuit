#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint8.hpp"
#include "StrongPointer.hpp"
#include "Uint8.hpp"
#include "InitializeException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  //_Uint8(int v);
  while(1) {
      Uint8 v1 = createUint8(10);
      if(v1->toValue() != 10){
          TEST_FAIL("Uint8 construct test1");
          break;
      }

      TEST_OK("Uint8 construct test");
      break;
  }

  //  _Uint8(Uint8 v);
  while(1) {
    Uint8 v1 = createUint8(11);
    Uint8 v2 = createUint8(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Uint8 construct test3");
      break;
    }

    Uint8 v3;
    try {
      Uint8 v4 = createUint8(v3);
      TEST_FAIL("Uint8 construct test4");
    } catch(InitializeException e) {}

    TEST_OK("Uint8 construct test5");
    break;
  }

  //int toValue();
  while(1) {
    Uint8 v1 = createUint8(11);
    Uint8 v2 = createUint8(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Uint8 toValue test1");
      break;
    }

    TEST_OK("Uint8 toValue test1");
    break;
  }

  //bool equals(Uint8 p);
  while(1) {
    Uint8 v1 = createUint8(11);
    Uint8 v2 = createUint8(11);
    if(!v1->equals(v2)) {
      TEST_FAIL("Uint8 equals test1");
      break;
    }

/*
    try {
      v1->equals(nullptr);
      TEST_FAIL("Uint8 equals test2");
    } catch(NullPointerException e) {}
*/
    TEST_OK("Uint8 equals test3");
    break;
  }

  //bool equals(int p);
  while(1) {
    Uint8 v1 = createUint8(11);
    if(!v1->equals(11)) {
      TEST_FAIL("Uint8 equals test4");
      break;
    }

    TEST_OK("Uint8 equals test5");
    break;
  }

  //==
  while(1) {
    Uint8 v1 = createUint8(12);
    Uint8 v2 = createUint8(12);
    if(v1 != v2) {
      TEST_FAIL("Uint8 [==] test1");
      break;
    }

    TEST_OK("Uint8 [==] test1");
    break;
  }

  //MAX_VALUE/MIN_VALUE
  while(1) {
      if(st(Uint8)::MAX_VALUE < 0) {
        TEST_FAIL("Uint8 MAX_VALUE test1");
        break;
      }

      if(st(Uint8)::MIN_VALUE != 0) {
        TEST_FAIL("Uint8 MIN_VALUE test2");
        break;
      }

      TEST_OK("Uint8 MIN_VALUE/MAX_VALUE test3");
      break;
  }
  
  //update
  while(1) {
      Uint8 v1 = createUint8(12);
      v1->update(20);
      if(v1->toValue() != 20) {
        TEST_FAIL("Uint8 update test3");
      }
      
      Uint8 v2 = createUint8(52);
      v1->update(v2);
      if(v1->toValue() != 52) {
        TEST_FAIL("Uint8 update test4");
      }
      
      TEST_OK("Uint8 Update test3");
      break;
  }

}
