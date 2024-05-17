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

void testByteArrayClone() {
  while(1) {
    ByteArray data1 = ByteArray::New(5);
    data1->fill(0x20);

    auto ptr1 = data1->clone();
    for(int i = 0;i < 5;i++) {
      ptr1[i] = i;
    }

    for(int i = 0;i < 5;i++) {
      if(ptr1[i] != i) {
        TEST_FAIL("testByteArrayClone case1");
      }
    }

    for(int i = 0;i < 5;i++) {
      if(data1[i] == i) {
        TEST_FAIL("testByteArrayClone case2");
      }
    }

    if(ptr1->size() != 5) {
      TEST_FAIL("testByteArrayClone case3");
    }
    break;
  }

  TEST_OK("testByteArrayClone case100");
}
