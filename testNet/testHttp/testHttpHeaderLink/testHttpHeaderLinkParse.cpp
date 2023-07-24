#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderLink.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkParse() {
  while(1) {
    HttpHeaderLink link1 = createHttpHeaderLink("<https://example.com>; rel=\"preload\"");
    if(link1->url == nullptr || !link1->url->sameAs("https://example.com")) {
      TEST_FAIL("[HttpHeaderLink test Parse case1] link is %s",link1->url->toChars());
    }

    if(!link1->rel->sameAs("preload")) {
      TEST_FAIL("[HttpHeaderLink test Parse case2] rel is %s",link1->rel->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderLink test Parse case100]");

}
