#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "PosixMq.hpp"
#include "System.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
#include "CountDownLatch.hpp"

using namespace obotcha;

CountDownLatch lambdaLatch = createCountDownLatch(1);

void testAsyncPosixMqLambda() {
    
    int pid = fork();
    if(pid == 0) {
      PosixMq sendMq = createPosixMq("lambdactest2",st(PosixMq)::Send);
      sleep(1);
      String s = createString("hello world");
      sendMq->send(s->toByteArray());
      exit(0);
    } else {
      PosixMq readMq1 = createPosixMq("lambdactest2",[](ByteArray data){
        if(!data->toString()->equals("hello world")) {
          TEST_FAIL("AsyncPosixMqLambda case1");
        }
        lambdaLatch->countDown();
      });
      lambdaLatch->await();
      readMq1->clear();
    }

    

    TEST_OK("[PosixMq Test AsyncPosixMqLambda case100]");
}
