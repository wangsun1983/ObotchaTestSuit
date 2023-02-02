#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderSecWebSocketVersion.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetSet() {
  while(1) {
    HttpHeaderSecWebSocketVersion c = createHttpHeaderSecWebSocketVersion();
    c->set(13);
    if(!c->toString()->equals("13")) {
      TEST_FAIL("[HttpHeaderSecWebSocketVersion test GetSet case1],str is %s",c->toString()->toChars());
      break;
    }
    
    if(c->get() != 13) {
      TEST_FAIL("[HttpHeaderSecWebSocketVersion test GetSet case2],str is %s",c->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketVersion test GetSet case100]");

}
