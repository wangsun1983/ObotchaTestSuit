#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "FileDescriptor.hpp"
#include "TestLog.hpp"
#include "File.hpp"

using namespace obotcha;

void testIsClosed() {
    //isClosed
    while(1) {
      int fd = open("./tmp/base_data",O_RDONLY);
      FileDescriptor descripor = createFileDescriptor(fd);

      if(descripor->isClosed()) {
        TEST_FAIL("[FileDescriptor isClosed Test case1]");
      }
      close(fd);

      if(!descripor->isClosed()) {
        TEST_FAIL("[FileDescriptor isClosed Test case2]");
      }
      break;
    }

    //isAsync
    while(1) {
      int fd = open("./tmp/base_data",O_RDONLY);
      FileDescriptor descripor = createFileDescriptor(fd);

      if(descripor->isAsync()) {
        TEST_FAIL("[FileDescriptor isClosed Test case3]");
      }

      descripor->setAsync(false);

      if(descripor->isAsync()) {
        TEST_FAIL("[FileDescriptor isClosed Test case4]");
      }

      descripor->setAsync(true);
      if(!descripor->isAsync()) {
        TEST_FAIL("[FileDescriptor isClosed Test case5]");
      }

      close(fd);
      break;
    }

    //hashcode
    while(1) {
      int fd = open("./tmp/base_data",O_RDONLY);
      FileDescriptor descripor = createFileDescriptor(fd);
      if(descripor->hashcode() != fd) {
        TEST_FAIL("[FileDescriptor isClosed Test case6]");
      }
      close(fd);
      break;
    }

    TEST_OK("[FileDescriptor isClosed Test case100]");
}
