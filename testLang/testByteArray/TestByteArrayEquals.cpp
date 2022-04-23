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

void testByteArrayEquals() {

  while(1) {
    ByteArray d1 = createByteArray(16);
    for(int i = 0;i<16;i++) {
      d1[i] = i;
    }

    ByteArray d2 = createByteArray(16);
    for(int i = 0;i<16;i++) {
      d2[i] = i;
    }

    if(!d1->equals(d2)) {
      TEST_FAIL("ByteArray test equals case1");
    }
    break;
  }

  while(1) {
    ByteArray d1 = createByteArray(16);
    for(int i = 0;i<16;i++) {
      d1[i] = i;
    }

    ByteArray d2 = createByteArray(16);
    for(int i = 0;i<16;i++) {
      d2[i] = i+1;
    }

    if(d1->equals(d2)) {
      TEST_FAIL("ByteArray test equals case2");
    }
    break;
  }

  while(1) {
    ByteArray d1 = createByteArray(16);
    for(int i = 0;i<16;i++) {
      d1[i] = i;
    }

    ByteArray d2;

    if(d1->equals(d2)) {
      TEST_FAIL("ByteArray test equals case3");
    }
    break;
  }

  TEST_OK("ByteArray test equals case100");
}
