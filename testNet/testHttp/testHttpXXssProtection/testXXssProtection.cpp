#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderXXssProtection.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testEncodingParse() {
  while(1) {
    HttpHeaderXXssProtection p = HttpHeaderXXssProtection::New();
    p->load("0");

    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Disable) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case1]");
    }

    p->load("1");
    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Enable) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case2]");
    }

    p->load("1; mode=block");
    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Block) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case3]");
    }

    p->load("1; report=abc.hpp");
    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Report) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case4]");
    }

    if(!p->getReportUrl()->sameAs("abc.hpp")) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case5,url is %s]",p->getReportUrl()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderXXssProtection p = HttpHeaderXXssProtection::New();
    p->load(" 0");

    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Disable) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case6]");
    }

    p->load("1 ");
    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Enable) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case7]");
    }

    p->load(" 1;  mode=block");
    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Block) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case8]");
    }

    p->load(" 1 ; report =abc.hpp");
    if(p->getType() != st(HttpHeaderXXssProtection)::Type::Report) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case9]");
    }

    if(!p->getReportUrl()->sameAs("abc.hpp")) {
      TEST_FAIL("[HttpHeaderXXssProtection test Parse case10,url is %s]",p->getReportUrl()->toChars());
    }
    break;
  }
  TEST_OK("[HttpHeaderXXssProtection test Parse case100]");

}
