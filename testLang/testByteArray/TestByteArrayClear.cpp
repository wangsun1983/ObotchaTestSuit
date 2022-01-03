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

void testByteArrayClear() {

    while(1) {
      ByteArray data = createByteArray(32);
      for(int i = 0; i < 32;i++) {
        data[i] = i;
      }

      data->quickShrink(16);
      if(data->size() != 16) {
        TEST_FAIL("ByteArray test Clear test 1");
        break;
      }

      for(int i = 0;i < 16;i++) {
        if(data[i] != i) {
          TEST_FAIL("ByteArray test Clear test 2");
          break;
        }
      }

      data->clear();
      if(data->size() != 32) {
        TEST_FAIL("ByteArray test Clear test 3");
        break;
      }

      for(int i = 0;i<32;i++) {
        if(data[i] != 0) {
          TEST_FAIL("ByteArray test Clear test 4");
          break;
        }
      }

      TEST_OK("ByteArray test Clear test 5");
      break;
    }
}
