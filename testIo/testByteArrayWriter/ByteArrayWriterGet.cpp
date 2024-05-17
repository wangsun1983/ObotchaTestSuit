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


void testByteArrayWriterGet() {
    while(1) {
      ByteArray array = ByteArray::New(8);
      ByteArrayWriter writer = ByteArrayWriter::New(array);
      writer->write<short int>(1);
      writer->write<short int>(2);

      auto arr1 = writer->getByteArray();
      if(arr1->size() != 4) {
        TEST_FAIL("[TestByteArrayWriter GetArray case1]");
      }

      if(arr1[0] != 1 || arr1[1] != 0 || arr1[2] != 2 || arr1[3] != 0) {
        for(int i = 0;i<arr1->size();i++) {
          TEST_FAIL("arr1[%d] is %x ",i,arr1[i]);
        }
        TEST_FAIL("[TestByteArrayWriter GetArray case2]");
      }
      break;
    }

    TEST_OK("[TestByteArrayWriter GetArray case100]");
}
