#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVersion.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderVersion version = createHttpHeaderVersion();
    version->load("HTTP/1.2");
    if(version->getMajorVer() != 1) {
      TEST_FAIL("[HttpHeaderVersion test Parse case1]");
      break;
    }
    
    if(version->getMinorVer() != 2) {
      TEST_FAIL("[HttpHeaderVersion test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderVersion test Parse case100]");

}
