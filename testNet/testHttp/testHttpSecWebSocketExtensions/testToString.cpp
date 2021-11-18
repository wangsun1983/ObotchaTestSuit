#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderSecWebSocketExtensions.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSecWebSocketExtensions c = createHttpHeaderSecWebSocketExtensions();
    c->import(" permessage-deflate, client_max_window_bits");
    if(!c->toString()->equals("permessage-deflate, client_max_window_bits")) {
      printf("---[HttpHeaderSecWebSocketExtensions test toString case1] [FAILED]--- ,str is %s\n",c->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecWebSocketExtensions test toString case100] [OK]--- \n");

}
