#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderForwarded.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Forwarded"),createString("For=\"[2001:db8:cafe::17]:4711\""));
    auto encoding1 = header->getForwarded();
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case1]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->sameAs("[2001:db8:cafe::17]:4711")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Forwarded"),createString("For=\"[2001:db8:cafe::17]:4711\""));
    auto encoding1 = header->getForwarded();
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case3]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->sameAs("[2001:db8:cafe::17]:4711")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case4]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Forwarded"),createString("for=\"_mdn\""));
    auto encoding1 = header->getForwarded();
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case5]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->sameAs("_mdn")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case6]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Forwarded"),createString("for=192.0.2.60; proto=http; by=203.0.113.43"));
    auto encoding1 = header->getForwarded();
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case5]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->sameAs("192.0.2.60")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case6]");
      break;
    }

    if(!encoding1->proto->sameAs("http")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case7]");
      break;
    }

    if(!encoding1->byIdentity->sameAs("203.0.113.43")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case8]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderForwarded forward = createHttpHeaderForwarded();
    forward->load("for=192.0.2.60; proto=http; by=203.0.113.43");
    header->setForwarded(forward);
    auto encoding1 = header->getForwarded();
    if(encoding1->forIdentities->size() != 1) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case9]");
      break;
    }

    if(!encoding1->forIdentities->get(0)->sameAs("192.0.2.60")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case10]");
      break;
    }

    if(!encoding1->proto->sameAs("http")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case11]");
      break;
    }

    if(!encoding1->byIdentity->sameAs("203.0.113.43")) {
      TEST_FAIL("[HttpHeaderForwarded test setToHeader case12]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderForwarded test setToHeader case100]");

}
