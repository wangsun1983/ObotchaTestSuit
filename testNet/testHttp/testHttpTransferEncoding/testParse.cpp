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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Transfer-Encoding"),
                createString("gzip, deflate"));
    auto c = header->getTransferEncoding();
    auto list = c->get();
    if(!list->get(0)->equals("gzip")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test SetToHeader case1]");
      break;
    }

    if(!list->get(1)->equals("deflate")) {
      TEST_FAIL("[HttpHeaderTransferEncoding test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderTransferEncoding test SetToHeader case100]");

}
