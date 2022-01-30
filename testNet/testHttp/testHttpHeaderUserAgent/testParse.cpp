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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderUserAgent useragent = createHttpHeaderUserAgent();
    useragent->import(" Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0");
    ArrayList<HttpUserAgentDetail> lists = useragent->get();
    auto detail1 = lists->get(0);
    if(lists->size() != 3) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case1_1]");
      break;
    }

    if(!detail1->product->equals("Mozilla")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case1]");
      break;
    }

    if(!detail1->version->equals("5.0")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case2]");
      break;
    }

    if(detail1->info == nullptr || !detail1->info->equals("Windows NT 6.1; Win64; x64; rv:47.0")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case3],info is %s ",detail1->info->toChars());
      break;
    }

    auto detail2 = lists->get(1);
    if(!detail2->product->equals("Gecko")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case4]");
      break;
    }

    if(!detail2->version->equals("20100101")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case5]");
      break;
    }

    if(detail2->info != nullptr) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case6]");
      break;
    }

    auto detail3 = lists->get(2);
    if(!detail3->product->equals("Firefox")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case7]");
      break;
    }

    if(!detail3->version->equals("47.0")) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case8]");
      break;
    }

    if(detail3->info != nullptr) {
      TEST_FAIL("[HttpHeaderUserAgent test Parse case9]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderUserAgent test Parse case100]");
}
