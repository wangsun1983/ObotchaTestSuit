#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderCacheControl.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("no-transform,only-if-cached,must-revalidate,public,no-cache, no-store, must-revalidate");
    if(!c->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case1]");
      break;
    }

    if(!c->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case2]");
      break;
    }

    if(c->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case3]");
      break;
    }

    if(!c->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case4]");
      break;
    }

    if(!c->mustRevalidate()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case5]");
      break;
    }

    if(!c->onlyIfCached()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case6]");
      break;
    }

    if(!c->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case7]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("no-transform,only-if-cached,must-revalidate,private,no-cache, no-store, must-revalidate");
    if(!c->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case8]");
      break;
    }

    if(!c->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case9]");
      break;
    }

    if(!c->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case10]");
      break;
    }

    if(c->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case11]");
      break;
    }

    if(!c->mustRevalidate()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case12]");
      break;
    }

    if(!c->onlyIfCached()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case13]");
      break;
    }

    if(!c->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case14]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("max-age=31536000,max-stale=123,min-fresh=333,s-maxage=90");
    if(c->maxAgeSeconds() != 31536000) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case15]");
      break;
    }

    if(c->sMaxAgeSeconds() != 90) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case16]");
      break;
    }

    if(c->minFreshSeconds() != 333) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case17]");
      break;
    }

    if(c->maxStaleSeconds() != 123) {
      TEST_FAIL("[HttpHeaderCacheControl test Parse case18]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderCacheControl test Parse case100]");

}
