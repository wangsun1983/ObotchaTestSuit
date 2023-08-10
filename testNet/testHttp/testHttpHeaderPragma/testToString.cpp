#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderPragma.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderPragma pragma = createHttpHeaderPragma();
    pragma->load(" no-cache ");
    if(!pragma->toString()->sameAs("no-cache")){
      TEST_FAIL("[HttpHeaderPragma test toString case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderPragma pragma = createHttpHeaderPragma();
    pragma->load(" no-cache ");
    HttpHeader header = createHttpHeader();
    header->setPragma(pragma);
    
    if(!header->getPragma()->toString()->sameAs("no-cache")){
      TEST_FAIL("[HttpHeaderPragma test toString case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderPragma test toString case100]");
}
