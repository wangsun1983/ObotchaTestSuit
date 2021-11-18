#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderSecWebSocketExtensions.hpp"
#include "HttpMethod.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecWebSocketExtensions c = createHttpHeaderSecWebSocketExtensions();
    c->import(" permessage-deflate, client_max_window_bits");
    auto list = c->get();
    if(!list->get(0)->equals("permessage-deflate")) {
      printf("---[HttpHeaderSecWebSocketExtensions test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("client_max_window_bits")) {
      printf("---[HttpHeaderSecWebSocketExtensions test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecWebSocketExtensions test Parse case100] [OK]--- \n");

}
