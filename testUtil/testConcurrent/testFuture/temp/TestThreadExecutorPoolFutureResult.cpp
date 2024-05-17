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

DECLARE_CLASS(ResultData1) {
public:
  int value1;
  int value2;
};

DECLARE_CLASS(ThreadPoolResultRunInt) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(1);
  }
};

DECLARE_CLASS(ThreadPoolResultRunByte) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(1);
  }
};

DECLARE_CLASS(ThreadPoolResultRunDouble) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(1.1);
  }
};

DECLARE_CLASS(ThreadPoolResultRunBool) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(false);
  }
};

DECLARE_CLASS(ThreadPoolResultRunFloat) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(2.2);
  }
};

DECLARE_CLASS(ThreadPoolResultRunLong) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(4);
  }
};

DECLARE_CLASS(ThreadPoolResultRunUint16) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(5);
  }
};

DECLARE_CLASS(ThreadPoolResultRunUint32) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(6);
  }
};

DECLARE_CLASS(ThreadPoolResultRunUint64) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(7);
  }
};

DECLARE_CLASS(ThreadPoolResultRunString) IMPLEMENTS(Runnable){
public:
  void run() {
    this->setResult(String::New("hello"));
  }
};

DECLARE_CLASS(ThreadPoolResultRunObject) IMPLEMENTS(Runnable){
public:
  void run() {
    ResultData1 r1 = createResultData1();
    r1->value1 = 10;
    r1->value2 = 20;
    this->setResult(r1);
  }
};

int testThreadExecutorPoolFutureResult() {

    while(1) {
        ExecutorService pool = st(Executors)::newFixedThreadPool(1);
        ThreadPoolResultRunInt intRun = Thread::NewPoolResultRunInt();
        Future f = pool->submit(intRun);
        int ret1 = f->getResult(-1);
        if(ret1 != 1) {
          printf("testThreadExecutorPoolFutureResult case1 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunByte byteRun = Thread::NewPoolResultRunByte();
        f = pool->submit(byteRun);
        byte ret2 = f->getResult(-1);
        if(ret2 != 1) {
          printf("testThreadExecutorPoolFutureResult case2 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunDouble doubleRun = Thread::NewPoolResultRunDouble();
        f = pool->submit(doubleRun);
        double ret3 = f->getResult(-1.1);
        if(ret3 != 1.1) {
          printf("testThreadExecutorPoolFutureResult case3 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunBool boolRun = Thread::NewPoolResultRunBool();
        f = pool->submit(boolRun);
        bool ret3_1 = f->getResult(-1.1);
        if(ret3_1 != false) {
          printf("testThreadExecutorPoolFutureResult case4 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunFloat floatRun = Thread::NewPoolResultRunFloat();
        f = pool->submit(floatRun);
        float ret4 = f->getResult(-1.1);
        if(st(Math)::compareFloat(ret4,2.2) != st(Math)::CompareParamEqual) {
          printf("testThreadExecutorPoolFutureResult case5 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunLong longRun = Thread::NewPoolResultRunLong();
        f = pool->submit(longRun);
        long ret5 = f->getResult(-1);
        if(ret5 != 4) {
          printf("testThreadExecutorPoolFutureResult case6 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunUint16 uint16Run = Thread::NewPoolResultRunUint16();
        f = pool->submit(uint16Run);
        uint16_t ret6 = f->getResult(1);
        if(ret6 != 5) {
          printf("testThreadExecutorPoolFutureResult case7 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunUint32 uint32Run = Thread::NewPoolResultRunUint32();
        f = pool->submit(uint32Run);
        uint32_t ret7 = f->getResult(1);
        if(ret7 != 6) {
          printf("testThreadExecutorPoolFutureResult case8 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunUint64 uint64Run = Thread::NewPoolResultRunUint64();
        f = pool->submit(uint64Run);
        uint64_t ret8 = f->getResult(1);
        if(ret8 != 7) {
          printf("testThreadExecutorPoolFutureResult case9 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunString stringRun = Thread::NewPoolResultRunString();
        f = pool->submit(stringRun);
        String ret9 = f->getResult(NullData<String>());
        if(!ret9->sameAs("hello")) {
          printf("testThreadExecutorPoolFutureResult case10 -------[FAIL] \n");
          break;
        }

        ThreadPoolResultRunObject objRun = Thread::NewPoolResultRunObject();
        f = pool->submit(objRun);
        ResultData1 ret10 = f->getResult(NullData<ResultData1>());
        if(ret10 == nullptr || ret10->value1 != 10 ||ret10->value2 != 20) {
          printf("testThreadExecutorPoolFutureResult case11 -------[FAIL] \n");
          break;
        }
        printf("testThreadExecutorPoolFutureResult case12 -------[OK] \n");
        break;
    }
}
