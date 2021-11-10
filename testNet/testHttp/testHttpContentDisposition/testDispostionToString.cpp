#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentDisposition.hpp"

using namespace obotcha;

void testDispositionToString() {
  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->import("attachment");
    if(!disposition->toString()->equals("attachment")) {
        printf("---[HttpHeaderContentDisposition test toString case1] [FAILED]---,disposition is %s \n",disposition->toString()->toChars());
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->import("attachment; filename=\"filename.jpg\"");
    if(!disposition->toString()->equals("attachment; filename=\"filename.jpg\"")) {
        printf("---[HttpHeaderContentDisposition test toString case2] [FAILED]---,disposition is %s \n",disposition->toString()->toChars());
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->import("form-data; name=\"fieldName\"; filename=\"filename.jpg\"");
    if(!disposition->toString()->equals("form-data; name=\"fieldName\"; filename=\"filename.jpg\"")) {
        printf("---[HttpHeaderContentDisposition test toString case3] [FAILED]--- disposition is %s \n",disposition->toString()->toChars());
        break;
    }
    break;
  }
  printf("---[HttpHeaderContentDisposition test toString case100] [OK]--- \n");

}
