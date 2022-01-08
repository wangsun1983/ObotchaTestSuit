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

DECLARE_CLASS(JoinTestThread) IMPLEMENTS(Thread) {
public:
  void run() {
    sleep(10);
  }
};

DECLARE_CLASS(JoinTestThread2) IMPLEMENTS(Thread) {
public:
  _JoinTestThread2(JoinTestThread t) {
    mThread = t;
    mIsWake = false;
    setName("JoinTestThread2");
  }

  void run() {
    mThread->join();
    mIsWake = true;
  }

  bool isWake() {
    return mIsWake;
  }

private:
  JoinTestThread mThread;

  bool mIsWake;
};

DECLARE_CLASS(JoinTestThread3) IMPLEMENTS(Thread) {
public:
  _JoinTestThread3(JoinTestThread t) {
    mThread = t;
    mIsWake = false;
  }

  void run() {
    mThread->join();
    mIsWake = true;
  }

  bool isWake() {
    return mIsWake;
  }

private:
  JoinTestThread mThread;
  bool mIsWake;
};

DECLARE_CLASS(JoinTestThread4) IMPLEMENTS(Thread) {
public:
  _JoinTestThread4() {
    mIsWake = false;
  }

  void run() {
    mIsWake = true;
  }

  bool isWake() {
    return mIsWake;
  }

private:
  bool mIsWake;
};

DECLARE_CLASS(JoinTestThread5) IMPLEMENTS(Thread) {
public:
  _JoinTestThread5() {
    mIsWake = false;
  }

  void run() {
    sleep(10*1000);
    mIsWake = true;
  }

  bool isWake() {
    return mIsWake;
  }

private:
  bool mIsWake;
};


void testThreadJoin() {
  while(1) {
    JoinTestThread t1 = createJoinTestThread();
    t1->start();
    JoinTestThread2 t2 = createJoinTestThread2(t1);
    t2->start();
    JoinTestThread3 t3 = createJoinTestThread3(t1);
    t3->start();

    sleep(15);

    if(!t2->isWake() || !t3->isWake()) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case1]");
        break;
    }

    TEST_OK("[Thread Test {ThreadJoin()} special case2]");
    break;;
  }

  while(1) {
    JoinTestThread4 t4 = createJoinTestThread4();
    t4->start();
    sleep(1);
    if(!t4->isWake()) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case3]");
        break;
    }

    long t1 = st(System)::currentTimeMillis();
    t4->join();
    if((st(System)::currentTimeMillis() - t1)>2) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case4]");
        break;
    }

    TEST_OK("[Thread Test {ThreadJoin()} special case5]");
    break;
  }

  while(1) {
    JoinTestThread4 t4 = createJoinTestThread4();
    t4->start();
    sleep(1);
    if(!t4->isWake()) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case7]");
        break;
    }

    long t1 = st(System)::currentTimeMillis();
    t4->join();
    if((st(System)::currentTimeMillis() - t1)>2) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case8]");
        break;
    }

    TEST_OK("[Thread Test {ThreadJoin()} special case9]");
    break;
  }

  while(1) {
    JoinTestThread5 t5 = createJoinTestThread5();
    t5->start();
    sleep(1);

    long t1 = st(System)::currentTimeMillis();
    t5->join(2000);
    long v = st(System)::currentTimeMillis() - t1;
    if(v < 2000 || v > 2010) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case10]");
        break;
    }

    if(t5->isWake()) {
        TEST_FAIL("[Thread Test {ThreadJoin()} special case11]");
        break;
    }

    //t5->quit();
    TEST_OK("[Thread Test {ThreadJoin()} special case12]");
    break;
  }

}
