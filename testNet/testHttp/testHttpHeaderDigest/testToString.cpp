#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDigest.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderDigest digest = createHttpHeaderDigest();
    digest->import(" sha-256=X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=");
    if(!digest->toString()->equals("sha-256=X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=")) {
      TEST_FAIL("[testHttpHeaderDigest test toString case1]");
    }

    break;
  }

  while(1) {
    HttpHeaderDigest digest = createHttpHeaderDigest();
    digest->import(" sha-256=X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=,unixsum=30637");
    if(!digest->toString()->equals("sha-256=X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=,unixsum=30637")) {
      TEST_FAIL("[testHttpHeaderDigest test toString case2]");
    }
    break;
  }

  TEST_OK("[testHttpHeaderDigest test toString case100]");
}
