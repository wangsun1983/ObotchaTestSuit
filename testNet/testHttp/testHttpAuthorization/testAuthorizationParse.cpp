#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAuthorization.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAuthorizationParse() {
  while(1) {
    HttpHeaderAuthorization auth = createHttpHeaderAuthorization();
    auth->load("Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    if(!auth->type->sameAs("Basic")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case1]");
      break;
    }

    if(!auth->credentials->sameAs("YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAuthorization auth = createHttpHeaderAuthorization();
    auth->load("Digest username=\"Mufasa\",realm=\"testrealm@host.com\",nonce=\"dcd98b7102dd2f0e8b11d0f600bfb0c093\",uri=\"/dir/index.html\",qop=auth,nc=00000001,cnonce=\"0a4f113b\",response=\"6629fae49393a05397450978507c4ef1\",opaque=\"5ccc069c403ebaf9f0171e9517f40e41\"");

    if(!auth->type->sameAs("Digest")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case3]");
      break;
    }

    if(!auth->username->sameAs("Mufasa")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case4] [FAILED],username is %s \n",auth->username->toChars());
      break;
    }

    if(!auth->realm->sameAs("testrealm@host.com")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case5]");
      break;
    }

    if(!auth->nonce->sameAs("dcd98b7102dd2f0e8b11d0f600bfb0c093")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case6]");
      break;
    }

    if(!auth->uri->sameAs("/dir/index.html")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case7]");
      break;
    }

    if(!auth->qop->sameAs("auth")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case8]");
      break;
    }

    if(!auth->cnonce->sameAs("0a4f113b")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case9]");
      break;
    }

    if(!auth->response->sameAs("6629fae49393a05397450978507c4ef1")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case10]");
      break;
    }

    if(!auth->opaque->sameAs("5ccc069c403ebaf9f0171e9517f40e41")) {
      TEST_FAIL("[HttpHeaderAuthorization test Parse case11]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAuthorization test Parse case100]");

}
