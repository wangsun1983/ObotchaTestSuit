#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAllow.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAllow c = createHttpHeaderAllow();
    c->load("POST, GET, OPTIONS");
    if(!c->toString()->equals("POST, GET, OPTIONS")) {
      TEST_FAIL("[HttpHeaderAllow test toString case1],str is %s\n",c->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderAllow c = createHttpHeaderAllow();
    c->load("POST, GET, OPTIONS");
    header->setAllow(c);
    
    auto c2 = header->getAllow();
    if(!c2->toString()->equals("POST, GET, OPTIONS")) {
      TEST_FAIL("[HttpHeaderAllow test toString case1],str is %s\n",c2->toString()->toChars());
      break;
    }
    break;
  }
  TEST_OK("[HttpHeaderAllow test toString case100]");

}
