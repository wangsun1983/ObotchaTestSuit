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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("no-transform,only-if-cached,must-revalidate,public,no-cache, no-store, must-revalidate");
    if(!c->noCache()) {
      printf("---[HttpHeaderCacheControl test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!c->noStore()) {
      printf("---[HttpHeaderCacheControl test Parse case2] [FAILED]--- \n");
      break;
    }

    if(c->isPrivate()) {
      printf("---[HttpHeaderCacheControl test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!c->isPublic()) {
      printf("---[HttpHeaderCacheControl test Parse case4] [FAILED]--- \n");
      break;
    }

    if(!c->mustRevalidate()) {
      printf("---[HttpHeaderCacheControl test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!c->onlyIfCached()) {
      printf("---[HttpHeaderCacheControl test Parse case6] [FAILED]--- \n");
      break;
    }

    if(!c->noTransform()) {
      printf("---[HttpHeaderCacheControl test Parse case7] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("no-transform,only-if-cached,must-revalidate,private,no-cache, no-store, must-revalidate");
    if(!c->noCache()) {
      printf("---[HttpHeaderCacheControl test Parse case8] [FAILED]--- \n");
      break;
    }

    if(!c->noStore()) {
      printf("---[HttpHeaderCacheControl test Parse case9] [FAILED]--- \n");
      break;
    }

    if(!c->isPrivate()) {
      printf("---[HttpHeaderCacheControl test Parse case10] [FAILED]--- \n");
      break;
    }

    if(c->isPublic()) {
      printf("---[HttpHeaderCacheControl test Parse case11] [FAILED]--- \n");
      break;
    }

    if(!c->mustRevalidate()) {
      printf("---[HttpHeaderCacheControl test Parse case12] [FAILED]--- \n");
      break;
    }

    if(!c->onlyIfCached()) {
      printf("---[HttpHeaderCacheControl test Parse case13] [FAILED]--- \n");
      break;
    }

    if(!c->noTransform()) {
      printf("---[HttpHeaderCacheControl test Parse case14] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderCacheControl c = createHttpHeaderCacheControl();
    c->import("max-age=31536000,max-stale=123,min-fresh=333,s-maxage=90");
    if(c->maxAgeSeconds() != 31536000) {
      printf("---[HttpHeaderCacheControl test Parse case15] [FAILED]--- \n");
      break;
    }

    if(c->sMaxAgeSeconds() != 90) {
      printf("---[HttpHeaderCacheControl test Parse case16] [FAILED]--- \n");
      break;
    }

    if(c->minFreshSeconds() != 333) {
      printf("---[HttpHeaderCacheControl test Parse case17] [FAILED]--- \n");
      break;
    }

    if(c->maxStaleSeconds() != 123) {
      printf("---[HttpHeaderCacheControl test Parse case18] [FAILED]--- \n");
      break;
    }
    break;
  }
  printf("---[HttpHeaderCacheControl test Parse case100] [OK]--- \n");

}
