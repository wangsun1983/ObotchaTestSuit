#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->import(" websocket ");
    if(!upgrade->toString()->equals("websocket")) {
      printf("---[HttpHeaderUpgrade test toString case1] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderUpgrade test toString case100] [OK]--- \n");
}
