#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderContentEncoding.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentEncoding c = HttpHeaderContentEncoding::New();
    c->load("gzip, deflate");
    if(!c->toString()->sameAs("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderContentEncoding test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    HttpHeaderContentEncoding c = HttpHeaderContentEncoding::New();
    c->load("gzip, deflate");
    header->setContentEncoding(c);
    if(!header->getContentEncoding()->toString()->sameAs("gzip, deflate")) {
      TEST_FAIL("[HttpHeaderContentEncoding test toString case2]");
      break;
    }
    break;
  }
  TEST_OK("[HttpHeaderContentEncoding test toString case100]");

}
