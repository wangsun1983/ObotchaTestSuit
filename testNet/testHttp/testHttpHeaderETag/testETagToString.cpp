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

void testEtagToString() {
  while(1) {
    HttpHeaderETag tag = HttpHeaderETag::New();
    tag->setWeakCheck(false);
    tag->setValue(String::New("33a64df551425fcc55e4d42a148795d9f25f89d4"));
    if(!tag->toString()->sameAs("\"33a64df551425fcc55e4d42a148795d9f25f89d4\"")) {
      TEST_FAIL("[HttpHeaderETag test toString case1]");
    }
    break;
  }

  while(1) {
    HttpHeaderETag tag = HttpHeaderETag::New();
    tag->setWeakCheck(true);
    tag->setValue(String::New("0815"));
    if(!tag->toString()->sameAs("W/\"0815\"")) {
      TEST_FAIL("[HttpHeaderETag test toString case2]");
    }
    break;
  }


  TEST_OK("[HttpHeaderETag test toString case100]");

}
