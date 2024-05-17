#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderContentEncoding.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Content-Encoding"),
                String::New("gzip, deflate"));
    auto c = header->getContentEncoding();
    auto list = c->get();
    if(!list->get(0)->sameAs("gzip")) {
      TEST_FAIL("[HttpHeaderContentEncoding test SetToHeader case1]");
      break;
    }

    if(!list->get(1)->sameAs("deflate")) {
      TEST_FAIL("[HttpHeaderContentEncoding test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentEncoding test SetToHeader case100]");

}
