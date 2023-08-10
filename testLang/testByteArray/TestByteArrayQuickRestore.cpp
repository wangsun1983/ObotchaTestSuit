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

void testByteArrayQuickRestore() {
  while(1) {
    ByteArray data = createByteArray(10);
    for(int i = 0;i < 10;i++) {
      data[i] = i;
    }

    data->quickShrink(5);
    data->quickShrink(4);
    data->quickShrink(3);
    data->quickShrink(2);
    data->quickRestore();
    if(data->size() != 10) {
      TEST_FAIL("testByteArrayQuickRestore case1");
    }

    for(int i = 0; i < 10;i++) {
      if(data[i] != i) {
        TEST_FAIL("testByteArrayQuickRestore case2");
      }
    }

    break;
  }
  TEST_OK("testByteArrayQuickRestore case100");
}
