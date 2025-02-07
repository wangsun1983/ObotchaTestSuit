#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderHost.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("host"),String::New(" developer.mozilla.org:1234"));
    auto digest = header->getHost();
    auto host = digest->getHost();
    if(!host->sameAs("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderHost test setToHeader case1] host is%s\n",host->toChars());
      break;
    }

    if(digest->getPort() != 1234) {
      TEST_FAIL("[HttpHeaderHost test setToHeader case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderHost headhost = HttpHeaderHost::New();
    headhost->load(" developer.mozilla.org");
    HttpHeader header = HttpHeader::New();
    header->setHost(headhost);
    
    auto digest = header->getHost();
    auto host = digest->getHost();
    if(!host->sameAs("developer.mozilla.org")) {
      TEST_FAIL("[HttpHeaderHost test setToHeader case3]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderHost test setToHeader case100]");
}
