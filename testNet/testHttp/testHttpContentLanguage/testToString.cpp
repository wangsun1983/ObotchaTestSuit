#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderContentLanguage.hpp"
#include "HttpPacket.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentLanguage c = HttpHeaderContentLanguage::New();
    c->load("de-DE, en-CA");
    if(c->toString()->sameAs("de-DE, en-CA ")) {
      TEST_FAIL("[HttpHeaderContentLanguage test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLanguage test toString case100]");

}
