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
    match->load("\"bfc13a64729c4290ef5b2c2730249c88ca92d82d\"");
    ArrayList<HttpHeaderMatchItem> list = match->get();
    if(list->size() != 1){
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case1] ");
      break;
    }

    auto item = list->get(0);
    if(item == nullptr || !item->tag->sameAs("bfc13a64729c4290ef5b2c2730249c88ca92d82d")) {
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case2] ");
    }
    break;
  }

  while(1) {
    HttpHeaderMatch match = createHttpHeaderMatch();
    match->load("W/\"67ab43\", \"54ed21\", \"7892dd\"");
    ArrayList<HttpHeaderMatchItem> list = match->get();
    if(list->size() != 3){
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case3] ");
      break;
    }

    auto item = list->get(0);
    if(item == nullptr || !item->tag->sameAs("67ab43") || !item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case4] ");
    }

    item = list->get(1);
    if(item == nullptr || !item->tag->sameAs("54ed21") || item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case5] ");
    }

    item = list->get(2);
    if(item == nullptr || !item->tag->sameAs("7892dd") || item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case6] ");
    }
    break;
  }

  while(1) {
    HttpHeaderMatch match = createHttpHeaderMatch();
    match->load("*");
    ArrayList<HttpHeaderMatchItem> list = match->get();
    if(list->size() != 1){
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case7] ");
      break;
    }

    auto item = list->get(0);
    if(item == nullptr || !item->tag->sameAs("*") || item->isWeakAlg) {
      TEST_FAIL("[HttpHeaderIfNoneMatch test parse case8] ");
    }

    break;
  }

  TEST_OK("[HttpHeaderIfNoneMatch test Parse case100]");
}
