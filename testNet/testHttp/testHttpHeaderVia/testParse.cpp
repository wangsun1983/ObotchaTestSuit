#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVia.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderVia match = createHttpHeaderVia();
    match->import("1.1 GWA,1.0 fred, 1.1 p.example.net");
    ArrayList<HttpHeaderViaItem> list = match->get();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderVia test Parse case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderVia test Parse case100]");
}
