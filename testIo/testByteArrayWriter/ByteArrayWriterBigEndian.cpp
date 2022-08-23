#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "ByteArrayWriter.hpp"
#include <string.h>
#include "TestLog.hpp"
using namespace obotcha;


void testByteArrayBigEndian() {
    while(1) {
      ByteArray data = createByteArray(8);
      ByteArrayWriter writer = createByteArrayWriter(data,Global::BigEndian);
      writer->write<short int>(1);
      writer->write<short int>(2);
      writer->write<short int>(3);
      writer->write<short int>(4);
      byte *d1 = data->toValue();

      short int v1 = d1[0]<<8 | d1[1];
      if(v1 != 1) {
        TEST_FAIL("[TestByteArrayWriter BigEndian case1]v1 is %d ",v1);
      }

      writer->reset();
      writer->write<int>(12);
      writer->write<int>(198);
      //for(int i = 0;i<8;i++) {
      //  TEST_FAIL("d[%d] is %x ",i,d1[i]);
      //}
      int v2 = d1[3] | d1[2]<<8 |d1[1]<<16 |d1[0]<<24;
      if(v2 != 12) {
        TEST_FAIL("[TestByteArrayWriter BigEndian case2]");
      }

      int v3 = d1[7] | d1[6]<<8 |d1[5]<<16 |d1[4]<<24;
      if(v3 != 198) {
        TEST_FAIL("[TestByteArrayWriter BigEndian case3],v3 is %d ",v3);
      }

      writer->reset();
      writer->write<long>(12345678);
      long v4 =  (long)d1[7] | (long)d1[6]<<8 |(long)d1[5]<<16 |(long)d1[4]<<24|(long)d1[3]<<32
                |(long)d1[2]<<40|(long)d1[1]<<48|(long)d1[0]<<56;
      if(v4 != 12345678) {
        TEST_FAIL("[TestByteArrayWriter BigEndian case4]");
      }

      writer->reset();
      writer->write<byte>(1);
      writer->write<byte>(2);
      writer->write<byte>(3);
      writer->write<byte>(4);
      writer->write<byte>(5);
      writer->write<byte>(6);
      writer->write<byte>(7);
      writer->write<byte>(8);
      for(int i = 0;i<8;i++) {
        if(d1[i] != i + 1) {
          TEST_FAIL("[TestByteArrayWriter BigEndian case5],d1[%d] is %d",i,d1[i]);
        }
      }
      break;
    }
    TEST_OK("[TestByteArrayWriter BigEndian case100]");
}
