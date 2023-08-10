#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->load("1");
    if(!dnt->toString()->sameAs("1")) {
      TEST_FAIL("[HttpHeaderDnt test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->load("0");
    if(!dnt->toString()->sameAs("0")) {
      TEST_FAIL("[HttpHeaderDnt test toString case2]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderDnt dnt = createHttpHeaderDnt();
    dnt->load("0");
    HttpHeader header = createHttpHeader();
    header->setDnt(dnt);
    
    auto dnt2 = header->getDnt();
    if(!dnt2->toString()->sameAs("0")) {
      TEST_FAIL("[HttpHeaderDnt test toString case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderDnt test toString case100]");

}
