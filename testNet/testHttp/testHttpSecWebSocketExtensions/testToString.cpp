#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpSecWebSocketExtensions.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpSecWebSocketExtensions c = createHttpSecWebSocketExtensions();
    c->import(" permessage-deflate, client_max_window_bits");
    if(!c->toString()->equals("permessage-deflate, client_max_window_bits")) {
      printf("---[HttpSecWebSocketExtensions test toString case1] [FAILED]--- ,str is %s\n",c->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpSecWebSocketExtensions test toString case100] [OK]--- \n");

}
