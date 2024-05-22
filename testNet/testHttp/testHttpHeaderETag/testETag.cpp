#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderETag.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testETagParse() {
  while(1) {
    HttpHeaderETag p = HttpHeaderETag::New();
    p->load("\"33a64df551425fcc55e4d42a148795d9f25f89d4\"");

    if(p->isWeakCheck()) {
      TEST_FAIL("[HttpHeaderETag test parse case1]");
    }

    if(!p->getValue()->sameAs("33a64df551425fcc55e4d42a148795d9f25f89d4")) {
      TEST_FAIL("[HttpHeaderETag test parse case2]");
    }
    break;
  }

  while(1) {
    HttpHeaderETag p = HttpHeaderETag::New();
    p->load("W/\"0815\"");

    if(!p->isWeakCheck()) {
      TEST_FAIL("[HttpHeaderETag test parse case3]");
    }

    if(!p->getValue()->sameAs("0815")) {
      TEST_FAIL("[HttpHeaderETag test parse case4]");
    }
    break;
  }
  TEST_OK("[HttpHeaderETag test Parse case100]");

}
