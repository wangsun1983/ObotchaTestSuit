#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

#define EMPTY_MESSAGE 1
#define EMPTY_DELAYED_MESSAGE 2
DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  _MyHandler() {
    count = 0;
    delayedCount = 0;
  }

  void handleMessage(Message msg) {
    switch(msg->what) {
      case EMPTY_MESSAGE:
      count += 1;
      break;

      case EMPTY_DELAYED_MESSAGE:
      delayedCount+= 1;
      break;
    }

  }

  int count;
  int delayedCount;
};

void testHandler() {
  MyHandler m = createMyHandler();
  for(int i = 0;i<1024*32;i++) {
    m->sendEmptyMessage(EMPTY_MESSAGE);
  }

  for(int j = 0;j<1024*32;j++) {
    m->sendEmptyMessageDelayed(EMPTY_DELAYED_MESSAGE,100);
  }

  sleep(10);
  if(m->count != 32*1024 || m->delayedCount != 32*1024) {
    TEST_FAIL("[Handler Test {Normal sendEmptyMessage/Delayed()} case1]");
  }

  TEST_OK("[Handler Test {Normal sendEmptyMessage/Delayed()} case2]");
}
