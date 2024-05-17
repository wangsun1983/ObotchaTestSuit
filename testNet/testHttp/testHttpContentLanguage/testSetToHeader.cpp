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
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Content-Language"),
                String::New("de-DE, en-CA"));
    auto c = header->getContentLanguage();
    auto list = c->get();
    if(!list->get(0)->sameAs("de-DE")) {
      TEST_FAIL("[HttpHeaderContentLanguage test SetToHeader case1]");
      break;
    }

    if(!list->get(1)->sameAs("en-CA")) {
      TEST_FAIL("[HttpHeaderContentLanguage test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLanguage test SetToHeader case100]");

}
