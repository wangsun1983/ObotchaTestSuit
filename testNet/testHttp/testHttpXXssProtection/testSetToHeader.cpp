#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeader.hpp"
#include "TestLog.hpp"
#include "HttpHeaderXXssProtection.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    auto header = HttpHeader::New();
    header->set(String::New("X-XSS-Protection"),
                String::New("1; report=abc.hpp"));
    auto p = header->getXXssProtection();
    
    if(p->getType() != st(HttpHeaderXXssProtection)::Report) {
      TEST_FAIL("[HttpHeaderXXssProtection test setToHeader case1]");
    }

    if(!p->getReportUrl()->sameAs("abc.hpp")) {
      TEST_FAIL("[HttpHeaderXXssProtection test setToHeader case2],url is %s ",p->getReportUrl()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderXXssProtection test setToHeader case100]");

}
