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


void testByteArrayWriterString() {
    while(1) {
      ByteArray d1 = createByteArray(16);
      ByteArrayWriter writer = createByteArrayWriter(d1);
      char array[] = {'h','e','l','l','o','\0'};
      writer->write((const char *)array);

      if(!d1->toString()->sameAs("hello")) {
        TEST_FAIL("[TestByteArrayWriter Write String case1]");
      }
      break;
    }

    while(1) {
      ByteArray d1 = createByteArray(16);
      ByteArrayWriter writer = createByteArrayWriter(d1);
      String array = createString("hello");
      writer->write(array);

      if(!d1->toString()->sameAs("hello")) {
        TEST_FAIL("[TestByteArrayWriter Write String case2]");
      }
      break;
    }

    TEST_OK("[TestByteArrayWriter Write String case100]");
}
