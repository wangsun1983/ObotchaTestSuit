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

Thread gThread = nullptr;

void testThreadCurrent() {
  while(1) {
      bool isRun = false;
      Thread t1 = createThread([&isRun] {
        usleep(1000 * 100);
        if(st(Thread)::current() != gThread
            ||st(Thread)::current() == nullptr) {
            TEST_FAIL("[Thread Test {Current()} case1]");
        }
        isRun = true;
      });
      t1->start();
      gThread = t1;
      t1->join();
      if(!isRun) {
          TEST_FAIL("[Thread Test {Current()} case2]");
      }
      break;
  }
  
  if(st(Thread)::current() != nullptr) {
    TEST_FAIL("[Thread Test {Current()} case3]");
  }
  
  TEST_OK("[Thread Test {Current()} case100]");
}
