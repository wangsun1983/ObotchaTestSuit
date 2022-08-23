#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testsafemode() {

  //case1
  while(1) {
    ByteArray arr1 = createByteArray(8);
    //arr1->setSafe();
    for(int i = 0;i < 8;i++) {
      arr1[i] = 99;
    }

    byte *data1 = arr1->toValue(true);
    for(int i = 0;i < 8;i++) {
      data1[i] = i;
    }

    for(int i = 0;i < 8;i++) {
      if(arr1[i] != 99) {
        TEST_FAIL("ByteArray testsafemode test 1");
        break;
      }
    }
    free(data1);
    
    TEST_OK("ByteArray testsafemode test 2");
    break;
  }

  //case2
  while(1) {
    ByteArray arr1 = createByteArray(8);
    for(int i = 0;i < 8;i++) {
      arr1[i] = 99;
    }

    byte *data1 = arr1->toValue();
    for(int i = 0;i < 8;i++) {
      data1[i] = i;
    }

    for(int i = 0;i < 8;i++) {
      if(arr1[i] != i) {
        TEST_FAIL("ByteArray testsafemode test 3");
        break;
      }
    }

    TEST_OK("ByteArray testsafemode test 4");
    break;
  }

  //case3
  while(1) {
    ByteArray arr1 = createByteArray(8);
    //arr1->setSafe();
    //if(!arr1->isSafeMode()) {
    //  TEST_FAIL("ByteArray testsafemode test 5");
    //  break;
    //}
    break;
  }

  TEST_OK("ByteArray testsafemode test 100");
  return;
}
