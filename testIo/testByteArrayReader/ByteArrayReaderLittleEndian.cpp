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


void testByteArrayLittleEndian() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    while(1) {
      ByteArray testData = createByteArray(array,8);

      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);

      //test short
      short int v1 = 0;
      v1 = array[0]|(array[1]<<8);
      int v1_chk = reader->read<short int>();
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case1],v1 is %x,v1_chk is %x",v1,v1_chk);
      }

      short int v2 = 0;
      v2 = array[2]|(array[3]<<8);
      int v2_chk = reader->read<short int>();
      if(v2 != v2_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case2],v2 is %x,v2_chk is %x",v2,v2_chk);
      }

      short int v3 = 0;
      v3 = array[4]|(array[5]<<8);
      int v3_chk = reader->read<short int>();
      if(v3 != v3_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case3],v3 is %x,v3_chk is %x",v3,v3_chk);
      }

      short int v4 = 0;
      v4 = array[6]|(array[7]<<8);
      int v4_chk = reader->read<short int>();
      if(v4 != v4_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case4],v4 is %x,v4_chk is %x",v4,v4_chk);
      }
      break;
    }

    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
      int v1 = 0;
      v1 = array[0]|(array[1]<<8)|(array[2]<<16)|(array[3]<<24);
      int v1_chk = reader->read<int>();
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case5],v1 is %d,v1_chk is %d",v1,v1_chk);
      }

      int v2 = 0;
      v2 = array[4]|(array[5]<<8)|(array[6]<<16)|(array[7]<<24);
      int v2_chk = reader->read<int>();
      if(v2 != v2_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case6],v2 is %d,v2_chk is %d",v2,v2_chk);
      }
      break;
    }

    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
      long v1 = 0;
      v1 = (long)array[0]|((long)array[1]<<8)|((long)array[2]<<16)|((long)array[3]<<24)|((long)array[4]<<32)|((long)array[5]<<40)|((long)array[6]<<48)|((long)array[7]<<56);
      long v1_chk = reader->read<long>();
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteArrayReader LittleEndia case7],v1 is %lx,v1_chk is %lx",v1,v1_chk);
      }

      break;
    }

    while(1) {
      ByteArray testData = createByteArray(array,8);
      ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
      for(int i = 0;i<8;i++) {
        byte v = reader->read<byte>();
        if(v != array[i]) {
          TEST_FAIL("[TestByteArrayReader LittleEndia case8],v is %d,array[%d] is %d",v,i,array[i]);
        }
      }
      break;
    }
    
    while(1) {
        byte array2[] = {0x01,0x02};
        ByteArray testData = createByteArray(array2,2);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
        
        auto v1 = (array2[0] | array2[1] <<8);
        int v2_chk = reader->read<short int>();
        if(v1 != v2_chk) {
          TEST_FAIL("[TestByteArrayReader LittleEndia case9],v1 is %d,v2_chk is %d",v1,v2_chk);
        }
        break;
    }
    
    while(1) {
        byte array2[] = {0x01};
        ByteArray testData = createByteArray(array2,1);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
        
        auto v1 = array2[0];
        byte v2_chk = reader->read<byte>();
        if(v1 != v2_chk) {
          TEST_FAIL("[TestByteArrayReader LittleEndia case10],v1 is %d,v2_chk is %d",v1,v2_chk);
        }
        break;
    }
    
    while(1) {
        byte array2[] = {0x01,0x02};
        ByteArray testData = createByteArray(array2,2);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
        
        auto v1 = (array2[0]|array2[1]<<8);
        long v2_chk = reader->read<short int>();
        if(v1 != v2_chk) {
          TEST_FAIL("[TestByteArrayReader LittleEndia case11],v1 is %d,v2_chk is %d",v1,v2_chk);
        }
        break;
    }
    
    while(1) {
        byte array2[] = {0x01,0x02};
        ByteArray testData = createByteArray(array2,2);
        ByteArrayReader reader = createByteArrayReader(testData,st(IO)::Endianness::Little);
        
        auto v1 = reader->read<short int>();
        int v1_chk = (array2[0]|array2[1]<<8);
        if(v1 != v1_chk) {
          TEST_FAIL("[TestByteArrayReader LittleEndia case12],v1 is %d,v2_chk is %d",v1,v1_chk);
        }
        
        try {
            auto v2 = reader->read<int>();
            TEST_FAIL("[TestByteArrayReader LittleEndia case13]");
        } catch(...){}
        
        break;
    }

    TEST_OK("[TestByteArrayReader LittleEndia case100]");
}
