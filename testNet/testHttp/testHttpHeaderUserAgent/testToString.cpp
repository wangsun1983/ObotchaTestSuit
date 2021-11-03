#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUserAgent.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderUserAgent useragent = createHttpHeaderUserAgent();
    useragent->import(" Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0");
    
    break;
  }

  printf("---[HttpHeaderUpgrade test toString case100] [OK]--- \n");
}
