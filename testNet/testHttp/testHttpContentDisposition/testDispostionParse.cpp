#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentDisposition.hpp"
#include "Math.hpp"

using namespace obotcha;

void testDispositionParse() {
  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->import("attachment");
    if(!disposition->type->equals("attachment")) {
        printf("---[HttpHeaderContentDisposition test Parse case1] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->import("attachment; filename=\"filename.jpg\"");
    if(!disposition->type->equals("attachment")) {
        printf("---[HttpHeaderContentDisposition test Parse case2] [FAILED]--- \n");
        break;
    }

    if(!disposition->filename->equals("filename.jpg")) {
        printf("---[HttpHeaderContentDisposition test Parse case3] [FAILED]--- \n");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderContentDisposition disposition = createHttpHeaderContentDisposition();
    disposition->import("form-data; name=\"fieldName\"; filename=\"filename.jpg\"");
    if(!disposition->type->equals("form-data")) {
        printf("---[HttpHeaderContentDisposition test Parse case4] [FAILED]--- \n");
        break;
    }

    if(!disposition->filename->equals("filename.jpg")) {
        printf("---[HttpHeaderContentDisposition test Parse case5] [FAILED]--- \n");
        break;
    }

    if(!disposition->name->equals("fieldName")) {
        printf("---[HttpHeaderContentDisposition test Parse case6] [FAILED]--- \n");
        break;
    }
    break;
  }

  printf("---[HttpHeaderContentDisposition test Parse case100] [OK]--- \n");

}
