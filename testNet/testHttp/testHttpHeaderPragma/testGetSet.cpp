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

void testGetSet() {
  while(1) {
    HttpHeaderPragma pragma = createHttpHeaderPragma();
    pragma->set(" no-cache ");
    if(!pragma->toString()->sameAs("no-cache")){
      TEST_FAIL("[HttpHeaderPragma test set case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderPragma pragma = createHttpHeaderPragma();
    pragma->set(" no-cache ");
    HttpHeader header = createHttpHeader();
    header->setPragma(pragma);
    
    if(!header->getPragma()->toString()->sameAs("no-cache")){
      TEST_FAIL("[HttpHeaderPragma test set case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderPragma test set case100]");
}
