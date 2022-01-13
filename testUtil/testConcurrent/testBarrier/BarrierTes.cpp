#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(Run1) IMPLEMENTS(Runnable) {
public:
  _Run1(Barrier v) {
    barrier = v;
  }

  void run() {
      sleep(3);
      barrier->await();
  }

  ~_Run1() {
    //disposeVal = 10;
  }
private:
  Barrier barrier;
};


DECLARE_CLASS(Run2) IMPLEMENTS(Runnable) {
public:
  _Run2(Barrier v) {
    barrier = v;
  }

  void run() {
      sleep(3);
      barrier->await();

  }

  ~_Run2() {
    //disposeVal = 10;
  }
private:
  Barrier barrier;
};

DECLARE_CLASS(Run3) IMPLEMENTS(Runnable) {
public:
  _Run3(Barrier v) {
    barrier = v;
  }

  void run() {
      barrier->await();
  }

  ~_Run3() {
    //disposeVal = 10;
  }
private:
  Barrier barrier;
};

int mtestCount = 0;
DECLARE_CLASS(Run4) IMPLEMENTS(Runnable) {
public:
  _Run4(Barrier v) {
    barrier = v;
  }

  void run() {
      barrier->await();
      mtestCount = 1;
  }

  ~_Run4() {
    //disposeVal = 10;
  }
private:
  Barrier barrier;
};

int normaltest() {
  
  //Barrier()/getWaitNums()
  while(1) {
      Barrier barrier = createBarrier(2);
      int num = barrier->getWaitNums();
      if(num != 2) {
        TEST_FAIL("[Barrier Test {construct()} case1]");
        break;
      }

      TEST_OK("[Barrier Test {construct()} case2]");
      break;
  }

  //await()
  while(1) {
      Barrier b = createBarrier(3);
      Thread t1 = createThread(createRun1(b));
      t1->start();

      Thread t2 = createThread(createRun1(b));
      t2->start();
      long current = st(System)::currentTimeMillis();
      b->await();

      int v = st(System)::currentTimeMillis() - current;
      if(v > 3005) {
        TEST_FAIL("[Barrier Test {await()} case1]");
        break;
      }

      TEST_OK("[Barrier Test {await()} case2]");
      break;
  }

  //await(long)
  while(1) {
      Barrier b = createBarrier(3);
      Thread t1 = createThread(createRun1(b));
      t1->start();

      long current = st(System)::currentTimeMillis();
      b->await(1000);
      int v = st(System)::currentTimeMillis() - current;
      if(v > 1005) {
        TEST_FAIL("[Barrier Test {await(long)} case1]");
        break;
      }

      TEST_OK("[Barrier Test {await(long)} case2]");
      break;
  }

  //getWaitNums()
  while(1) {
    Barrier b = createBarrier(2);
    Thread t1 = createThread(createRun3(b));
    t1->start();
    sleep(1);
    int num = b->getWaitNums();
    if(num != 1) {
        TEST_FAIL("[Barrier Test {getWaitNums()} case1]");
        break;
    }

    TEST_OK("[Barrier Test {getWaitNums()} case2]");
    break;
  }

  //await()
  while(1) {
    Barrier b = createBarrier(2);
    Thread t1 = createThread(createRun4(b));
    t1->start();

    sleep(2);
    if(mtestCount == 1) {
        TEST_FAIL("[Barrier Test func {await()} case1]");
        break;
    }

    TEST_OK("[Barrier Test func {await()} case2]");
    break;
  }

  return 0;
}
