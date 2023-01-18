#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ProcessMq.hpp"
#include "System.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
#include "CountDownLatch.hpp"

using namespace obotcha;

CountDownLatch lambdaLatch = createCountDownLatch(1);

void testAsyncProcessMqLambda() {
    
    int pid = fork();
    if(pid == 0) {
      ProcessMq sendMq = createProcessMq("lambdactest2",st(ProcessMq)::Send);
      sleep(1);
      String s = createString("hello world");
      sendMq->send(s->toByteArray());
      exit(0);
    } else {
      ProcessMq readMq1 = createProcessMq("lambdactest2",[](ByteArray data){
        if(!data->toString()->equals("hello world")) {
          TEST_FAIL("AsyncProcessMqLambda case1");
        }
        lambdaLatch->countDown();
      });
      lambdaLatch->await();
      readMq1->clear();
    }

    

    TEST_OK("[ProcessMq Test AsyncProcessMqLambda case100]");
}
