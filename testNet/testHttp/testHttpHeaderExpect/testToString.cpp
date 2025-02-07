#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpect.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
      HttpHeaderExpect expect = HttpHeaderExpect::New();
      expect->load("100-continue");
      if(!expect->toString()->sameAs("100-continue")) {
        TEST_FAIL("[HttpHeaderExpect test toString case1]");
      }

      HttpHeader header = HttpHeader::New();
      header->setExpect(expect);
      auto expect2 = header->getExpect();
      if(!expect2->toString()->sameAs("100-continue")) {
        TEST_FAIL("[HttpHeaderExpect test toString case2]");
      }
      break;
  }
  
  while(1) {
      HttpHeaderExpect expect = HttpHeaderExpect::New();
      expect->set("100-continue");
      if(!expect->toString()->sameAs("100-continue")) {
        TEST_FAIL("[HttpHeaderExpect test toString case3]");
      }
      break;
  }
  
  TEST_OK("[HttpHeaderExpect test toString case100]");

}
