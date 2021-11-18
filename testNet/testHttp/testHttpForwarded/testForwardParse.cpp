#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderForwarded.hpp"
#include "Math.hpp"

using namespace obotcha;

void testForwardedParse() {
  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("For=\"[2001:db8:cafe::17]:4711\"");
    if(encoding1->forIdentities->size() != 1) {
      printf("---[HttpHeaderForwarded test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("[2001:db8:cafe::17]:4711")) {
      printf("---[HttpHeaderForwarded test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("For=\"[2001:db8:cafe::17]:4711\"");
    if(encoding1->forIdentities->size() != 1) {
      printf("---[HttpHeaderForwarded test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("[2001:db8:cafe::17]:4711")) {
      printf("---[HttpHeaderForwarded test Parse case4] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("for=\"_mdn\"");
    if(encoding1->forIdentities->size() != 1) {
      printf("---[HttpHeaderForwarded test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("_mdn")) {
      printf("---[HttpHeaderForwarded test Parse case6] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderForwarded encoding1 = createHttpHeaderForwarded();
    encoding1->import("for=192.0.2.60; proto=http; by=203.0.113.43");
    if(encoding1->forIdentities->size() != 1) {
      printf("---[HttpHeaderForwarded test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!encoding1->forIdentities->get(0)->equals("192.0.2.60")) {
      printf("---[HttpHeaderForwarded test Parse case6] [FAILED]--- \n");
      break;
    }

    if(!encoding1->proto->equals("http")) {
      printf("---[HttpHeaderForwarded test Parse case7] [FAILED]--- \n");
      break;
    }

    if(!encoding1->byIdentity->equals("203.0.113.43")) {
      printf("---[HttpHeaderForwarded test Parse case8] [FAILED]--- \n");
      break;
    }
    break;
  }


  printf("---[HttpHeaderForwarded test Parse case100] [OK]--- \n");

}
