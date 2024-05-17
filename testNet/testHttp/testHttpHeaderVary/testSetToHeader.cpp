#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVary.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Vary"),
                String::New("no-referrer, User-Agent"));
    auto match = header->getVary();
    ArrayList<String> list = match->get();
    if(list->size() != 2) {
      TEST_FAIL("[HttpHeaderVary test setToHeader case1]");
      break;
    }

    if(!list->get(0)->sameAs("no-referrer") || !list->get(1)->sameAs("User-Agent")) {
      TEST_FAIL("[HttpHeaderVary test setToHeader case2]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = HttpHeader::New();
    HttpHeaderVary vary = HttpHeaderVary::New();
    vary->load("no-referrer, User-Agent ");
    header->setVary(vary);
    auto match = header->getVary();
    ArrayList<String> list = match->get();
    if(list->size() != 2) {
      TEST_FAIL("[HttpHeaderVary test setToHeader case1]");
      break;
    }

    if(!list->get(0)->sameAs("no-referrer") || !list->get(1)->sameAs("User-Agent")) {
      TEST_FAIL("[HttpHeaderVary test setToHeader case3]");
      break;
    }
    break;
  }
  
  TEST_OK("[HttpHeaderVary test setToHeader case100]");
}
