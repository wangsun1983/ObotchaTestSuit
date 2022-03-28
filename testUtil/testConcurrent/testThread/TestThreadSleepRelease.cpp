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
#include "InterruptedException.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int myLongSleepExceptionTest1 = 0;
int myLongSleepReleaseTest1 = 0;

DECLARE_CLASS(MyLongSleepTest1Thread) IMPLEMENTS(Thread) {
public:

  void run() {
      try {
        st(Thread)::sleep(50*1000);
      } catch(InterruptedException &e) {
          myLongSleepExceptionTest1 = 1;
      }
  }

  ~_MyLongSleepTest1Thread() {
      myLongSleepReleaseTest1 = 1;
  }
};


void testThreadSleepRelease() {
  
  while(1) {
    {
      MyLongSleepTest1Thread t = createMyLongSleepTest1Thread();
      t->start();
      sleep(1);
      t->interrupt();
    }
    sleep(1);

    if(myLongSleepExceptionTest1 != 1 || myLongSleepReleaseTest1 != 1) {
      TEST_FAIL("[Thread Test {sleep release()} case1]");
      break;
    }

    TEST_OK("[Thread Test {sleep release()} case2]");
    break;
  }

}
