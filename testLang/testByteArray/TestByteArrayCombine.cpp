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

void testByteArrayCombine() {

    while(1) {
      ByteArray data1 = createByteArray(5);
      ByteArray data2 = createByteArray(5);

      data1->fill(0x10);
      data2->fill(0x20);

      st(ByteArray)::Combine(data1,data2);
      if(data1->size() != 10) {
        TEST_FAIL("ByteArray test Combine test 1");
      }

      for(int i = 0; i < 5;i++) {
        if(data1[i] != 0x10) {
          TEST_FAIL("ByteArray test Combine test 2");
          break;
        }
      }

      for(int j = 5; j < 10;j++) {
        if(data1[j] != 0x20) {
          TEST_FAIL("ByteArray test Combine test 3");
          break;
        }
      }
      break;
    }

    while(1) {
      ByteArray data1 = nullptr;
      ByteArray data2 = createByteArray(5);
      data2->fill(0x20);
      st(ByteArray)::Combine(data1,data2);
      if(data1 == nullptr) {
        TEST_FAIL("ByteArray test Combine test 4");
        break;
      }

      if(data1->size() != 5) {
        TEST_FAIL("ByteArray test Combine test 5");
        break;
      }

      for(int i = 0;i < 5;i++) {
        if(data1[i] != 0x20) {
          TEST_FAIL("ByteArray test Combine test 5");
          break;
        }
      }
      break;
    }

    while(1) {
      ByteArray data1 = createByteArray(5);
      ByteArray data2 = nullptr;
      data1->fill(0x20);
      st(ByteArray)::Combine(data1,data2);
      if(data1 == nullptr) {
        TEST_FAIL("ByteArray test Combine test 6");
        break;
      }

      if(data1->size() != 5) {
        TEST_FAIL("ByteArray test Combine test 7");
        break;
      }

      for(int i = 0;i < 5;i++) {
        if(data1[i] != 0x20) {
          TEST_FAIL("ByteArray test Combine test 8");
          break;
        }
      }
      break;
    }

    TEST_OK("ByteArray test Combine test 100")
}
