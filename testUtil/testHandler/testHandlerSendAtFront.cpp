#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int v = 0;

DECLARE_CLASS(SendAtFrontHandler) IMPLEMENTS(Handler) {
public:
    void handleMessage(Message msg) {
      switch(msg->what) {
        case 1:
        v = 1;
        break;

        case 2:
        v = 2;
        break;

        case 3:
        v = 3;
        break;
      }
    }

};

void testHandlerSendAtFront() {
  //case 1
  while(1) {
    SendAtFrontHandler h = createSendAtFrontHandler();
    h->post([]{
      sleep(1);
    });

    Message msg1 = createMessage();
    msg1->what = 1;

    Message msg2 = createMessage();
    msg2->what = 2;

    Message msg3 = createMessage();
    msg3->what = 3;

    h->sendMessage(msg1);
    h->sendMessageAtFrontOfQueue(msg2);
    h->sendMessageAtFrontOfQueue(msg3);

    usleep(1000*1100);
    if(v != 1) {
      TEST_FAIL("[Handler Test {Send At Front} case1],v is %d",v);
    }
    break;
  }

  //case 1
  while(1) {
    v = 0;
    SendAtFrontHandler h = createSendAtFrontHandler();
    h->post([]{
      sleep(1);
    });

    Message msg1 = createMessage();
    msg1->what = 1;

    Message msg2 = createMessage();
    msg2->what = 2;

    Message msg3 = createMessage();
    msg3->what = 3;

    h->sendMessageAtFrontOfQueue(msg2);
    h->sendMessageAtFrontOfQueue(msg3);

    usleep(1000*1100);
    if(v != 2) {
      TEST_FAIL("[Handler Test {Send At Front} case2],v is %d",v);
    }
    break;
  }

  TEST_OK("[Handler Test {Send At Front} case100]");
}
