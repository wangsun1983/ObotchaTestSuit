#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderCacheControl.hpp"
#include "HttpPacket.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->load("no-transform,only-if-cached,must-revalidate,public,no-cache, no-store, must-revalidate");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpPacket)::Request));

    if(c->noCache() != c2->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case1]");
      break;
    }

    if(c->noStore() != c2->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case2]");
      break;
    }

    if(c->isPrivate() != c2->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case3]");
      break;
    }

    //if(c->isPublic() != c2->isPublic()) {
    //  TEST_FAIL("[HttpHeaderCacheControl test toString case4]");
    //  break;
    //}

    //if(c->mustRevalidate() != c2->mustRevalidate()) {
    //  TEST_FAIL("[HttpHeaderCacheControl test toString case5]");
    //  break;
    //}

    if(c->onlyIfCached() != c2->onlyIfCached()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case6]");
      break;
    }

    if(c->noTransform() != c2->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case7]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->load("no-transform,only-if-cached,must-revalidate,private,no-cache, no-store, must-revalidate");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpPacket)::Response));

    if(c->noCache() != c2->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case8]");
      break;
    }

    if(c->noStore() != c2->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case9]");
      break;
    }

    if(c->isPrivate() != c2->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case10]");
      break;
    }

    if(c->isPublic() != c2->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case11]");
      break;
    }

    if(c->mustRevalidate() != c2->mustRevalidate()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case12]");
      break;
    }

    //if(c->onlyIfCached() != c2->onlyIfCached()) {
    //  TEST_FAIL("[HttpHeaderCacheControl test toString case13]");
    //  break;
    //}

    if(c->noTransform() != c2->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case14]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->load("max-age=31536000,max-stale=123,min-fresh=333,s-maxage=90");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpPacket)::Response));

    if(c->maxAgeSeconds() != c2->maxAgeSeconds()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case15]");
      break;
    }

    if(c->sMaxAgeSeconds() != c2->sMaxAgeSeconds()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case16]");
      break;
    }

    //if(c->minFreshSeconds() != c2->minFreshSeconds()) {
    //  TEST_FAIL("[HttpHeaderCacheControl test toString case17]");
    //  break;
    //}

    if(c->maxStaleSeconds() != c2->maxStaleSeconds()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case18]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->load("public");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpPacket)::Response));
    if(c->isPublic() != c2->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case19]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->setNoTransform(true);
    c->setOnlyIfCached(true);
    c->setMustRevalidate(true);
    c->setPublic();
    c->setNoCache(true);
    c->setNoStore(true);
    
    HttpHeaderCacheControl c2 
        = createHttpHeaderCacheControl(createString("no-transform,only-if-cached,must-revalidate,public,no-cache, no-store, must-revalidate"));
    
    if(c->noCache() != c2->noCache()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case20]");
      break;
    }

    if(c->noStore() != c2->noStore()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case21]");
      break;
    }

    if(c->isPrivate() != c2->isPrivate()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case22]");
      break;
    }

    if(c->isPublic() != c2->isPublic()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case23]");
      break;
    }

    if(c->mustRevalidate() != c2->mustRevalidate()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case24]");
      break;
    }

    if(c->onlyIfCached() != c2->onlyIfCached()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case25]");
      break;
    }

    if(c->noTransform() != c2->noTransform()) {
      TEST_FAIL("[HttpHeaderCacheControl test toString case26]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderCacheControl test toString case100]");

}
