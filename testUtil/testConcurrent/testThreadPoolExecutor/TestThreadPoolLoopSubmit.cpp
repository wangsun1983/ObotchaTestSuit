#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "ThreadPoolExecutor.hpp"
#include "Error.hpp"
#include "AtomicNumber.hpp"
#include "TestLog.hpp"

using namespace obotcha;

AtomicInteger value = AtomicInteger::New(0);

DECLARE_CLASS(MyLoopSubmitRunnable1) IMPLEMENTS(Runnable) {
public:
    void run() {
        value->incrementAndGet();
    }
};

DECLARE_CLASS(MyLoopSubmitRunnable2) IMPLEMENTS(Runnable) {
public:
    void run() {
        value->decrementAndGet();
    }

    bool onInterrupt() {
      return false;
    }
};

DECLARE_CLASS(MyLoopSubmitRunnable3) IMPLEMENTS(Runnable) {
public:
    void run() {
        sleep(5);
    }

    bool onInterrupt() {
      return false;
    }
};

void testThreadPoolLoopSubmit() {
    //test1
    ThreadPoolExecutor executor = ThreadPoolExecutor::New(4,4,0);
    for(int i = 0;i<1024*8;i++){
      executor->submit(MyLoopSubmitRunnable1::New());
    }
    sleep(1);
    if(value->get() != 1024*8) {
      TEST_FAIL("[ThreadPoolExecutor Loop Submit} special case1] ");
    }
    executor->shutdown();
    //test2
    ThreadPoolExecutor executor2 = ThreadPoolExecutor::New(4,4,0);
    for(int i = 0;i<1024*8;i++){
      executor2->submit(MyLoopSubmitRunnable2::New());
    }
    sleep(1);
    if(value->get() != 0) {
      TEST_FAIL("[ThreadPoolExecutor Loop Submit} special case2] value is %d ",value->get());
    }
    executor2->shutdown();
    //test3
    ThreadPoolExecutor executor3 = ThreadPoolExecutor::New(1,1,0);
    executor3->submit(MyLoopSubmitRunnable3::New());
    executor3->submit(MyLoopSubmitRunnable3::New());
    long c = st(System)::CurrentTimeMillis();
    executor3->submit(MyLoopSubmitRunnable3::New());
    long interval = st(System)::CurrentTimeMillis() - c;
    if(interval < 5000 || interval > 5005) {
      TEST_FAIL("[ThreadPoolExecutor Loop Submit} special case3],interval is %ld ",interval);
    }
    executor3->shutdown();

    TEST_OK("[ThreadPoolExecutor Loop Submit} special case100]");

}
