#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "AtomicNumber.hpp"
#include "TestLog.hpp"

using namespace obotcha;

AtomicInteger loopValue = createAtomicInteger(0);
Barrier barrier_257 = createBarrier(256 + 1);

DECLARE_CLASS(LoopSubmitRun) IMPLEMENTS(Runnable) {
public:
    void run() {
      barrier_257->await();
      loopValue->incrementAndGet();
    }
};

int looptest() {
  //test1
  for(int i = 0;i < 256;i++) {
    Thread t = createThread(createLoopSubmitRun());
    t->start();
  }
  barrier_257->await();
  sleep(1);
  if(loopValue->get() != 256) {
    TEST_FAIL("[Barrier Test {loop test} case1]");
    return 0;
  }

  TEST_OK("[Barrier Test {loop test} case100]");
  return 0;
}
