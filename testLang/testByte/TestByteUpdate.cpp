#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void updatetest() {
  while(1) {
      //case 1
      Byte v1 = createByte(10);
      v1->update(2);

      if(v1->toValue() != 2){
          TEST_FAIL("Byte update special test1");
          break;
      }

      //case 2
      Byte v2 = createByte(10);
      Byte v2_1 = createByte(2);
      v2->update(v2_1);

      if(v2->toValue() != 2) {
          TEST_FAIL("Byte update special test2");
          break;
      }

      TEST_OK("yte update special test4");
      break;
  }



}
