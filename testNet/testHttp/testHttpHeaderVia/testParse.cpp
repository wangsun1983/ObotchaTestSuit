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
    match->load("1.1 GWA,1.0 fred, 1.1 p.example.net");
    ArrayList<HttpHeaderViaItem> list = match->get();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderVia test Parse case1]");
      break;
    }
    
    auto v0 = list->get(0);
    if(!v0->version->equals("1.1")) {
        TEST_FAIL("[HttpHeaderVia test Parse case1]");
    }
    
    if(!v0->pseudonym->equals("GWA")) {
        TEST_FAIL("[HttpHeaderVia test Parse case2]");
    }
    
    auto v1 = list->get(1);
    if(!v1->version->equals("1.0")) {
        TEST_FAIL("[HttpHeaderVia test Parse case1]");
    }
    
    if(!v1->pseudonym->equals("fred")) {
        TEST_FAIL("[HttpHeaderVia test Parse case2]");
    }
    
    auto v2 = list->get(2);
    if(!v2->version->equals("1.1")) {
        TEST_FAIL("[HttpHeaderVia test Parse case1]");
    }
    
    if(!v2->url->toString()->equals("p.example.net")) {
        TEST_FAIL("[HttpHeaderVia test Parse case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderVia match = createHttpHeaderVia();
    match->load("Http/1.1 GWA,1.0 fred, 1.1 p.example.net");
    ArrayList<HttpHeaderViaItem> list = match->get();
    if(list->size() != 3) {
      TEST_FAIL("[HttpHeaderVia test Parse case3]");
      break;
    }
    
    auto v0 = list->get(0);
    if(!v0->protocol->equals("Http")) {
        TEST_FAIL("[HttpHeaderVia test Parse case4]");
    }
    
    if(!v0->version->equals("1.1")) {
        TEST_FAIL("[HttpHeaderVia test Parse case5]");
    }
    
    if(!v0->pseudonym->equals("GWA")) {
        TEST_FAIL("[HttpHeaderVia test Parse case6]");
    }
    
    auto v1 = list->get(1);
    if(!v1->version->equals("1.0")) {
        TEST_FAIL("[HttpHeaderVia test Parse case7]");
    }
    
    if(!v1->pseudonym->equals("fred")) {
        TEST_FAIL("[HttpHeaderVia test Parse case8]");
    }
    
    auto v2 = list->get(2);
    if(!v2->version->equals("1.1")) {
        TEST_FAIL("[HttpHeaderVia test Parse case9]");
    }
    
    if(!v2->url->toString()->equals("p.example.net")) {
        TEST_FAIL("[HttpHeaderVia test Parse case10]");
    }
    break;
  }

  TEST_OK("[HttpHeaderVia test Parse case100]");
}
