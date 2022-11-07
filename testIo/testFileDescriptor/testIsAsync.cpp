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

void testIsAsync() {
    //isAsync
    while(1) {
      int fd = open("./tmp/base_data",O_RDONLY);
      FileDescriptor descripor = createFileDescriptor(fd);

      if(descripor->isAsync()) {
        TEST_FAIL("[FileDescriptor isAsync Test case3]");
      }

      descripor->setAsync(false);

      if(descripor->isAsync()) {
        TEST_FAIL("[FileDescriptor isAsync Test case4]");
      }

      descripor->setAsync(true);
      if(!descripor->isAsync()) {
        TEST_FAIL("[FileDescriptor isAsync Test case5]");
      }

      close(fd);
      break;
    }

    TEST_OK("[FileDescriptor isAsync Test case100]");
}
