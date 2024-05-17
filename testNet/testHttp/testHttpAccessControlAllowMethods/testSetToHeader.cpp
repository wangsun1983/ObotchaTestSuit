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
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Access-Control-Allow-Methods"),String::New("POST, GET, OPTIONS"));
    
    auto c = header->getAllowMethods();
    c->load("POST, GET, OPTIONS");
    auto list = c->get();
    if(list[0] != st(HttpMethod)::Id::Post) {
      TEST_FAIL("[HttpHeaderAccessControlAllowMethods test setToHeader case1]");
      break;
    }

    if(list[1] != st(HttpMethod)::Id::Get) {
      TEST_FAIL("[HttpHeaderAccessControlAllowMethods test setToHeader case2]");
      break;
    }

    if(list[2] != st(HttpMethod)::Id::Options) {
      TEST_FAIL("[HttpHeaderAccessControlAllowMethods test setToHeader case3]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderAccessControlAllowMethods test setToHeader case100]");

}
