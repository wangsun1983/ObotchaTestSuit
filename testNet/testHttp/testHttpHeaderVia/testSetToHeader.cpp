#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVia.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Via"),
                String::New("1.1 GWA,1.0 fred, 1.1 p.example.net"));
    auto match = header->getVia();
    ArrayList<HttpHeaderViaItem> list = match->get();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderVia test setToHeader case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderVia test setToHeader case100]");
}
