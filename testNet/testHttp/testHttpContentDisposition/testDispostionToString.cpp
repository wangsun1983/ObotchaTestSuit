#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentDisposition.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testDispositionToString() {
  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->load("attachment");
    if(!disposition->toString()->sameAs("attachment")) {
        TEST_FAIL("[HttpHeaderContentDisposition test toString case1] [FAILED],disposition is %s ",disposition->toString()->toChars());
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->load("attachment; filename=\"filename.jpg\"");
    if(!disposition->toString()->sameAs("attachment; filename=\"filename.jpg\"")) {
        TEST_FAIL("[HttpHeaderContentDisposition test toString case2] [FAILED],disposition is %s ",disposition->toString()->toChars());
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->load("form-data; name=\"fieldName\"; filename=\"filename.jpg\"");
    if(!disposition->toString()->sameAs("form-data; name=\"fieldName\"; filename=\"filename.jpg\"")) {
        TEST_FAIL("[HttpHeaderContentDisposition test toString case3] [FAILED] disposition is %s ",disposition->toString()->toChars());
        break;
    }
    break;
  }
  
  while(1) {
      HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
      disposition->setType(st(HttpHeaderContentDisposition)::FormData);
      disposition->setFileName(createString("filename.jpg"));
      disposition->setName(createString("fieldName"));
      if(!disposition->toString()->sameAs("form-data; name=\"fieldName\"; filename=\"filename.jpg\"")) {
        TEST_FAIL("[HttpHeaderContentDisposition test toString case4] [FAILED] disposition is %s ",disposition->toString()->toChars());
      }
      break;
  }
  
  
  TEST_OK("[HttpHeaderContentDisposition test toString case100]");

}
