#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ExecutorService.hpp"
#include "Integer.hpp"
#include "Executors.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Math.hpp"

using namespace obotcha;

DECLARE_CLASS(ResultData3) {
public:
  int value1;
  int value2;
};

DECLARE_CLASS(ThreadPoolResultRunInt3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(1);
  }
};

DECLARE_CLASS(ThreadPoolResultRunByte3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(1);
  }
};

DECLARE_CLASS(ThreadPoolResultRunDouble3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(1.1);
  }
};

DECLARE_CLASS(ThreadPoolResultRunBool3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(false);
  }
};

DECLARE_CLASS(ThreadPoolResultRunFloat3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(2.2);
  }
};

DECLARE_CLASS(ThreadPoolResultRunLong3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(4);
  }
};

DECLARE_CLASS(ThreadPoolResultRunUint16_3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(5);
  }
};

DECLARE_CLASS(ThreadPoolResultRunUint32_3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(6);
  }
};

DECLARE_CLASS(ThreadPoolResultRunUint64_3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(7);
  }
};

DECLARE_CLASS(ThreadPoolResultRunString3) IMPLEMENTS(Runnable){
public:
  void run() {
    sleep(1);
    this->setResult(String::New("hello"));
  }
};

DECLARE_CLASS(ThreadPoolResultRunObject3) IMPLEMENTS(Runnable){
public:
  void run() {
    ResultData3 r1 = createResultData3();
    r1->value1 = 10;
    r1->value2 = 20;
    sleep(1);
    this->setResult(r1);
  }
};

int testThreadExecutorPoolFutureResultTimeout() {
    while(1) {
        ExecutorService pool = st(Executors)::newFixedThreadPool(1);
        ThreadPoolResultRunInt3 intRun = Thread::NewPoolResultRunInt3();
        Future f = pool->submit(intRun);
        long trace1 = st(System)::CurrentTimeMillis();
        int ret1 = f->getResult(-1,500);
        long interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret1 != -1) {
          printf("testThreadExecutorPoolFutureResultTimeout case1 -------[FAIL],ret1 is %d \n",ret1);
          break;
        }
        sleep(1);

        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case2 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunByte3 byteRun = Thread::NewPoolResultRunByte3();
        f = pool->submit(byteRun);
        trace1 = st(System)::CurrentTimeMillis();
        byte ret2 = f->getResult(99,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret2 != 99) {
          printf("testThreadExecutorPoolFutureResultTimeout case3 -------[FAIL] \n");
          break;
        }
        sleep(1);

        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case4 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunDouble3 doubleRun = Thread::NewPoolResultRunDouble3();
        f = pool->submit(doubleRun);
        trace1 = st(System)::CurrentTimeMillis();
        double ret3 = f->getResult(-1.1,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret3 != -1.1) {
          printf("testThreadExecutorPoolFutureResultTimeout case5 -------[FAIL] \n");
          break;
        }
        sleep(1);

        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case6 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunBool3 boolRun = Thread::NewPoolResultRunBool3();
        f = pool->submit(boolRun);
        trace1 = st(System)::CurrentTimeMillis();
        bool ret3_1 = f->getResult(true,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret3_1 != true) {
          printf("testThreadExecutorPoolFutureResultTimeout case7 -------[FAIL] \n");
          break;
        }
        sleep(1);

        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case8 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunFloat3 floatRun = Thread::NewPoolResultRunFloat3();
        f = pool->submit(floatRun);
        trace1 = st(System)::CurrentTimeMillis();
        float ret4 = f->getResult(-1.1,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(st(Math)::compareFloat(ret4,-1.1) != st(Math)::CompareParamEqual) {
          printf("testThreadExecutorPoolFutureResultTimeout case9 -------[FAIL] \n");
          break;
        }
        sleep(1);
        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case10 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunLong3 longRun = Thread::NewPoolResultRunLong3();
        f = pool->submit(longRun);
        trace1 = st(System)::CurrentTimeMillis();
        long ret5 = f->getResult(-1,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret5 != -1) {
          printf("testThreadExecutorPoolFutureResultTimeout case11 -------[FAIL] \n");
          break;
        }
        sleep(1);

        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case12 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunUint16_3 uint16Run = Thread::NewPoolResultRunUint16_3();
        f = pool->submit(uint16Run);
        trace1 = st(System)::CurrentTimeMillis();
        uint16_t ret6 = f->getResult(1,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret6 != 1) {
          printf("testThreadExecutorPoolFutureResultTimeout case13 -------[FAIL] \n");
          break;
        }
        sleep(1);
        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case14 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunUint32_3 uint32Run = Thread::NewPoolResultRunUint32_3();
        f = pool->submit(uint32Run);
        trace1 = st(System)::CurrentTimeMillis();
        uint32_t ret7 = f->getResult(1,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret7 != 1) {
          printf("testThreadExecutorPoolFutureResultTimeout case15 -------[FAIL] \n");
          break;
        }
        sleep(1);
        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case16 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunUint64_3 uint64Run = Thread::NewPoolResultRunUint64_3();
        f = pool->submit(uint64Run);
        trace1 = st(System)::CurrentTimeMillis();
        uint64_t ret8 = f->getResult(1,500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret8 != 1) {
          printf("testThreadExecutorPoolFutureResultTimeout case17 -------[FAIL] \n");
          break;
        }
        sleep(1);
        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case18 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunString3 stringRun = Thread::NewPoolResultRunString3();
        f = pool->submit(stringRun);
        trace1 = st(System)::CurrentTimeMillis();
        String ret9 = f->getResult(NullData<String>(),500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret9 != nullptr) {
          printf("testThreadExecutorPoolFutureResultTimeout case19 -------[FAIL] \n");
          break;
        }
        sleep(1);
        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case20 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunObject3 objRun = Thread::NewPoolResultRunObject3();
        f = pool->submit(objRun);
        trace1 = st(System)::CurrentTimeMillis();
        ResultData3 ret10 = f->getResult(NullData<ResultData3>(),500);
        interval = st(System)::CurrentTimeMillis() - trace1;
        if(ret10 != nullptr) {
          printf("testThreadExecutorPoolFutureResultTimeout case21 -------[FAIL] \n");
          break;
        }
        sleep(1);
        if(interval > 510 || interval < 500) {
          printf("testThreadExecutorPoolFutureResultTimeout case22 -------[FAIL] \n");
          break;
        }

        printf("testThreadExecutorPoolFutureResultTimeout case23 -------[OK] \n");
        break;
    }
}
