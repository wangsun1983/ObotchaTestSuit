#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVia.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  HttpHeaderVia match = createHttpHeaderVia();
  match->import("1.1 GWA, 1.0 fred, 1.1 p.example.net");
  if(!match->toString()->equals("1.1 GWA, 1.0 fred, 1.1 p.example.net")) {
    TEST_FAIL("[HttpHeaderVia test toString case1],toString is %s",match->toString()->toChars());
  }

  TEST_OK("[HttpHeaderVia test toString case100]");
}
