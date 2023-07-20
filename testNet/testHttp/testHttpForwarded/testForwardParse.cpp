#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderForwarded.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testForwardedParse() {
  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->load("For=\"[2001:db8:cafe::17]:4711\"");
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case1]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("[2001:db8:cafe::17]:4711")) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->load("For=\"[2001:db8:cafe::17]:4711\"");
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case3]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("[2001:db8:cafe::17]:4711")) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case4]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->load("for=\"_mdn\"");
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case5]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("_mdn")) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case6]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->load("for=192.0.2.60; proto=http; by=203.0.113.43");
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case5]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("192.0.2.60")) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case6]");
      break;
    }

    if(!encoding1->proto->equals("http")) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case7]");
      break;
    }

    if(!encoding1->byIdentity->equals("203.0.113.43")) {
      TEST_FAIL("[HttpHeaderForwarded test Parse case8]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderForwarded test Parse case100]");

}
