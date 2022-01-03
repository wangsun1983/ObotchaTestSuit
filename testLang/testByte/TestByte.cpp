#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "InitializeException.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {
  //_Byte(Byte v);
  while(1) {
      Byte v1 = createByte(10);
      if(v1->toValue() != 10){
          TEST_FAIL("Byte construct test1");
          break;
      }

      TEST_OK("Byte construct test");
      break;
  }

  // _Byte(Byte v);
  while(1) {
    Byte v1 = createByte(11);
    Byte v2 = createByte(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Byte construct test3");
      break;
    }

    TEST_OK("Byte construct test5");
    break;
  }

  //int toValue();
  while(1) {
    Byte v1 = createByte(11);
    Byte v2 = createByte(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Byte toValue test1");
      break;
    }

    TEST_OK("Byte toValue test1");
    break;
  }

  //bool equals(Integer p);
  while(1) {
    Byte v1 = createByte(11);
    Byte v2 = createByte(11);
    if(!v1->equals(v2)) {
      TEST_FAIL("Byte equals test1");
      break;
    }

    TEST_OK("Byte equals test3");
    break;
  }

  //bool equals(int p);
  while(1) {
    Byte v1 = createByte(11);
    if(!v1->equals(11)) {
      TEST_FAIL("Byte equals test4");
      break;
    }

    TEST_OK("Byte equals test5");
    break;
  }

  //==
  while(1) {
    Byte v1 = createByte(12);
    Byte v2 = createByte(12);
    if(v1 != v2) {
      TEST_FAIL("Byte [==] test1");
      break;
    }

    TEST_OK("Byte [==] test1");
    break;
  }

}
