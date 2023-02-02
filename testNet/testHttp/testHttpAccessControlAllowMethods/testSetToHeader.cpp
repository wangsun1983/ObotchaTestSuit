#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowMethods.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Access-Control-Allow-Methods"),createString("POST, GET, OPTIONS"));
    
    auto c = header->getAllowMethods();
    c->import("POST, GET, OPTIONS");
    auto list = c->get();
    if(list->get(0)->toValue() != st(HttpMethod)::Post) {
      TEST_FAIL("[HttpHeaderAccessControlAllowMethods test setToHeader case1]");
      break;
    }

    if(list->get(1)->toValue() != st(HttpMethod)::Get) {
      TEST_FAIL("[HttpHeaderAccessControlAllowMethods test setToHeader case2]");
      break;
    }

    if(list->get(2)->toValue() != st(HttpMethod)::Options) {
      TEST_FAIL("[HttpHeaderAccessControlAllowMethods test setToHeader case3]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderAccessControlAllowMethods test setToHeader case100]");

}
