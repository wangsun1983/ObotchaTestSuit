#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAuthorization.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAuthorizationToString() {
  while(1) {
    HttpHeaderAuthorization auth = createHttpHeaderAuthorization();
    auth->load("Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    if(!auth->toString()->sameAs("Basic YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeaderAuthorization test toString case1]");
      break;
    }

    auth = createHttpHeaderAuthorization();
    auth->load("Digest username=\"Mufasa\",realm=\"testrealm@host.com\",nonce=\"dcd98b7102dd2f0e8b11d0f600bfb0c093\",uri=\"/dir/index.html\",qop=auth,nc=00000001,cnonce=\"0a4f113b\",response=\"6629fae49393a05397450978507c4ef1\",opaque=\"5ccc069c403ebaf9f0171e9517f40e41\"");
    if(!auth->toString()->sameAs("Digest username=\"Mufasa\",realm=\"testrealm@host.com\",nonce=\"dcd98b7102dd2f0e8b11d0f600bfb0c093\",uri=\"/dir/index.html\",qop=auth,nc=00000001,cnonce=\"0a4f113b\",response=\"6629fae49393a05397450978507c4ef1\",opaque=\"5ccc069c403ebaf9f0171e9517f40e41\"")) {
      TEST_FAIL("[HttpHeaderAuthorization test toString case2] [FAILED],auth is %s \n",auth->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAuthorization test toString case100]");

}
