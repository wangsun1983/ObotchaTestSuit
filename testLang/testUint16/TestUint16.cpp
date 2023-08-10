#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {
  //_Uint16(int v);
  while(1) {
      Uint16 v1 = createUint16(10);
      if(v1->toValue() != 10){
          TEST_FAIL("Uint16 construct test1");
          break;
      }

      TEST_OK("Uint16 construct test");
      break;
  }

  //  _Uint16(Uint16 v);
  while(1) {
    Uint16 v1 = createUint16(11);
    Uint16 v2 = createUint16(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Uint16 construct test3");
      break;
    }

    // Uint16 v3;
    // try {
    //   Uint16 v4 = createUint16(v3);
    //   TEST_FAIL("Uint16 construct test4");
    // } catch(InitializeException e){}


    TEST_OK("Uint16 construct test5");
    break;
  }

  //int toValue();
  while(1) {
    Uint16 v1 = createUint16(11);
    Uint16 v2 = createUint16(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Uint16 toValue test1");
      break;
    }

    TEST_OK("Uint16 toValue test1");
    break;
  }

  //bool equals(Uint16 p);
  while(1) {
    Uint16 v1 = createUint16(11);
    Uint16 v2 = createUint16(11);
    if(!v1->equals(v2)) {
      TEST_FAIL("Uint16 equals test1");
      break;
    }
/*
    try {
      v1->equals(nullptr);
      TEST_FAIL("Uint16 equals test2");
    } catch(NullPointerException e) {}
*/
    TEST_OK("Uint16 equals test3");
    break;
  }

  //bool equals(int p);
  while(1) {
    Uint16 v1 = createUint16(11);
    if(!v1->sameAs(11)) {
      TEST_FAIL("Uint16 equals test4");
      break;
    }

    TEST_OK("Uint16 equals test5");
    break;
  }

  //==
  while(1) {
    Uint16 v1 = createUint16(12);
    Uint16 v2 = createUint16(12);
    if(v1 != v2) {
      TEST_FAIL("Uint16 [==] test1");
      break;
    }

    TEST_OK("Uint16 [==] test1");
    break;
  }

  //MAX_VALUE/MIN_VALUE
  while(1) {
      if(st(Uint16)::kMaxValue < 0) {
        TEST_FAIL("Uint16 MAX_VALUE test1");
        break;
      }

      if(st(Uint16)::kMinValue != 0) {
        TEST_FAIL("Uint16 MIN_VALUE test2");
        break;
      }

      TEST_OK("Uint16 MIN_VALUE/MAX_VALUE test3");
      break;
  }
  
  //update
  while(1) {
      Uint16 v1 = createUint16(12);
      v1->update(20);
      if(v1->toValue() != 20) {
        TEST_FAIL("Uint16 update test3");
      }
      
      Uint16 v2 = createUint16(52);
      v1->update(v2);
      if(v1->toValue() != 52) {
        TEST_FAIL("Uint16 update test4");
      }
      
      TEST_OK("Uint16 Update test3");
      break;
  }
}
