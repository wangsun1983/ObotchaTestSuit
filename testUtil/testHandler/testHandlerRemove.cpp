#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestHandler2) IMPLEMENTS(Handler) {
public:
  _MyTestHandler2() {
  }

  void handleMessage(Message msg) {
      //TEST_FAIL("msg arg1 is %d",msg->arg1);
      count++;
  }

  int count;
};


void testHandlerRemove() {
  //case 1
  while(1) {
    MyTestHandler2 handler = MyTestHandler2::New();
    handler->sendEmptyMessageDelayed(1,1000*2);
    handler->sendEmptyMessageDelayed(1,1000*2);
    handler->sendEmptyMessageDelayed(1,1000*2);

    handler->removeMessages(1);
    if(handler->size() != 0) {
      TEST_FAIL("[Handler Test {Handler Remove} case1],handler size is %d",handler->size());
    }

    TEST_OK("[Handler Test {Handler Remove} case2]");
    break;
  }

  //case 2
  while(1) {
    MyTestHandler2 handler = MyTestHandler2::New();
    handler->sendEmptyMessageDelayed(1,1000*2);
    handler->sendEmptyMessageDelayed(2,1000*2);
    handler->sendEmptyMessageDelayed(3,1000*2);

    handler->removeMessages(1);
    if(handler->size() != 2) {
      TEST_FAIL("[Handler Test {Handler Remove} case3],handler size is %d",handler->size());
    }

    TEST_OK("[Handler Test {Handler Remove} case4]");
    break;
  }

  TEST_OK("[Handler Test {Handler Remove} case5]");
}
