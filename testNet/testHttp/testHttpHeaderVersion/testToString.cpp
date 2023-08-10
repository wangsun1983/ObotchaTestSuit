#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"
#include "HttpHeaderVersion.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderVersion version = createHttpHeaderVersion();
    version->setMajorVer(3);
    version->setMinorVer(2);
    if(!version->toString()->sameAs("HTTP/3.2")) {
        TEST_FAIL("[HttpHeaderVersion test toString case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderVersion test toString case100]");

}
