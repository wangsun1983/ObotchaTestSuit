#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSourceMap.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderSourceMap timing = HttpHeaderSourceMap::New();
    timing->load("/path/to/file.js.map");
    if(!timing->toString()->sameAs("/path/to/file.js.map")) {
      TEST_FAIL("[HttpHeaderSourceMap test toString case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderSourceMap timing = HttpHeaderSourceMap::New();
    timing->load("/path/to/file.js.map");
    HttpHeader header = HttpHeader::New();
    header->setSourceMap(timing);
    auto timing2 = header->getSourceMap();
    if(!timing2->toString()->sameAs("/path/to/file.js.map")) {
      TEST_FAIL("[HttpHeaderSourceMap test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderServerTiming test toString case100]");

}
