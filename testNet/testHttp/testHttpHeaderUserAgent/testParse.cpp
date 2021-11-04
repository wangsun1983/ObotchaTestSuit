#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUserAgent.hpp"
#include "Math.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderUserAgent useragent = createHttpHeaderUserAgent();
    useragent->import(" Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0");
    ArrayList<HttpUserAgentDetail> lists = useragent->get();
    auto detail1 = lists->get(0);
    if(lists->size() != 3) {
      printf("---[HttpHeaderUserAgent test Parse case1_1] [FAILED]--- \n");
      break;
    }

    if(!detail1->product->equals("Mozilla")) {
      printf("---[HttpHeaderUserAgent test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!detail1->version->equals("5.0")) {
      printf("---[HttpHeaderUserAgent test Parse case2] [FAILED]--- \n");
      break;
    }

    if(detail1->info == nullptr || !detail1->info->equals("Windows NT 6.1; Win64; x64; rv:47.0")) {
      printf("---[HttpHeaderUserAgent test Parse case3] [FAILED]---,info is %s \n",detail1->info->toChars());
      break;
    }

    auto detail2 = lists->get(1);
    if(!detail2->product->equals("Gecko")) {
      printf("---[HttpHeaderUserAgent test Parse case4] [FAILED]--- \n");
      break;
    }

    if(!detail2->version->equals("20100101")) {
      printf("---[HttpHeaderUserAgent test Parse case5] [FAILED]--- \n");
      break;
    }

    if(detail2->info != nullptr) {
      printf("---[HttpHeaderUserAgent test Parse case6] [FAILED]--- \n");
      break;
    }

    auto detail3 = lists->get(2);
    if(!detail3->product->equals("Firefox")) {
      printf("---[HttpHeaderUserAgent test Parse case7] [FAILED]--- \n");
      break;
    }

    if(!detail3->version->equals("47.0")) {
      printf("---[HttpHeaderUserAgent test Parse case8] [FAILED]--- \n");
      break;
    }

    if(detail3->info != nullptr) {
      printf("---[HttpHeaderUserAgent test Parse case9] [FAILED]--- \n");
      break;
    }

    break;
  }



  printf("---[HttpHeaderUserAgent test Parse case100] [OK]--- \n");
}
