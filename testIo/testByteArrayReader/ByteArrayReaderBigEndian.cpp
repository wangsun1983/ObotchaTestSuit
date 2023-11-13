#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include <string.h>
#include "TestLog.hpp"

using namespace obotcha;


void testByteArrayBigEndian() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);

      //test short
      short int v1 = 0;
      v1 = (array[0]<<8)|array[1];
      int v1_chk = reader->read<short int>();
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case1],v1 is %d,v1_chk is %d",v1,v1_chk);
      }

      short int v2 = 0;
      v2 = (array[2]<<8)|array[3];
      int v2_chk = reader->read<short int>();
      if(v2 != v2_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case2],v2 is %d,v2_chk is %d",v2,v2_chk);
      }

      short int v3 = 0;
      v3 = (array[4]<<8)|array[5];
      int v3_chk = reader->read<short int>();
      if(v3 != v3_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case3],v3 is %d,v3_chk is %d",v3,v3_chk);
      }

      short int v4 = 0;
      v4 = (array[6]<<8)|array[7];
      int v4_chk = reader->read<short int>();
      if(v4 != v4_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case4],v4 is %d,v4_chk is %d",v4,v4_chk);
      }
      break;
    }

    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);
      int v1 = 0;
      v1 = (array[0]<<24)|(array[1]<<16)|(array[2]<<8)|(array[3]);
      int v1_chk = reader->read<int>();
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case5],v1 is %d,v1_chk is %d",v1,v1_chk);
      }

      int v2 = 0;
      v2 = (array[4]<<24)|(array[5]<<16)|(array[6]<<8)|(array[7]);
      int v2_chk = reader->read<int>();
      if(v2 != v2_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case6],v2 is %d,v2_chk is %d",v2,v2_chk);
      }
      break;
    }

    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);
      long v1 = 0;
      v1 = (long)array[7]|((long)array[6]<<8)|((long)array[5]<<16)|((long)array[4]<<24)|((long)array[3]<<32)|((long)array[2]<<40)|((long)array[1]<<48)|((long)array[0]<<56);
      long v1_chk = reader->read<long>();
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteArrayReader BigEndian case7],v1 is %lx,v1_chk is %lx",v1,v1_chk);
      }

      break;
    }

    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);

      for(int i = 0;i<8;i++) {
        byte v = reader->read<byte>();
        if(v != array[i]) {
          TEST_FAIL("[TestByteArrayReader BigEndian case8],v is %d,array[%d] is %d",v,i,array[i]);
        }
      }
      break;
    }
    
    //////
    while(1) {
        byte array2[] = {0x01,0x02};
        ByteArray testData = createByteArray(array2,2);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);
        
        auto v1 = (array2[0]<<8 | array2[1]);
        int v2_chk = reader->read<int>();
        if(v1 != v2_chk) {
          TEST_FAIL("[TestByteArrayReader BigEndian case9],v1 is %d,v2_chk is %d",v1,v2_chk);
        }
        break;
    }
    
    while(1) {
        byte array2[] = {0x01};
        ByteArray testData = createByteArray(array2,1);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);
        
        auto v1 = array2[0];
        int v2_chk = reader->read<int>();
        if(v1 != v2_chk) {
          TEST_FAIL("[TestByteArrayReader BigEndian case10],v1 is %d,v2_chk is %d",v1,v2_chk);
        }
        break;
    }
    
    while(1) {
        byte array2[] = {0x01,0x02};
        ByteArray testData = createByteArray(array2,2);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);
        
        auto v1 = (array2[0]<<8|array2[1]);
        long v2_chk = reader->read<long>();
        if(v1 != v2_chk) {
          TEST_FAIL("[TestByteArrayReader BigEndian case11],v1 is %d,v2_chk is %d",v1,v2_chk);
        }
        break;
    }
    
    while(1) {
        byte array2[] = {0x01,0x02};
        ByteArray testData = createByteArray(array2,2);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Big);
        
        auto v1 = reader->read<int>();
        int v1_chk = (array2[0]<<8|array2[1]);
        if(v1 != v1_chk) {
          TEST_FAIL("[TestByteArrayReader BigEndian case12],v1 is %d,v2_chk is %d",v1,v1_chk);
        }
        
        try {
            auto v2 = reader->read<int>();
            TEST_FAIL("[TestByteArrayReader BigEndian case13]");
        } catch(...){}
        
        break;
    }

    TEST_OK("[TestByteArrayReader BigEndian case8]");
}
