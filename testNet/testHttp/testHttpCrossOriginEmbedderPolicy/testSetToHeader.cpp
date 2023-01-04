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
#include "HttpHeaderCrossOriginEmbedderPolicy.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Cross-Origin-Embedder-Policy"),createString("unsafe-none"));
    auto policy = header->getCrossOriginEmbedderPolicy();
    if(!policy->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test setToHeader case1]");
    }
    break;
  }

  TEST_OK("[CrossOriginEmbedderPolicy test setToHeader case1]");
}
