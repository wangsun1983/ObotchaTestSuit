#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "CRLFDetector.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpPost.hpp"

using namespace obotcha;

void testGetMethodName() {
  while(1) {
    HttpPost post = createHttpPost("https://abc.com");
    if(!post->getMethodName()->sameAs("POST")) {
        TEST_FAIL("[HttpPost test GetMethodName case1]");
    }
    break;
  }

  TEST_OK("[HttpPost test GetMethodName case100]");
}
