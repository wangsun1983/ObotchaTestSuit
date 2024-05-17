#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderOrigin.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "Net.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderOrigin match = HttpHeaderOrigin::New();
    match->load("");
    HttpUrl url = match->get();
    if(url == nullptr){
      TEST_FAIL("[HttpHeaderOrigin test parse case1]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeaderOrigin match = HttpHeaderOrigin::New();
    match->load("https://developer.mozilla.org:1234");
    HttpUrl url = match->get();
    if(url == nullptr){
      TEST_FAIL("[HttpHeaderOrigin test parse case2]");
      break;
    }

    if(url->getScheme() != st(Net)::Protocol::Https) {
      TEST_FAIL("[HttpHeaderOrigin test parse case3]");
      break;
    }

    if(!url->getHost()->sameAs("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderOrigin test parse case4]");
      break;
    }

    if(url->getPort() != 1234) {
      TEST_FAIL("[HttpHeaderOrigin test parse case5]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderOrigin test Parse case100]");
}
