#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpHeaderContentLanguage.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentLanguage c = createHttpHeaderContentLanguage();
    c->import("de-DE, en-CA");
    auto list = c->get();
    if(!list->get(0)->equals("de-DE")) {
      printf("---[HttpHeaderContentLanguage test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("en-CA")) {
      printf("---[HttpHeaderContentLanguage test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderContentLanguage test Parse case100] [OK]--- \n");

}
