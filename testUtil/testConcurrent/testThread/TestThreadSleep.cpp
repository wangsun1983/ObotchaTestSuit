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

int count = 0;

DECLARE_CLASS(SleepRun1) IMPLEMENTS(Runnable) {
public:

  void run() {
      try {
        st(Thread)::sleep(100000000);
      } catch(InterruptedException e){}
      count++;
  }

};


void testThreadSleep() {

  while(1) {
    for(int i = 0;i < 1024*32;i++) {
      Thread t = createThread(createSleepRun1());
      t->start();
      t->interrupt();
      t->join();
    }
    TEST_OK("[Thread Test {sleep()} Interrupt case1] count is %d ",count);
    break;
  }
}
