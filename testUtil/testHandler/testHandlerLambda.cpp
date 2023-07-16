#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHandlerLambda() {
  Handler h = createHandler();
  while(1) {
    int value = 100;
    h->post([&value]() {
      if(value == 100) {
        value = 123;
      }
    });
    sleep(1);

    if(value != 123) {
      TEST_FAIL("[HandlerLambda Test Start case1]");
      break;
    }

    TEST_OK("[HandlerLambda Test Start case2]");
    break;
  }

  while(1) {
    int value = 100;
    long current = st(System)::CurrentTimeMillis();
    long next = 0;
    h->postDelayed(3000,[&next]() {
      next = st(System)::CurrentTimeMillis();
    });
    sleep(4);

    if(next - current > 3005 || current - next > 3005) {
      TEST_FAIL("[HandlerLambda Test case3]");
      break;
    }

    TEST_OK("[HandlerLambda Test case4]");
    break;
  }
}
