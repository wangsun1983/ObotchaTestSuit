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

void testGetUrl() {
  while(1) {
    HttpPost post = createHttpPost("https://abc.com");
    if(!post->getUrl()->toString()->equals("https://abc.com")) {
        TEST_FAIL("[HttpPost test testGetUrl case1],url is %s",post->getUrl()->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpPost test testGetUrl case100]");
}
