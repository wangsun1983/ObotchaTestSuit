#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderPragma.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderPragma pragma = createHttpHeaderPragma();
    pragma->import(" no-cache ");
    if(!pragma->get()->equals("no-cache")){
      TEST_OK("[HttpHeaderPragma test parse case1]");
      break;
    }
    break;
  }
  
  TEST_OK("[HttpHeaderPragma test Parse case100]");
}
