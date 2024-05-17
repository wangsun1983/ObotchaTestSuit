#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include <string.h>
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testReadBigEndian() {
    byte array[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    while(1) {
      ByteArray testData = ByteArray::New(array,8);
      ByteRingArray ringArray = ByteRingArray::New(32);
      ringArray->push(testData);
      ByteRingArrayReader reader = ByteRingArrayReader::New(ringArray,st(IO)::Endianness::Big);

      //test short
      short int v1 = 0;
      v1 = (array[0]<<8)|array[1];
      short v1_chk = 0;
      reader->read<short>(v1_chk);
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case1],v1 is %x,v1_chk is %x",v1,v1_chk);
      }

      short int v2 = 0;
      v2 = (array[2]<<8)|array[3];
      short v2_chk = 0;
      reader->read<short>(v2_chk);
      if(v2 != v2_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case2],v2 is %d,v2_chk is %d",v2,v2_chk);
      }

      short int v3 = 0;
      v3 = (array[4]<<8)|array[5];
      short v3_chk = 0;
      reader->read<short>(v3_chk);
      if(v3 != v3_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case3],v3 is %d,v3_chk is %d",v3,v3_chk);
      }

      short int v4 = 0;
      v4 = (array[6]<<8)|array[7];
      short v4_chk = 0;
      reader->read<short>(v4_chk);
      if(v4 != v4_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case4],v4 is %d,v4_chk is %d",v4,v4_chk);
      }
      break;
    }

    while(1) {
      ByteArray testData = ByteArray::New(array,8);
      ByteRingArray ringArray = ByteRingArray::New(32);
      ringArray->push(testData);
      ByteRingArrayReader reader = ByteRingArrayReader::New(ringArray,st(IO)::Endianness::Big);
      
      int v1 = 0;
      v1 = (array[0]<<24)|(array[1]<<16)|(array[2]<<8)|(array[3]);
      int v1_chk = 0;
      reader->read<int>(v1_chk);
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case5],v1 is %d,v1_chk is %d",v1,v1_chk);
      }

      int v2 = 0;
      v2 = (array[4]<<24)|(array[5]<<16)|(array[6]<<8)|(array[7]);
      int v2_chk = 0;
      reader->read<int>(v2_chk);
      if(v2 != v2_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case6],v2 is %d,v2_chk is %d",v2,v2_chk);
      }
      break;
    }

    while(1) {
      ByteArray testData = ByteArray::New(array,8);
      ByteRingArray ringArray = ByteRingArray::New(32);
      ringArray->push(testData);
      ByteRingArrayReader reader = ByteRingArrayReader::New(ringArray,st(IO)::Endianness::Big);
      
      long v1 = 0;
      v1 = (long)array[7]|((long)array[6]<<8)|((long)array[5]<<16)|((long)array[4]<<24)|((long)array[3]<<32)|((long)array[2]<<40)|((long)array[1]<<48)|((long)array[0]<<56);
      long v1_chk = 0;
      reader->read<long>(v1_chk);
      if(v1 != v1_chk) {
        TEST_FAIL("[TestByteRingArrayReader BigEndian case7],v1 is %lx,v1_chk is %lx",v1,v1_chk);
      }

      break;
    }

    while(1) {
      ByteArray testData = ByteArray::New(array,8);
      ByteRingArray ringArray = ByteRingArray::New(32);
      ringArray->push(testData);
      ByteRingArrayReader reader = ByteRingArrayReader::New(ringArray,st(IO)::Endianness::Big);
     
      for(int i = 0;i<8;i++) {
        byte v = 0;
        reader->read<byte>(v);
        if(v != array[i]) {
          TEST_FAIL("[TestByteRingArrayReader BigEndian case8],v is %d,array[%d] is %d",v,i,array[i]);
        }
      }
      break;
    }

    TEST_OK("[TestByteRingArrayReader BigEndian case8]");
}
