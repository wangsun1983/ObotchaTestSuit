#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testEncodingToString() {
  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->load("text/html");
    if(!encoding1->toString()->sameAs("text/html")) {
      TEST_FAIL("[HttpHeaderAccept test toString case1]encoding is %s",encoding1->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->load("image/*");
    if(!encoding1->toString()->sameAs("image/*")) {
      TEST_FAIL("[HttpHeaderAccept test toString case2]encoding is %s",encoding1->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->load("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    if(!encoding1->toString()->sameAs("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8")) {
      TEST_FAIL("[HttpHeaderAccept test toString case3]encoding is %s",encoding1->toString()->toChars());
    }
    break;
  }
  
  while(1) {
    HttpHeaderAccept accept = createHttpHeaderAccept();
    HttpHeader header = createHttpHeader();
    accept->load("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    header->setAccept(accept);
    
    auto encoding1 = header->getAccept();
    if(!encoding1->toString()->sameAs("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8")) {
      TEST_FAIL("[HttpHeaderAccept test toString case4]encoding is %s",encoding1->toString()->toChars());
    }
    break;
  }


  TEST_OK("[HttpHeaderAccept test toString case100]");

}
