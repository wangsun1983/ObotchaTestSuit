#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderTransferEncoding.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderTransferEncoding c = createHttpHeaderTransferEncoding();
    c->import("gzip, deflate");
    if(!c->toString()->equals("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test toString case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderTransferEncoding c = createHttpHeaderTransferEncoding();
    c->import("gzip, deflate");
    header->setTransferEncoding(c);
    if(!header->getTransferEncoding()->toString()->equals("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test toString case2,v is %s]",header->getContentEncoding()->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderTransferEncoding c = createHttpHeaderTransferEncoding();
    c->add(createString("gzip"));
    c->add(createString("deflate"));
    if(!c->toString()->equals("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test toString case3]");
      break;
    }
    break;
  }
  
  TEST_OK("[HttpHeaderTransferEncoding test toString case100]");

}
