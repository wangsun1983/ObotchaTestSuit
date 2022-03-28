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
#include "InterruptedException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

AtomicInteger interruptCount = createAtomicInteger(0);

DECLARE_CLASS(MyLoopShutdownRunnable1) IMPLEMENTS(Runnable) {
public:
    void run() {
      try {
        st(Thread)::sleep(100);
      }catch(InterruptedException &e) {
        //interruptCount->add(1);
      }
    }

};

void testThreadPoolLoopShutdown() {
    //test1
    ThreadPoolExecutor executor = createThreadPoolExecutor(8*1024,4);
    for(int i = 0;i<8*1024;i++){
      executor->submit(createMyLoopShutdownRunnable1());
    }

    int ret = executor->shutdown();
    
    executor->awaitTermination();

    if(interruptCount->get() != 1024*8) {
      TEST_FAIL("[ThreadPoolExecutor Loop shutdown} special case1,value is %d]",interruptCount->get());
    }

    //test2
    interruptCount = createAtomicInteger(0);
    ThreadPoolExecutor executor2 = createThreadPoolExecutor(8*1024,4);
    ArrayList<Future> list = createArrayList<Future>();
    for(int i = 0;i<1024*8;i++){
      Future v = executor2->submit(createMyLoopShutdownRunnable1());
      list->add(v);
    }

    for(int i = 0;i<1024*8;i++) {
      Future v = list->get(i);
      v->cancel();
    }

    if(interruptCount->get() != 1024*8) {
      TEST_FAIL("[ThreadPoolExecutor Loop shutdown} special case2,value is %d]",interruptCount->get());
    }

    executor2->shutdown();

    TEST_OK("[ThreadPoolExecutor Loop shutdown} special case100]");

}
