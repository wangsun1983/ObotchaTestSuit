#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Allow"),
                createString(" POST, GET, OPTIONS"));
    auto c = header->getAllow();
    auto list = c->get();
    if(list[0] != st(HttpMethod)::Id::Post) {
      TEST_FAIL("[HttpHeaderAllow test setToHeader case1]");
      break;
    }

    if(list[1] != st(HttpMethod)::Id::Get) {
      TEST_FAIL("[HttpHeaderAllow test setToHeader case2]");
      break;
    }

    if(list[2] != st(HttpMethod)::Id::Options) {
      TEST_FAIL("[HttpHeaderAllow test setToHeader case3]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderAllow test setToHeader case100]");

}
