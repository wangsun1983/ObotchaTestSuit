#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAuthorization.hpp"
#include "Math.hpp"

using namespace obotcha;

void testAuthorizationParse() {
  while(1) {
    HttpHeaderAuthorization auth = createHttpHeaderAuthorization();
    auth->import("Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    if(!auth->type->equals("Basic")) {
      printf("---[HttpHeaderAuthorization test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!auth->credentials->equals("YWxhZGRpbjpvcGVuc2VzYW1l")) {
      printf("---[HttpHeaderAuthorization test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAuthorization auth = createHttpHeaderAuthorization();
    auth->import("Digest username=\"Mufasa\",realm=\"testrealm@host.com\",nonce=\"dcd98b7102dd2f0e8b11d0f600bfb0c093\",uri=\"/dir/index.html\",qop=auth,nc=00000001,cnonce=\"0a4f113b\",response=\"6629fae49393a05397450978507c4ef1\",opaque=\"5ccc069c403ebaf9f0171e9517f40e41\"");
    
    if(!auth->type->equals("Digest")) {
      printf("---[HttpHeaderAuthorization test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!auth->username->equals("Mufasa")) {
      printf("---[HttpHeaderAuthorization test Parse case4] [FAILED]--- \n");
      break;
    }

    if(!auth->realm->equals("testrealm@host.com")) {
      printf("---[HttpHeaderAuthorization test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!auth->nonce->equals("dcd98b7102dd2f0e8b11d0f600bfb0c093")) {
      printf("---[HttpHeaderAuthorization test Parse case6] [FAILED]--- \n");
      break;
    }

    if(!auth->uri->equals("/dir/index.html")) {
      printf("---[HttpHeaderAuthorization test Parse case7] [FAILED]--- \n");
      break;
    }

    if(!auth->qop->equals("auth")) {
      printf("---[HttpHeaderAuthorization test Parse case8] [FAILED]--- \n");
      break;
    }

    if(!auth->cnonce->equals("0a4f113b")) {
      printf("---[HttpHeaderAuthorization test Parse case9] [FAILED]--- \n");
      break;
    }

    if(!auth->response->equals("6629fae49393a05397450978507c4ef1")) {
      printf("---[HttpHeaderAuthorization test Parse case10] [FAILED]--- \n");
      break;
    }

    if(!auth->opaque->equals("5ccc069c403ebaf9f0171e9517f40e41")) {
      printf("---[HttpHeaderAuthorization test Parse case11] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAuthorization test Parse case100] [OK]--- \n");

}
