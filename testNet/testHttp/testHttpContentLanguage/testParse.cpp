#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderContentLanguage.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentLanguage c = HttpHeaderContentLanguage::New();
    c->load("de-DE, en-CA");
    auto list = c->get();
    if(!list->get(0)->sameAs("de-DE")) {
      TEST_FAIL("[HttpHeaderContentLanguage test Parse case1]");
      break;
    }

    if(!list->get(1)->sameAs("en-CA")) {
      TEST_FAIL("[HttpHeaderContentLanguage test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLanguage test Parse case100]");

}
