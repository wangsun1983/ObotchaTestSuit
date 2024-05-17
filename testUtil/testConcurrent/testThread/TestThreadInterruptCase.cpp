#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "InterruptedException.hpp"
#include "TestLog.hpp"

#define TEST_DEVIATION 50 //ms
#define TEST_SLEEP_INTERVAL 100 //s

static int disposeVal = -1;

using namespace obotcha;

Mutex myTest1Mutex;
int myTest1 = 0;
int myTest1Interrupt = 0;

DECLARE_CLASS(MyTest1Thread) IMPLEMENTS(Thread) {
public:
    void run() {
        try {
            st(Thread)::Sleep();
        }catch(InterruptedException &e){
            myTest1Interrupt = 1;
        }
    }

    ~_MyTest1Thread() {
        //TEST_FAIL("m2 ");
        myTest1 = 1;
    }
};

std::atomic_int mytest2count{0};

DECLARE_CLASS(MyTest2Run) IMPLEMENTS(Runnable) {
public:
    void run() {
        usleep(1000 * 200);
    }

    bool onInterrupt() {
        mytest2count++;
        return false;
    }
};

void testThreadInterruptCase() {
    //TestThread onInterrupt case1
    while(1) {
        MyTest1Thread thread = MyTest1Thread::New();
        thread->start();
        sleep(1);
        thread->interrupt();
        thread->join();
        if(myTest1Interrupt != 1) {
            TEST_FAIL("[Thread Test {Interrupt()} special case1]");
            break;
        }
        break;
    }

    while(1) {
        MyTest2Run r2 = MyTest2Run::New();
        Thread t = Thread::New(r2);
        mytest2count = 0;
        t->start();

        usleep(1000*100);

        t->interrupt();

        if(mytest2count != 1) {
            int val = mytest2count;
            TEST_FAIL("[Thread Test {Interrupt()} special case3],mytest2count is %d ",val);
        }

        t->join();
        break;
    }

    TEST_OK("[Thread Test {Interrupt()} special case100]");

}
