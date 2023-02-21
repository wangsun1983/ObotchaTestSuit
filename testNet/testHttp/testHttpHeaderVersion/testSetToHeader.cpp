#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(st(HttpHeader)::Version,createString("2.3"));
    auto ver = header->getVersion();
    
    if(ver->getMajorVer() != 2) {
      TEST_FAIL("[HttpHeaderVersion testSetToHeader case1]");
      break;
    }
    
    if(ver->getMinorVer() != 3) {
      TEST_FAIL("[HttpHeaderVersion testSetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderDnt test Parse case100]");

}
