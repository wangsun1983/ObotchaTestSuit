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

CountDownLatch ProcessMqLatch = createCountDownLatch(1);

DECLARE_CLASS(PosixTestListener) IMPLEMENTS(ProcessMqListener){
public:
  void onData(ByteArray data) {
      if(!data->toString()->equals("hello world")) {
        TEST_FAIL("testAsyncProcessMq case1");
      }

      ProcessMqLatch->countDown();
  }
};

void testAsyncProcessMq() {
    int pid = fork();
    if(pid == 0) {
      sleep(1);
      ProcessMq sendMq = createProcessMq("asynctest2",st(ProcessMq)::Send);
      String s = createString("hello world");
      sendMq->send(s->toByteArray());
      exit(0);
    } else {
      ProcessMq readMq1 = createProcessMq("asynctest2",createPosixTestListener());
      ProcessMqLatch->await();
      readMq1->clear();
    }

    TEST_OK("[ProcessMq Test AsyncProcessMq case100]");
}
