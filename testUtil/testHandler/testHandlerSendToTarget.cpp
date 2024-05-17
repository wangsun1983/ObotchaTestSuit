#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Thread.hpp"

using namespace obotcha;

int value11 = 0;

DECLARE_CLASS(SendTargeHandler) IMPLEMENTS(Handler) {
public:
    void handleMessage(Message msg) {
		switch(msg->what) {
			case 100:
			value11 = 1122;
		}
    }
};

void testHandlerSendToTarget() {
  SendTargeHandler h = SendTargeHandler::New();
  auto message = h->obtainMessage(100);
  
  Thread t1 = Thread::New([&]{
	  message->sendToTarget();
  });
  t1->start();
  
  t1->join();
  usleep(1000*100);
  
  if(value11 != 1122) {
	TEST_OK("[Handler Test {SendToTarget} case1]");  
  }

  TEST_OK("[Handler Test {SendToTarget} case100]");
}
