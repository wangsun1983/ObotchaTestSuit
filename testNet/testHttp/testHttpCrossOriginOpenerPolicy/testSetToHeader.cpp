#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderCrossOriginOpenerPolicy.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Cross-Origin-Opener-Policy"),String::New("unsafe-none"));
    auto policy = header->getCrossOriginOpenerPolicy();
    if(!policy->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginOpenerPolicy test setToHeader case1]");
    }
    break;
  }

  TEST_OK("[CrossOriginOpenerPolicy test setToHeader case1]");
}
