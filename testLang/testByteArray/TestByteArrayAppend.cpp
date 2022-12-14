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

void testappend() {

    //testAppend
    while(1) {
      //case1
      ByteArray data1 = createByteArray(16);
      for(int i = 0;i<16;i++) {
        data1[i] = i;
      }

      ByteArray data2 = createByteArray(16);
      for(int i = 0;i<16;i++) {
        data2[i] = i+16;
      }

      data1->append(data2);
      if(data1->size() != 32) {
        TEST_FAIL("ByteArray testappend test 1");
        break;
      }

      for(int i = 0;i<32;i++) {
        if(data1[i] != i) {
            TEST_FAIL("ByteArray testappend test 2");
            break;
        }
      }


      //case2
      ByteArray data3 = createByteArray(8);
      for(int i = 0;i<8;i++) {
        data3[i] = i;
      }

      byte data4[12];
      if(data3->append(data4,-1) != -EINVAL) {
        TEST_FAIL("ByteArray testappend test 3");
        break;
      }

      TEST_OK("ByteArray testappend test 4");
      break;
    }

    //testAppend
    while(1) {
      ByteArray array = createByteArray(16);
      for(int i = 0;i<16;i++) {
        array[i] = i;
      }

      array->quickShrink(8);

      ByteArray array2 = createByteArray(4);
      for(int i = 0;i < 4;i++) {
        array2[i] = i;
      }

      const byte *t1 = array->toValue();

      array->append(array2);
      const byte *t2 = array->toValue();

      if(t1 != t2) {
        TEST_FAIL("ByteArray testappend test 5");
        break;
      }

      if(array->size() != 12) {
        TEST_FAIL("ByteArray testappend test 6");
        break;
      }

      if(array[0] != 0
        ||array[1] != 1
        ||array[2] != 2
        ||array[3] != 3
        ||array[4] != 4
        ||array[5] != 5
        ||array[6] != 6
        ||array[7] != 7
        ||array[8] != 0
        ||array[9] != 1
        ||array[10] != 2
        ||array[11] != 3 ) {
        TEST_FAIL("ByteArray testappend test 7");
        break;
      }

      TEST_OK("ByteArray testappend test 8");
      break;
    }
    
    //append(const sp<_ByteArray> &b, int len)
    while(1) {
        ByteArray data = createByteArray(16);
        for(int i = 0;i < 16;i++) {
            data[i] = i;
        }
        
        ByteArray data2 = createByteArray(8);
        for(int i = 16;i < 24;i++) {
            data2[i-16] = i;
        }
        
        data->append(data2,2);
        if(data->size() != 18) {
            TEST_FAIL("ByteArray testappend test 9");
            break;
        }
        
        for(int i = 0;i < 18;i++) {
            if(data[i] != i) {
                TEST_FAIL("ByteArray testappend test 10");
                break;
            }
        }
        
        break;
    }
    
    while(1) {
        ByteArray data = createByteArray(16);
        for(int i = 0;i < 16;i++) {
            data[i] = i;
        }
        
        ByteArray data2 = createByteArray(8);
        for(int i = 16;i < 24;i++) {
            data2[i-16] = i;
        }
        
        try {
            data->append(data2,32);
            TEST_FAIL("ByteArray testappend test 11");
        } catch(...) {}
        
        break;
    }
    
    TEST_OK("ByteArray testappend test 100");
}
