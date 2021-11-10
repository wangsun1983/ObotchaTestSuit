#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderLastModified.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderLastModified headerDate = createHttpHeaderLastModified();
    headerDate->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    if(!headerDate->toString()->equals("Wed, 21 Oct 2015 07:28:00 GMT")) {
      printf("---[HttpHeaderLastModified test toString case1] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderLastModified test toString case100] [OK]--- \n");

}
