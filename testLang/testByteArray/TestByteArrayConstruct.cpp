#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <stdlib.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConstruct() {

    while(1) {
      //case1 _ByteArray(int length,bool isSafe = false);
      ByteArray data = createByteArray(128);
      if(data->size() != 128) {
        TEST_FAIL("ByteArray test Construct test 1");
        break;
      }
      data[16] = 12;
      byte *val = data->toValue();
      val[16] = 32;
      if(data[16] != 32) {
        TEST_FAIL("ByteArray test Construct test 2");
        break;
      }

      data = createByteArray(128);
      //data->setSafe();
      data[16] = 12;

      val = data->toValue(true);
      val[16] = 32;
      if(data[16] == 32) {
        TEST_FAIL("ByteArray test Construct test 3");
        break;
      }

      free(val);
      TEST_OK("ByteArray test Construct test 4");
      break;
    }

    while(1) {
      //_ByteArray(const byte *data,uint32_t len,bool isSafe = false);
      byte data[128];
      for(int i = 0;i < 128;i++) {
        data[i] = i;
      }

      ByteArray arr1 = createByteArray(data+32,16);
      for(int i = 0;i < 16;i++) {
        if(arr1[i] != i+32) {
          TEST_FAIL("ByteArray test Construct test 3");
          break;
        }
      }

      byte *val = arr1->toValue();
      val[8] = 32;
      if(arr1[8] != 32) {
        TEST_FAIL("ByteArray test Construct test 4");
        break;
      }

      arr1 = createByteArray(data+32,16);
      //arr1->setSafe();
      for(int i = 0;i < 16;i++) {
        if(arr1[i] != i+32) {
          TEST_FAIL("ByteArray test Construct test 4");
          break;
        }
      }

      val = arr1->toValue(true);
      val[8] = 32;
      if(arr1[8] == 32) {
        TEST_FAIL("ByteArray test Construct test 5");
        break;
      }
      free(val);
      TEST_OK("ByteArray test Construct test 5");
      break;
    }

    while(1) {
      ByteArray data = createByteArray(32);
      for(int i = 0;i<32;i++) {
        data[i] = i;
      }

      ByteArray arr1 = createByteArray(data);
      for(int i = 0;i<32;i++) {
        if(arr1[i] != i) {
          TEST_FAIL("ByteArray test Construct test 6");
          break;
        }
      }

      byte *val = arr1->toValue();
      val[16] = 22;
      if(arr1[16] != 22) {
        TEST_FAIL("ByteArray test Construct test 7");
        break;
      }

      ByteArray arr2 = createByteArray(data->toValue(),32);
      //arr2->setSafe();
      for(int i = 0;i<32;i++) {
        if(arr2[i] != i) {
          TEST_FAIL("ByteArray test Construct test 8");
          break;
        }
      }

      val = arr2->toValue(true);
      val[16] = 22;
      if(arr2[16] == 22) {
        TEST_FAIL("ByteArray test Construct test 9");
        break;
      }
      free(val);
      TEST_OK("ByteArray test Construct test 10");
      break;
    }

    //_ByteArray::_ByteArray(sp<_ByteArray>&data,int start,int len)
    while(1) {
      ByteArray data = createByteArray(32);
      for(int i = 0; i < data->size();i++) {
        data[i] = i;
      }

      ByteArray data1 = createByteArray(data);
      if(data1->size() != 32) {
        TEST_FAIL("ByteArray test Construct test 11");
        break;
      }

      for(int j = 0;j< data1->size();j++) {
        if(data[j] != data1[j]) {
          TEST_FAIL("ByteArray test Construct test 12");
          break;
        }
      }
      break;
    }

    while(1) {
      ByteArray data = createByteArray(32);
      for(int i = 0; i < data->size();i++) {
        data[i] = i;
      }

      ByteArray data1 = createByteArray(data,10);
      if(data1->size() != 22) {
        TEST_FAIL("ByteArray test Construct test 13");
        break;
      }
      
      for(int j = 0;j< data1->size();j++) {
        if(data[j + 10] != data1[j]) {
          TEST_FAIL("ByteArray test Construct test 14,data is %d,data2 is %d",data[j+10],data1[j]);
          break;
        }
      }
      break;
    }

    while(1) {
      ByteArray data = createByteArray(32);
      for(int i = 0; i < data->size();i++) {
        data[i] = i;
      }

      ByteArray data1 = createByteArray(data,10,2);
      if(data1->size() != 2) {
        TEST_FAIL("ByteArray test Construct test 15,size is %d",data1->size());
        break;
      }

      for(int j = 0;j< 2;j++) {
        if(data[j + 10] != data1[j]) {
          TEST_FAIL("ByteArray test Construct test 16");
          break;
        }
      }
      break;
    }
	
	while(1) {
		ByteArray data1 = createByteArray(5);
		ByteArray data2 = createByteArray(data1,0,1);
		if(data2->size() != 1) {
			TEST_FAIL("ByteArray test Construct test 17");
		}
		
		ByteArray data3 = createByteArray(data1,0,5);
		if(data3->size() != 5) {
			TEST_FAIL("ByteArray test Construct test 18");
		}
		
		try {
			ByteArray data4 = createByteArray(data1,1,5);
			TEST_FAIL("ByteArray test Construct test 19");
		} catch(...) {}
		
		try {
			ByteArray data5 = createByteArray(data1,2,4);
			TEST_FAIL("ByteArray test Construct test 20");
		} catch(...) {}
		
		ByteArray data6 = createByteArray(data1,2,3);
		if(data6->size() != 3) {
			TEST_FAIL("ByteArray test Construct test 21");
		}
		
		ByteArray data7 = createByteArray(data1,0,0);
		if(data7->size() != 5) {
			TEST_FAIL("ByteArray test Construct test 22");
		}
		break;
	}
    TEST_OK("ByteArray test Construct test 100");
}
