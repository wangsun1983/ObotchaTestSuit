#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyHandler1) IMPLEMENTS(Handler) {
public:
  _MyHandler1() {

  }

  void handleMessage(Message msg) {

  }

  int count;
  int delayedCount;
};

void testHandlerSize() {
  //case 1
  while(1) {
    MyHandler1 handler1 = createMyHandler1();
    handler1->sendEmptyMessageDelayed(1,1000*10);
    handler1->sendEmptyMessageDelayed(2,1000*10);
    handler1->sendEmptyMessageDelayed(3,1000*10);
    handler1->sendEmptyMessageDelayed(4,1000*10);

    if(handler1->size() != 4) {
      TEST_FAIL("[Handler Test {Normal size()} case1]");
      break;
    }

    TEST_OK("[Handler Test {Normal size()} case2]");
    break;
  }

  //case 2
  while(1) {
    MyHandler1 handler1 = createMyHandler1();
    handler1->sendEmptyMessage(1);
    handler1->sendEmptyMessageDelayed(2,1000*10);
    handler1->sendEmptyMessageDelayed(3,1000*10);
    handler1->sendEmptyMessageDelayed(4,1000*10);
    usleep(100);
    if(handler1->size() != 3) {
      TEST_FAIL("[Handler Test {Normal size()} case3]");
      break;
    }

    TEST_OK("[Handler Test {Normal size()} case4]");
    break;
  }

  //case 3
  while(1) {
    MyHandler1 handler1 = createMyHandler1();
    handler1->sendEmptyMessage(1);
    handler1->sendEmptyMessage(2);
    handler1->sendEmptyMessage(3);
    usleep(100*5);
    if(handler1->size() != 0) {
      TEST_FAIL("[Handler Test {Normal size()} case5]");
      break;
    }

    TEST_OK("[Handler Test {Normal size()} case6]");
    break;
  }

  TEST_OK("[Handler Test {Normal size()} case7]");
}
