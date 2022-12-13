#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderParser.hpp"
#include "ByteRingArrayReader.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHttpUrlWithoutPath() {
  HttpUrl url = createHttpUrl("http://localhost/");
  if(url->getPath() != nullptr) {
    TEST_FAIL("[HttpUrlParse test Parse with no path case1]");
  }

  TEST_OK("[HttpUrlParse test Parse with no path case100]");

}
