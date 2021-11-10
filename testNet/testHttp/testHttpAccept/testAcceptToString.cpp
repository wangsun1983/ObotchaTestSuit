#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"

using namespace obotcha;

void testEncodingToString() {
  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->import("text/html");
    if(!encoding1->toString()->equals("text/html")) {
      printf("---[HttpHeaderAccept test toString case1] [FAILED]--- encoding is %s\n",encoding1->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->import("image/*");
    if(!encoding1->toString()->equals("image/*")) {
      printf("---[HttpHeaderAccept test toString case2] [FAILED]--- encoding is %s\n",encoding1->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderAccept encoding1 = createHttpHeaderAccept();
    encoding1->import("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    if(!encoding1->toString()->equals("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8")) {
      printf("---[HttpHeaderAccept test toString case3] [FAILED]--- encoding is %s\n",encoding1->toString()->toChars());
    }
    break;
  }

  printf("---[HttpHeaderAccept test toString case100] [OK]--- \n");

}
