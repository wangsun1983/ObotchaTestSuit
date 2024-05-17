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
    HttpHeaderTransferEncoding c = HttpHeaderTransferEncoding::New();
    c->load("gzip, deflate");
    if(!c->toString()->sameAs("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test toString case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = HttpHeader::New();
    HttpHeaderTransferEncoding c = HttpHeaderTransferEncoding::New();
    c->load("gzip, deflate");
    header->setTransferEncoding(c);
    if(!header->getTransferEncoding()->toString()->sameAs("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test toString case2,v is %s]",header->getContentEncoding()->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderTransferEncoding c = HttpHeaderTransferEncoding::New();
    c->add(String::New("gzip"));
    c->add(String::New("deflate"));
    if(!c->toString()->sameAs("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test toString case3]");
      break;
    }
    break;
  }
  
  TEST_OK("[HttpHeaderTransferEncoding test toString case100]");

}
