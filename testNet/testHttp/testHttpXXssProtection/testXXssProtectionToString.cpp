#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"
#include "HttpHeaderXXssProtection.hpp"

using namespace obotcha;

void testXXssProtectionToString() {
  while(1) {
    HttpHeaderXXssProtection p = HttpHeaderXXssProtection::New();
    //p->load("0");
    p->set(st(HttpHeaderXXssProtection)::Type::Disable);
    if(!p->toString()->sameAs("0")) {
      TEST_FAIL("[HttpHeaderXXssProtection test toString case1]");
    }

    p->set(st(HttpHeaderXXssProtection)::Type::Enable);
    if(!p->toString()->sameAs("1")) {
      TEST_FAIL("[HttpHeaderXXssProtection test toString case2]");
    }

    p->set(st(HttpHeaderXXssProtection)::Type::Block);
    if(!p->toString()->sameAs("1; mode=block")) {
      TEST_FAIL("[HttpHeaderXXssProtection test toString case3]");
    }

    p->set(st(HttpHeaderXXssProtection)::Type::Report,String::New("aabb.cpp"));
    if(!p->toString()->sameAs("1; report=aabb.cpp")) {
      TEST_FAIL("[HttpHeaderXXssProtection test toString case4]");
    }

    break;

  }


  TEST_OK("[HttpHeaderAccept test toString case100]");

}
