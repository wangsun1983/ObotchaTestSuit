#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
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

CountDownLatch lambdaLatch = CountDownLatch::New(1);

void testAsyncProcessMqLambda() {
    
    int pid = fork();
    if(pid == 0) {
      sleep(1);
      ProcessMq sendMq = ProcessMq::New("lambd_test1",false);
      sleep(2);
      String s = String::New("hello world");
      int ret = sendMq->send(s->toByteArray());
	  sendMq->close();
      exit(0);
    } else {
      ProcessMq readMq1 = ProcessMq::New("lambd_test1",true);
	  readMq1->setListener([](ByteArray data){
        if(!data->toString()->sameAs("hello world")) {
          TEST_FAIL("AsyncProcessMqLambda case1");
        }
        lambdaLatch->countDown();
      });
	  
      lambdaLatch->await();
      readMq1->clear();
	  int status = 0;
	  waitpid(pid,&status,0);
	  readMq1->close();
    }

    TEST_OK("[ProcessMq Test AsyncProcessMqLambda case100]");
}
