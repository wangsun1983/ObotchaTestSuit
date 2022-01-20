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
#include "AtomicInteger.hpp"
#include "TestLog.hpp"

using namespace obotcha;

AtomicInteger value = createAtomicInteger(0);

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

    void onInterrupt() {
    }
};

DECLARE_CLASS(MyLoopSubmitRunnable3) IMPLEMENTS(Runnable) {
public:
    void run() {
        sleep(5);
    }

    void onInterrupt() {
    }
};

void testThreadPoolLoopSubmit() {
    //test1
    ThreadPoolExecutor executor = createThreadPoolExecutor(4,4);
    for(int i = 0;i<1024*8;i++){
      executor->execute(createMyLoopSubmitRunnable1());
    }
    sleep(1);
    if(value->get() != 1024*8) {
      TEST_FAIL("[ThreadPoolExecutor Loop Submit} special case1] ");
    }
    executor->shutdown();
    //test2
    ThreadPoolExecutor executor2 = createThreadPoolExecutor(4,4);
    for(int i = 0;i<1024*8;i++){
      executor2->submit(createMyLoopSubmitRunnable2());
    }
    sleep(1);
    if(value->get() != 0) {
      TEST_FAIL("[ThreadPoolExecutor Loop Submit} special case2] value is %d ",value->get());
    }
    executor2->shutdown();
    //test3
    ThreadPoolExecutor executor3 = createThreadPoolExecutor(1,1);
    executor3->submit(createMyLoopSubmitRunnable3());
    executor3->submit(createMyLoopSubmitRunnable3());
    long c = st(System)::currentTimeMillis();
    executor3->submit(createMyLoopSubmitRunnable3());
    long interval = st(System)::currentTimeMillis() - c;
    if(interval < 5000 || interval > 5005) {
      TEST_FAIL("[ThreadPoolExecutor Loop Submit} special case3],interval is %ld ",interval);
    }
    executor3->shutdown();
    
    TEST_OK("[ThreadPoolExecutor Loop Submit} special case100]");

}
