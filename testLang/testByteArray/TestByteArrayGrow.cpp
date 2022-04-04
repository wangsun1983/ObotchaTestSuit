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

void testgrow() {

    //test growTo case
    while(1) {
      //case1
      ByteArray arr = createByteArray(8);
      for(int i = 0;i<8;i++) {
        arr[i] = i;
      }

      arr->growTo(16);
      if(arr->size() != 16) {
        TEST_FAIL("ByteArray testgrow test 1");
        break;
      }

      for(int i = 0;i<8;i++) {
        if(arr[i] != i) {
          TEST_FAIL("ByteArray testgrow test 2");
          break;
        }
      }

      for(int i = 9;i<16;i++) {
        if(arr[i] != 0) {
          TEST_FAIL("ByteArray testgrow test 3");
          break;
        }
      }

      //case2
      ByteArray arr2 = createByteArray(8);
      if(arr2->growTo(2) != -EINVAL) {
        TEST_FAIL("ByteArray testgrow test 4");
        break;
      }

      TEST_OK("ByteArray testgrow test 5");
      break;
    }

    //test clear
    while(1) {
      //case1
      ByteArray arr = createByteArray(8);
      for(int i = 0;i<8;i++) {
        arr[i] = i;
      }
      arr->quickShrink(4);

      if(arr->size() != 4) {
        TEST_FAIL("ByteArray testclear test 1");
        break;
      }

      arr->clear();
      if(arr->size() != 8) {
        TEST_FAIL("ByteArray testclear test 2");
        break;
      }

      for(int i = 0;i<8;i++) {
        if(arr[i] != 0) {
          TEST_FAIL("ByteArray testclear test 3");
          break;
        }
      }

      TEST_OK("ByteArray testclear test 4");
      break;
    }

    //test growBy
    while(1) {
      //case1
      ByteArray arr = createByteArray(8);
      for(int i = 0;i<8;i++) {
        arr[i] = i;
      }

      arr->growBy(16);
      if(arr->size() != 24) {
        TEST_FAIL("ByteArray testgrow test 5");
        break;
      }

      for(int i = 0;i<8;i++) {
        if(arr[i] != i) {
          TEST_FAIL("ByteArray testgrow test 6");
          break;
        }
      }

      for(int i = 9;i<24;i++) {
        if(arr[i] != 0) {
          TEST_FAIL("ByteArray testgrow test 7");
          break;
        }
      }

      TEST_OK("ByteArray testgrow test 7");
      break;
    }

}
