#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentLocation.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeaderContentLocation location = HttpHeaderContentLocation::New();
    location->load("/index.html");
    HttpHeader header = HttpHeader::New();
    header->setContentLocation(location);
    
    auto location1 = header->getContentLocation();
    if(!location1->toString()->sameAs("/index.html")) {
      TEST_FAIL("[HttpHeaderContentLocation test setToHeader case1],str is %s",location->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLocation test setToHeader case100]");

}
