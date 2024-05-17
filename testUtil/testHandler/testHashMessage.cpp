#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HasMessageHandler) IMPLEMENTS(Handler) {
public:

  void handleMessage(Message msg) {
  }

};

void testHasMessage() {
   HasMessageHandler h = HasMessageHandler::New();
   for(int i = 0; i<1024;i++) {
    h->sendEmptyMessageDelayed(1,10000);
   }

   if(!h->hasMessage(1)) {
    TEST_FAIL("[Handler Test {hasMessage} case1]");
   }

   h->removeMessages(1);
   if(h->hasMessage(1)) {
    TEST_FAIL("[Handler Test {hasMessage} case2]");
   }

  TEST_OK("[Handler Test {hasMessage} case3]");

}
