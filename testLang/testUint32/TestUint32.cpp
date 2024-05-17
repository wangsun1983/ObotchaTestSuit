#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint32.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  //_Uint32(int v);
  while(1) {
      Uint32 v1 = Uint32::New(10);
      if(v1->toValue() != 10){
          TEST_FAIL("Uint32 construct test1");
          break;
      }

      TEST_OK("Uint32 construct test");
      break;
  }

  //  _Uint32(Uint32 v);
  while(1) {
    Uint32 v1 = Uint32::New(11);
    Uint32 v2 = Uint32::New(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Uint32 construct test3");
      break;
    }

    // Uint32 v3;
    // try {
    //     Uint32 v4 = Uint32::New(v3);
    //     TEST_FAIL("Uint32 construct test4");
    // } catch(InitializeException e) {}

    TEST_OK("Uint32 construct test5");
    break;
  }

  //int toValue();
  while(1) {
    Uint32 v1 = Uint32::New(11);
    Uint32 v2 = Uint32::New(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Uint32 toValue test1");
      break;
    }

    TEST_OK("Uint32 toValue test1");
    break;
  }

  //bool equals(Uint32 p);
  while(1) {
    Uint32 v1 = Uint32::New(11);
    Uint32 v2 = Uint32::New(11);
    if(!v1->equals(v2)) {
      TEST_FAIL("Uint32 equals test1");
      break;
    }
/*
    try {
      v1->equals(nullptr);
      TEST_FAIL("Uint32 equals test2");
    } catch(NullPointerException e) {}
*/
    TEST_OK("Uint32 equals test3");
    break;
  }

  //bool equals(int p);
  while(1) {
    Uint32 v1 = Uint32::New(11);
    if(!v1->sameAs(11)) {
      TEST_FAIL("Uint32 equals test4");
      break;
    }

    TEST_OK("Uint32 equals test5");
    break;
  }

  //==
  while(1) {
    Uint32 v1 = Uint32::New(12);
    Uint32 v2 = Uint32::New(12);
    if(v1 != v2) {
      TEST_FAIL("Uint32 [==] test1");
      break;
    }

    TEST_OK("Uint32 [==] test1");
    break;
  }

  //MAX_VALUE/MIN_VALUE
  while(1) {
      if(st(Uint32)::kMaxValue < 0) {
        TEST_FAIL("Uint32 MAX_VALUE test1");
        break;
      }

      if(st(Uint32)::kMinValue != 0) {
        TEST_FAIL("Uint32 MIN_VALUE test2");
        break;
      }

      TEST_OK("Uint32 MIN_VALUE/MAX_VALUE test3");
      break;
  }
  
  //update
  while(1) {
      Uint32 v1 = Uint32::New(12);
      v1->update(20);
      if(v1->toValue() != 20) {
        TEST_FAIL("Uint32 update test3");
      }
      
      Uint32 v2 = Uint32::New(52);
      v1->update(v2);
      if(v1->toValue() != 52) {
        TEST_FAIL("Uint32 update test4");
      }
      
      TEST_OK("Uint32 Update test3");
      break;
  }
}
