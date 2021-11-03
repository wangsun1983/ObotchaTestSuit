#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->import(" websocket ");
    if(!upgrade->get()->equals("websocket")) {
      printf("---[HttpHeaderUpgrade test Parse case1] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderUpgrade test Parse case100] [OK]--- \n");
}
