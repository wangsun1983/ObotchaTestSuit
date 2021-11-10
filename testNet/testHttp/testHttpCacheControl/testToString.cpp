#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderCacheControl.hpp"
#include "HttpProtocol.hpp"
using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("no-transform,only-if-cached,must-revalidate,public,no-cache, no-store, must-revalidate");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpProtocol)::HttpRequest));

    if(c->noCache() != c2->noCache()) {
      printf("---[HttpHeaderCacheControl test toString case1] [FAILED]--- \n");
      break;
    }

    if(c->noStore() != c2->noStore()) {
      printf("---[HttpHeaderCacheControl test toString case2] [FAILED]--- \n");
      break;
    }

    if(c->isPrivate() != c2->isPrivate()) {
      printf("---[HttpHeaderCacheControl test toString case3] [FAILED]--- \n");
      break;
    }

    //if(c->isPublic() != c2->isPublic()) {
    //  printf("---[HttpHeaderCacheControl test toString case4] [FAILED]--- \n");
    //  break;
    //}

    //if(c->mustRevalidate() != c2->mustRevalidate()) {
    //  printf("---[HttpHeaderCacheControl test toString case5] [FAILED]--- \n");
    //  break;
    //}

    if(c->onlyIfCached() != c2->onlyIfCached()) {
      printf("---[HttpHeaderCacheControl test toString case6] [FAILED]--- \n");
      break;
    }

    if(c->noTransform() != c2->noTransform()) {
      printf("---[HttpHeaderCacheControl test toString case7] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("no-transform,only-if-cached,must-revalidate,private,no-cache, no-store, must-revalidate");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpProtocol)::HttpResponse));

    if(c->noCache() != c2->noCache()) {
      printf("---[HttpHeaderCacheControl test toString case8] [FAILED]--- \n");
      break;
    }

    if(c->noStore() != c2->noStore()) {
      printf("---[HttpHeaderCacheControl test toString case9] [FAILED]--- \n");
      break;
    }

    if(c->isPrivate() != c2->isPrivate()) {
      printf("---[HttpHeaderCacheControl test toString case10] [FAILED]--- \n");
      break;
    }

    if(c->isPublic() != c2->isPublic()) {
      printf("---[HttpHeaderCacheControl test toString case11] [FAILED]--- \n");
      break;
    }

    if(c->mustRevalidate() != c2->mustRevalidate()) {
      printf("---[HttpHeaderCacheControl test toString case12] [FAILED]--- \n");
      break;
    }

    //if(c->onlyIfCached() != c2->onlyIfCached()) {
    //  printf("---[HttpHeaderCacheControl test toString case13] [FAILED]--- \n");
    //  break;
    //}

    if(c->noTransform() != c2->noTransform()) {
      printf("---[HttpHeaderCacheControl test toString case14] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("max-age=31536000,max-stale=123,min-fresh=333,s-maxage=90");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpProtocol)::HttpResponse));

    if(c->maxAgeSeconds() != c2->maxAgeSeconds()) {
      printf("---[HttpHeaderCacheControl test toString case15] [FAILED]--- \n");
      break;
    }

    if(c->sMaxAgeSeconds() != c2->sMaxAgeSeconds()) {
      printf("---[HttpHeaderCacheControl test toString case16] [FAILED]--- \n");
      break;
    }

    //if(c->minFreshSeconds() != c2->minFreshSeconds()) {
    //  printf("---[HttpHeaderCacheControl test toString case17] [FAILED]--- \n");
    //  break;
    //}

    if(c->maxStaleSeconds() != c2->maxStaleSeconds()) {
      printf("---[HttpHeaderCacheControl test toString case18] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("public");
    HttpHeaderCacheControl c2 = createHttpHeaderCacheControl(c->toString(st(HttpProtocol)::HttpResponse));
    if(c->isPublic() != c2->isPublic()) {
      printf("---[HttpHeaderCacheControl test toString case19] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderCacheControl test toString case100] [OK]--- \n");

}
