#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUserAgent.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("User-Agent"),
                createString(" Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0"));
    auto useragent = header->getUserAgent();
    ArrayList<HttpUserAgentDetail> lists = useragent->get();
    auto detail1 = lists->get(0);
    if(lists->size() != 3) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case1_1]");
      break;
    }

    if(!detail1->product->sameAs("Mozilla")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case1]");
      break;
    }

    if(!detail1->version->sameAs("5.0")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case2]");
      break;
    }

    if(detail1->info == nullptr || !detail1->info->sameAs("Windows NT 6.1; Win64; x64; rv:47.0")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case3],info is %s ",detail1->info->toChars());
      break;
    }

    auto detail2 = lists->get(1);
    if(!detail2->product->sameAs("Gecko")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case4]");
      break;
    }

    if(!detail2->version->sameAs("20100101")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case5]");
      break;
    }

    if(detail2->info != nullptr) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case6]");
      break;
    }

    auto detail3 = lists->get(2);
    if(!detail3->product->sameAs("Firefox")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case7]");
      break;
    }

    if(!detail3->version->sameAs("47.0")) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case8]");
      break;
    }

    if(detail3->info != nullptr) {
      TEST_FAIL("[HttpHeaderUserAgent test SetToHeader case9]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderUserAgent test SetToHeader case100]");
}
