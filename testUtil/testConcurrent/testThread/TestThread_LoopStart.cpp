#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadLoopStart() {
  while(1) {
    Thread t = createThread([] {

    });
    if(t->start() != 0) {
      TEST_FAIL("[Thread Loop start case1]");
      break;
    }

    if(t->start() == 0) {
      TEST_FAIL("[Thread Loop start case2]");
      break;
    }
    break;
  }
  TEST_OK("[Thread Loop start case100]");
}
