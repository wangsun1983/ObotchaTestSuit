#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Integer.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

DECLARE_CLASS(MyRun1) IMPLEMENTS(Runnable) {
public:

    _MyRun1(Mutex mutex) {
        //cond = condition;
        mutex_t = mutex;
    }

    void run() {
        //TEST_FAIL("Thread1 start \n");
        AutoLock l(mutex_t);
        //mutex_t->lock();
        //cond->wait(mutex_t);
        //TEST_FAIL("Thread1 goto sleep \n");
        sleep(5);
        //mutex_t->unlock();
        //TEST_FAIL("Thread1 end \n");
    }

private:
    //Condition *cond;
    Mutex mutex_t;
};

DECLARE_CLASS(MyRun2) IMPLEMENTS(Runnable) {
public:

    _MyRun2(Mutex mutex) {
      mutex_t = mutex;
    }

    void run() {
        //TEST_FAIL("Thread2 start \n");
        //cond->notify();
        AutoLock l(mutex_t);
        //mutex_t->lock();
        //TEST_FAIL("Thread2 trace \n");
        //mutex_t->unlock();
        //TEST_FAIL("Thread2 end \n");
    }

private:
    Mutex mutex_t;
};

#if 0
DECLARE_CLASS(MyRun3) IMPLEMENTS(Runnable) {
public:

    _MyRun3(Mutex mutex) {
      mutex_t = mutex;
    }

    void run() {
        //TEST_FAIL("Thread2 start \n");
        //cond->notify();
        AutoLock l(mutex_t,2000);
        //mutex_t->lock();
        //TEST_FAIL("Thread2 trace \n");
        //mutex_t->unlock();
        //TEST_FAIL("Thread2 end \n");
    }

private:
    Mutex mutex_t;
};
#endif

DECLARE_CLASS(MyRun4) IMPLEMENTS(Runnable) {
public:

    _MyRun4(Mutex mutex) {
      mutex_t = mutex;
    }

    void run() {
        //TEST_FAIL("Thread2 start \n");
        //cond->notify();
        //AutoLock l(mutex_t,2000);
        mutex_t->tryLock();
        //mutex_t->lock();
        //TEST_FAIL("Thread2 trace \n");
        //mutex_t->unlock();
        //TEST_FAIL("Thread2 end \n");
    }

private:
    Mutex mutex_t;
};

int testMutexNormal() {
    //Mutex()
    while(1) {
        Mutex mutex = createMutex();
        TEST_OK("[TestMutex Test {construct()} case1]");
        break;
    }

    //Mutex(String)
    while(1) {
        Mutex mutex = createMutex("test");
        if(!mutex->toString()->equals("test")) {
            TEST_FAIL("[TestMutex Test {construct(String)} case1]");
            break;
        }

        TEST_OK("[TestMutex Test {construct(String)} case2]");
        break;
    }

    //lock()
    while(1) {
        Mutex mutex = createMutex("test");
        Thread mThread1 = createThread(createMyRun1(mutex));//new Thread(new Thread1(mutex));
        mThread1->start();
        long current = st(System)::currentTimeMillis();
        sleep(1);

        Thread mThread2 = createThread(createMyRun2(mutex));
        mThread2->start();
        mThread2->join();
        int v = st(System)::currentTimeMillis() - current;
        if(v >5005) {
            TEST_FAIL("[TestMutex Test {lock()} case1]");
            break;
        }

        TEST_OK("[TestMutex Test {lock()} case2]");
        break;
    }

#if 0
    //lock(long)
    while(1) {
        Mutex mutex = createMutex("test");
        Thread mThread1 = createThread(createMyRun1(mutex));//new Thread(new Thread1(mutex));
        mThread1->start();
        sleep(1);
        long current = st(System)::currentTimeMillis();
        Thread mThread2 = createThread(createMyRun3(mutex));
        mThread2->start();
        int v = st(System)::currentTimeMillis() - current;
        if(v > 2005) {
            TEST_FAIL("[TestMutex Test {lock(long)} case1]");
            break;
        }

        TEST_FAIL("[TestMutex Test {lock(long)} case2] [OK] \n");
        break;
    }
#endif

    //unlock()
    while(1) {
        Mutex t = createMutex();
        int ret = t->unlock();
        if(ret == 0) {
            TEST_FAIL("[TestMutex Test {unlock()} case1]");
            break;
        }

        TEST_OK("[TestMutex Test {unlock()} case2]");
        break;
    }

    //tryLock()
    while(1) {
        Mutex mutex = createMutex("test");
        Thread mThread1 = createThread(createMyRun1(mutex));//new Thread(new Thread1(mutex));
        mThread1->start();
        sleep(1);
        long current = st(System)::currentTimeMillis();
        Thread mThread2 = createThread(createMyRun4(mutex));
        mThread2->start();
        mThread2->join();

        int v = st(System)::currentTimeMillis() - current;
        //TEST_FAIL("v is %d \n",v);
        if(v > 5) {
            TEST_FAIL("[TestMutex Test {tryLock()} case1]");
            break;
        }

        TEST_OK("[TestMutex Test {tryLock()} case2]");
        break;
    }

    sleep(10);
    return 0;
}
