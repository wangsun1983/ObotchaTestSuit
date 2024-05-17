#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int send_v = 0;

DECLARE_CLASS(SendDelayedHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
      switch(msg->what) {
        case 1:
        send_v++;
        break;

        case 0:
        send_v = 0;
        break;
      }
  }
};

void testHandlerSendDelayed() {
  //case 1
  while(1) {
    SendDelayedHandler handler = SendDelayedHandler::New();
    handler->sendEmptyMessageDelayed(0,1000);
    handler->sendEmptyMessage(1);
    usleep(1000*5);
    if(send_v != 1) {
      TEST_FAIL("[Handler Test {Send Delayed} case1],v is %d",send_v);
    }

    handler->sendEmptyMessage(1);
    usleep(1000*5);
    if(send_v != 2) {
      TEST_FAIL("[Handler Test {Send Delayed} case2],v is %d",send_v);
    }

    break;
  }


  TEST_OK("[Handler Test {Send Delayed} case100]");
}
