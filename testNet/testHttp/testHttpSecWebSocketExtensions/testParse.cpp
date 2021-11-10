#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpSecWebSocketExtensions.hpp"
#include "HttpMethod.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpSecWebSocketExtensions c = createHttpSecWebSocketExtensions();
    c->import(" permessage-deflate, client_max_window_bits");
    auto list = c->get();
    if(!list->get(0)->equals("permessage-deflate")) {
      printf("---[HttpSecWebSocketExtensions test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("client_max_window_bits")) {
      printf("---[HttpSecWebSocketExtensions test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpSecWebSocketExtensions test Parse case100] [OK]--- \n");

}
