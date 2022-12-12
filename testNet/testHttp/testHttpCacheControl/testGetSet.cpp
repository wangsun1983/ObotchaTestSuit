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

void testGetSet() {
  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->setNoCache(true);
    c->setNoStore(true);
    c->setMaxAgeSeconds(1);
    c->setSMaxAgeSeconds(2);
    c->setPrivate();
    c->setMustRevalidate(true);
    c->setMaxStaleSeconds(3);
    c->setMinFreshSeconds(4);
    c->setOnlyIfCached(true);
    c->setNoTransform(true);
    
    if(!c->noCache()) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case1]");
    }
    
    if(!c->noStore()) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case2]");
    }
    
    if(c->maxAgeSeconds() != 1) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case3]");
    }
    
    if(c->sMaxAgeSeconds() != 2) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case4]");
    }
    
    if(!c->isPrivate()) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case5]");
    }
    
    if(!c->mustRevalidate()) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case6]");
    }
    
    if(c->maxStaleSeconds() != 3) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case7]");
    }
    
    if(c->minFreshSeconds() != 4) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case8]");
    }
    
    if(!c->onlyIfCached()) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case9]");
    }
    
    if(!c->noTransform()) {
        TEST_FAIL("[HttpHeaderCacheControl test GetSet case10]");
    }
    break;
  }

  TEST_OK("[HttpHeaderCacheControl test GetSet case100]");

}
