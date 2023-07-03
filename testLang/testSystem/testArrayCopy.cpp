#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "System.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

#define CPU_NUMS 12

void testArrayCopy() {
  while(1) {
    ByteArray src = createByteArray(32);
    for(int i = 0;i < 32;i++) {
      src[i] = i;
    }

    ByteArray dest = createByteArray(35);
    dest[32] = 66;
    dest[33] = 67;
    dest[34] = 68;

    st(System)::ArrayCopy(dest,0,src,0,32);

    for(int i = 0; i < 32;i++) {
      if(dest[i] != i) {
        TEST_FAIL("[testArrayCopy case1]");
      }
    }

    if(dest[32] != 66 || dest[33] != 67 || dest[34] != 68) {
      TEST_FAIL("[testArrayCopy case2]");
    }
    break;
  }

  while(1) {
    ByteArray src = createByteArray(32);
    for(int i = 0;i < 32;i++) {
      src[i] = i;
    }

    ByteArray dest = createByteArray(35);
    dest[0] = 55;
    dest[32] = 66;
    dest[33] = 67;
    dest[34] = 68;

    st(System)::ArrayCopy(dest,1,src,0,32);

    for(int i = 1; i < 32;i++) {
      if(dest[i] != i-1) {
        TEST_FAIL("[testArrayCopy case3],dest[%d] is %d",i,dest[i]);
      }
    }

    if(dest[0] != 55 || dest[32] == 67 || dest[33] != 67 || dest[34] != 68) {
      TEST_FAIL("[testArrayCopy case4]");
    }
    break;
  }

  while(1) {
    ByteArray src = createByteArray(32);
    for(int i = 0;i < 32;i++) {
      src[i] = i;
    }

    ByteArray dest = createByteArray(35);
    for(int i = 0;i < 35;i++) {
      dest[i] = 22;
    }

    st(System)::ArrayCopy(dest,1,src,2,16);

    for(int i = 1; i < 17;i++) {
      if(dest[i] != src[i + 1]) {
        TEST_FAIL("[testArrayCopy case5],dest[%d] is %d",i,dest[i]);
      }
    }

    if(dest[0] != 22) {
      TEST_FAIL("[testArrayCopy case6]");
    }

    for(int i = 17;i < 35;i++) {
      if(dest[i] != 22) {
        TEST_FAIL("[testArrayCopy case7],dest[%d] is %d",i,dest[i]);
      }
    }
    break;
  }

  TEST_OK("[testArrayCopy case100]");
}
