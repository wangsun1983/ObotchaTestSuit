#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSourceMap.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("SourceMap"),createString("/path/to/file.js.map"));
    
    HttpHeaderSourceMap timing = header->getSourceMap();
    timing->load("/path/to/file.js.map");
    if(!timing->get()->equals("/path/to/file.js.map")) {
      TEST_FAIL("[HttpHeaderSourceMap test SetToHeader case1]");
      break;
    }
    break;
  }
  

  TEST_OK("[HttpHeaderSourceMap test Parse case100]");

}
