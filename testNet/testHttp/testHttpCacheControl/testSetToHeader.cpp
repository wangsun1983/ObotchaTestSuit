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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Cache-Control"),
        createString("no-transform,only-if-cached,must-revalidate,public,no-cache, no-store, must-revalidate"));
    auto c = header->getCacheControl();
    
    if(!c->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case1]");
      break;
    }

    if(!c->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case2]");
      break;
    }

    if(c->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case3]");
      break;
    }

    if(!c->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case4]");
      break;
    }

    if(!c->mustRevalidate()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case5]");
      break;
    }

    if(!c->onlyIfCached()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case6]");
      break;
    }

    if(!c->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case7]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Cache-Control"),
        createString("no-transform,only-if-cached,must-revalidate,private,no-cache, no-store, must-revalidate"));
    auto c = header->getCacheControl();
    
    if(!c->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case8]");
      break;
    }

    if(!c->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case9]");
      break;
    }

    if(!c->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case10]");
      break;
    }

    if(c->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case11]");
      break;
    }

    if(!c->mustRevalidate()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case12]");
      break;
    }

    if(!c->onlyIfCached()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case13]");
      break;
    }

    if(!c->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case14]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Cache-Control"),
        createString("max-age=31536000,max-stale=123,min-fresh=333,s-maxage=90"));
    auto c = header->getCacheControl();
    
    if(c->maxAgeSeconds() != 31536000) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case15]");
      break;
    }

    if(c->sMaxAgeSeconds() != 90) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case16]");
      break;
    }

    if(c->minFreshSeconds() != 333) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case17]");
      break;
    }

    if(c->maxStaleSeconds() != 123) {
      TEST_FAIL("[HttpHeaderCacheControl test setToHeader case18]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderCacheControl test setToHeader case100]");

}
