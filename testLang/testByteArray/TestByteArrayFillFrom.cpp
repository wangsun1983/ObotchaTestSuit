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

void testByteArrayFillFrom() {
  while(1) {
    byte *data = (byte *)malloc(5);
    for(int i = 0;i < 5;i++) {
      data[i] = i+32;
    }

    ByteArray data2 = createByteArray(10);
    for(int i = 0; i < 10 ;i++) {
      data2[i] = i + 64;
    }

    data2->fillFrom(data,5,2);
    // for(int i = 0; i <10;i++) {
    //   printf("v[%d] is %d \n",i,data2[i]);
    // }

    if(data2[0] != 64 || data2[1] != 65 ||data2[2] != 66 ||data2[3] != 67
      || data2[4] != 68 || data2[5] != 32 || data2[6] != 33) {
      TEST_FAIL("testByteArrayFillFrom case1");
    }

    if(data2[7] != 71 || data2[8] != 72 || data2[9] != 73) {
      TEST_FAIL("testByteArrayFillFrom case2");
    }
    
    free(data);
    break;
  }
  TEST_OK("testByteArrayFillFrom case100");
}
