#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptLanguage.hpp"

using namespace obotcha;

void testLanguageToString() {

  while(1) {
    HttpHeaderAcceptLanguage encoding1 = createHttpHeaderAcceptLanguage();
    encoding1->import("fr-CH,fr;q=0.9,en;q=0.8,de;q=0.7,*;q=0.5");
    if(!encoding1->toString()->equals("fr-CH,fr;q=0.9,en;q=0.8,de;q=0.7,*;q=0.5")) {
      printf("---[HttpHeaderAcceptLanguage test toString case1] [FAILED]---,str is %s \n",encoding1->toString()->toChars());
    }
    break;
  }

  printf("---[HttpHeaderAcceptLanguage test toString case100] [OK]--- \n");

}
