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

CountDownLatch posixMqLatch = createCountDownLatch(1);

DECLARE_CLASS(PosixTestListener) IMPLEMENTS(PosixMqListener){
public:
  void onData(ByteArray data) {
      if(!data->toString()->equals("hello world")) {
        TEST_FAIL("testAsyncPosixMq case1");
      }

      posixMqLatch->countDown();
  }
};

void testAsyncPosixMq() {
    int pid = fork();
    if(pid == 0) {
      sleep(1);
      PosixMq sendMq = createPosixMq("asynctest2",st(PosixMq)::Send);
      String s = createString("hello world");
      sendMq->send(s->toByteArray());
      exit(0);
    } else {
      PosixMq readMq1 = createPosixMq("asynctest2",createPosixTestListener());
      posixMqLatch->await();
      readMq1->clear();
    }

    TEST_OK("[PosixMq Test AsyncPosixMq case100]");
}
