#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCharSetToString() {
  while(1) {
    HttpHeaderAcceptCharSet charset = createHttpHeaderAcceptCharSet();
    charset->import("iso-8859-1");
    if(!charset->toString()->equals("iso-8859-1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptCharSet charset = createHttpHeaderAcceptCharSet();
    charset->import("utf-8, iso-8859-1");
    if(!charset->toString()->equals("utf-8,iso-8859-1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case2] [FAILED],str is %s",charset->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptCharSet charset = createHttpHeaderAcceptCharSet();
    charset->import("utf-8, iso-8859-1;q=0.5, *;q=0.1");
    if(!charset->toString()->equals("utf-8,iso-8859-1;q=0.5,*;q=0.1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptCharSet test toString case100]");

}
