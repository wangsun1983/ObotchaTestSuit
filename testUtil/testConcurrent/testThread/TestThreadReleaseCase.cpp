#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "TestLog.hpp"

#define TEST_DEVIATION 50 //ms
#define TEST_SLEEP_INTERVAL 100 //s

static int disposeVal = -1;

using namespace obotcha;

Mutex myReleaseMutex = Mutex::New();
int mReleaseCount = 0;

DECLARE_CLASS(MyReleaseTestThread) IMPLEMENTS(Thread) {
public:
    void run() {
        sleep(1);
    }

    ~_MyReleaseTestThread() {
        AutoLock l(myReleaseMutex);
        mReleaseCount++;
    }

    void onInterrupt() {

    }

};



DECLARE_CLASS(MyReleaseTest2Thread) IMPLEMENTS(Thread) {
public:
    void run() {
            sleep(3);
    }

    ~_MyReleaseTest2Thread() {
        AutoLock l(myReleaseMutex);
        mReleaseCount++;
    }

    void onInterrupt() {

    }
};

void testThreadRelease() {
    //TestThread onInterrupt case1
    while(1) {
        for(int i = 0;i < 50;i++) {
            Thread t = MyReleaseTestThread::New();
            t->start();
        }

        sleep(10);
        if(mReleaseCount != 50) {
            TEST_FAIL("[Thread Test {release()} case1],mReleaseCount is %d",mReleaseCount);
            break;
        }

        TEST_OK("[Thread Test {release()} case2]");
        break;
    }

    while(1) {
        mReleaseCount = 0;
        ArrayList<Thread> list = ArrayList<Thread>::New();
        for(int i = 0;i < 50;i++) {
            Thread t = MyReleaseTestThread::New();
            t->start();
            list->add(t);
        }

        sleep(10);
        if(mReleaseCount != 0) {
            TEST_FAIL("[Thread Test {release()} case3],mReleaseCount is %d",mReleaseCount);
            break;
        }

        list->clear();
        if(mReleaseCount != 50) {
            TEST_FAIL("[Thread Test {release()} case4],mReleaseCount is %d",mReleaseCount);
            break;
        }

        TEST_OK("[Thread Test {release()} case5]");
        break;
    }

    //interrupt
    while(1) {
        mReleaseCount = 0;
        ArrayList<Thread> list = ArrayList<Thread>::New();
        for(int i = 0;i < 50;i++) {
            Thread t = MyReleaseTest2Thread::New();
            t->start();
            list->add(t);
        }

        for(int i = 0;i<50;i++) {
            Thread t = list->get(0);
            //t->quit();
        }

        sleep(5);
        if(mReleaseCount != 0) {
            TEST_FAIL("[Thread Test {release()} case6],mReleaseCount is %d",mReleaseCount);
            break;
        }

        sleep(5);
        list->clear();
        if(mReleaseCount != 50) {
            TEST_FAIL("[Thread Test {release()} case7],mReleaseCount is %d",mReleaseCount);
            break;
        }

        TEST_OK("[Thread Test {release()} case8]");
        break;

    }

}
