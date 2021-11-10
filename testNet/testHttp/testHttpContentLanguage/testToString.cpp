#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderContentLanguage.hpp"
#include "HttpProtocol.hpp"
using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentLanguage c = createHttpHeaderContentLanguage();
    c->import("de-DE, en-CA");
    if(c->toString()->equals("de-DE, en-CA ")) {
      printf("---[HttpHeaderContentLanguage test toString case1] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderContentLanguage test toString case100] [OK]--- \n");

}
