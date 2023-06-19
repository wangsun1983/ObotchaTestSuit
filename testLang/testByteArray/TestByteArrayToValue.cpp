#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testByteArrayToValue() {
  while(1) {
    ByteArray data1 = createByteArray(5);
    data1->fill(0x20);

    auto ptr1 = data1->toValue();
    memset(ptr1,0x11,5);
    for(int i = 0;i < 5;i++) {
      if(data1[i] != 0x11) {
        TEST_FAIL("testByteArrayToValue case1");
      }
    }
    break;
  }

  while(1) {
    ByteArray data1 = createByteArray(5);
    data1->fill(0x20);

    auto ptr1 = data1->toValue(true);
    memset(ptr1,0x11,5);
    for(int i = 0;i < 5;i++) {
      if(data1[i] != 0x20) {
        TEST_FAIL("testByteArrayToValue case2");
      }
    }
    free(ptr1);
    break;
  }

  TEST_OK("testByteArrayToValue case100");
}
