#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void testAcceptAdd() {
  while(1) {
    HttpHeaderAccept accept = createHttpHeaderAccept();
    accept->add("text/html");
    accept->add("application/xhtml+xml");
    accept->add("application/xml",0.9);
    accept->add("*/*",0.8);
    
    if(!accept->toString()->sameAs("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8")) {
      TEST_FAIL("[HttpHeaderAccept test add case3]accept is %s",accept->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderAccept test add case100]");

}
