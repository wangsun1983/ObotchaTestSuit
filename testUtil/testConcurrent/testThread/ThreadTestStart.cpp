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

DECLARE_CLASS(StartTestThread1) IMPLEMENTS(Thread) {
public:
    void run() {
        //TEST_FAIL("startTest trace1 ");
        sleep(1);
        //TEST_FAIL("startTest trace2 ");
    }
};

DECLARE_CLASS(StartTestThread2) IMPLEMENTS(Thread) {
public:
    _StartTestThread2() {

    }

    void run() {
        //TEST_FAIL("startTest trace1 ");
        sleep(1);
        //TEST_FAIL("startTest trace2 ");
    }
};

DECLARE_CLASS(StartTestThread3) IMPLEMENTS(Thread) {
public:
    void run() {

    }
};

void testThreadStart() {

    while(1) {
        StartTestThread1 t1 = createStartTestThread1();
        t1->start();
        int ret = t1->start();
        if(ret != -AlreadyExecute) {
            TEST_FAIL("[Thread TestStart {start()} case1]");
            break;
        }

        sleep(2);
        ret = t1->start();
        if(ret != -AlreadyExecute) {
            TEST_FAIL("[Thread TestStart {start()} case2]");
            break;
        }

        TEST_OK("[Thread TestStart {start()} case3]");
        break;
    }

    while(1) {
        StartTestThread1 t1 = createStartTestThread1();
        t1->start();
        int ret = t1->start();
        if(ret != -AlreadyExecute) {
            TEST_FAIL("[Thread TestStart {start()} case4]");
            break;
        }

        TEST_OK("[Thread TestStart {start()} case5]");
        break;
    }

    while(1) {
        Thread t1 = createThread([](){
            sleep(1);
        });
        t1->start();
        int ret = t1->start();
        if(ret != -AlreadyExecute) {
            TEST_FAIL("[Thread TestStart {start()} case6]");
            break;
        }

        TEST_OK("[Thread TestStart {start()} case7]");
        break;
    }

    while(1) {
        for(int i = 0;i<1024*32;i++) {
            StartTestThread3 r = createStartTestThread3();
            if(r->start() != 0) {
                TEST_FAIL("[Thread TestStart {start()} case8]");
                break;
            }

            if(r->start() != -AlreadyExecute) {
                TEST_FAIL("[Thread TestStart {start()} case9]");
                break;
            }
        }
        break;
    }

}
