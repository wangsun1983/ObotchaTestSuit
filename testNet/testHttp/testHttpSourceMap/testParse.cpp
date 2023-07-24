#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSourceMap.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSourceMap timing = createHttpHeaderSourceMap();
    timing->load("/path/to/file.js.map");
    if(!timing->get()->sameAs("/path/to/file.js.map")) {
      TEST_FAIL("[HttpHeaderSourceMap test Parse case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderSourceMap timing = createHttpHeaderSourceMap();
    timing->set("/path/to/file.js.map");
    if(!timing->get()->sameAs("/path/to/file.js.map")) {
      TEST_FAIL("[HttpHeaderSourceMap test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSourceMap test Parse case100]");

}
