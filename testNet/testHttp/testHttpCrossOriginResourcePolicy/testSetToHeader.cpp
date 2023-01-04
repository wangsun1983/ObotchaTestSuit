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
#include "HttpHeaderCrossOriginResourcePolicy.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Cross-Origin-Resource-Policy"),
                createString("same-site"));
    auto policy = header->getCrossOriginResourcePolicy();
    if(!policy->isSameSite()) {
      TEST_FAIL("[CrossOriginResourcePolicy test setToHeader case1]");
    }
    break;
  }

  TEST_OK("[CrossOriginResourcePolicy test setToHeader case100]");
}
