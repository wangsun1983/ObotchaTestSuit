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

DECLARE_CLASS(JoinRunCase2) IMPLEMENTS(Runnable) {
public:
  _JoinRunCase2(int v) {
    waitInterval = v;
  }

  void run() {
    st(Thread)::Sleep(waitInterval);
  }

private:
  int waitInterval;
};


void testThreadjoinCase2() {
  //sleep(1ms)
  for(int i = 0;i<64;i++) {
    Thread t = createThread(createJoinRunCase2(1));
    t->start();
    t->join();
  }

  TEST_OK("[Thread Test {JoinCase()} case1]");

  for(int i = 0;i<64;i++) {
    Thread t = createThread(createJoinRunCase2(10));
    t->start();
    t->join();
  }
  TEST_OK("[Thread Test {JoinCase()} case2]");

  for(int i = 0;i<64;i++) {
    Thread t = createThread(createJoinRunCase2(100));
    t->start();
    t->join();
  }
  TEST_OK("[Thread Test {JoinCase()} case3]");

  //wait(1ms)
  for(int i = 0;i<64;i++) {
    Thread t = createThread(createJoinRunCase2(1));
    t->start();
    st(Thread)::Sleep(1);
    t->join();
  }
  TEST_OK("[Thread Test {JoinCase()} case4]");

  for(int i = 0;i<64;i++) {
    Thread t = createThread(createJoinRunCase2(10));
    t->start();
    st(Thread)::Sleep(10);
    t->join();
  }

  TEST_OK("[Thread Test {JoinCase()} case6]");


}
