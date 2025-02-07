#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderTransferEncoding.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderTransferEncoding c = HttpHeaderTransferEncoding::New();
    c->load("gzip, deflate");
    auto list = c->get();
    if(!list->get(0)->sameAs("gzip")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test Parse case1]");
      break;
    }

    if(!list->get(1)->sameAs("deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test Parse case2]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderTransferEncoding c = HttpHeaderTransferEncoding::New("gzip, deflate");
    auto list = c->get();
    if(!list->get(0)->sameAs("gzip")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test Parse case3]");
      break;
    }

    if(!list->get(1)->sameAs("deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test Parse case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderTransferEncoding test Parse case100]");

}
