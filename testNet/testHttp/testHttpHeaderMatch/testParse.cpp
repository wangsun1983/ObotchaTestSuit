#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderMatch.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderMatch match = createHttpHeaderMatch();
    match->import("\"bfc13a64729c4290ef5b2c2730249c88ca92d82d\"");
    ArrayList<HttpHeaderMatchItem> list = match->get();
    if(list->size() != 1){
      TEST_FAIL("[HttpHeaderMatch test parse case1] ");
      break;
    }

    auto item = list->get(0);
    if(item == nullptr || !item->tag->equals("bfc13a64729c4290ef5b2c2730249c88ca92d82d")) {
      TEST_FAIL("[HttpHeaderMatch test parse case2] ");
    }
    break;
  }

  while(1) {
    HttpHeaderMatch match = createHttpHeaderMatch();
    match->import("W/\"67ab43\", \"54ed21\", \"7892dd\"");
    ArrayList<HttpHeaderMatchItem> list = match->get();
    if(list->size() != 3){
      TEST_FAIL("[HttpHeaderMatch test parse case3] ");
      break;
    }

    auto item = list->get(0);
    if(item == nullptr || !item->tag->equals("67ab43") || !item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderMatch test parse case4] ");
    }

    item = list->get(1);
    if(item == nullptr || !item->tag->equals("54ed21") || item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderMatch test parse case5] ");
    }

    item = list->get(2);
    if(item == nullptr || !item->tag->equals("7892dd") || item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderMatch test parse case6] ");
    }
    break;
  }

  while(1) {
    HttpHeaderMatch match = createHttpHeaderMatch();
    match->import("*");
    ArrayList<HttpHeaderMatchItem> list = match->get();
    if(list->size() != 1){
      TEST_FAIL("[HttpHeaderMatch test parse case7] ");
      break;
    }

    auto item = list->get(0);
    if(item == nullptr || !item->tag->equals("*") || item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderMatch test parse case8] ");
    }

    break;
  }

  TEST_OK("[HttpHeaderMatch test Parse case100]");
}
