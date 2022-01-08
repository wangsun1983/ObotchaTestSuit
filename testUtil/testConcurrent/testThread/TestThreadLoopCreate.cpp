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
#include "AtomicInteger.hpp"
#include "TestLog.hpp"

using namespace obotcha;

Mutex t = createMutex("test");
AtomicInteger value = createAtomicInteger(0);
AtomicInteger MyCompleteLoopValue = createAtomicInteger(0);

DECLARE_CLASS(LoopCreateRun1) IMPLEMENTS(Runnable) {
public:

  void run() {
      value->incrementAndGet();
  }
};

DECLARE_CLASS(LoopTestThread) IMPLEMENTS(Thread) {
public:
  void run() {
    //do nothing
  }

  void onComplete() {
    MyCompleteLoopValue->incrementAndGet();
  }
};

void testThreadLoopCreate() {
  //test1
  for(int i = 0;i<1024*32;i++) {
      Thread t = createThread(createLoopCreateRun1());
      t->start();
  }

  sleep(1);
  if(value->get() != (1024*32)) {
    printf("value is %d ",value->get());
    TEST_FAIL("[Thread Test {Loop create()} special case1]");
  }

  //test2
  for(int i = 0;i<1024*32;i++) {
      LoopTestThread t = createLoopTestThread();
      t->start();
  }

  sleep(1);
  if(MyCompleteLoopValue->get() != (1024*32)) {
    printf("value1 is %d ",MyCompleteLoopValue->get());
    TEST_FAIL("[Thread Test {Loop create()} special case2]");
  }

  TEST_OK("[Thread Test {Loop create()} special case3]");

}
