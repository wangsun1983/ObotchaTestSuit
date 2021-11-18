#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentLocation.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentLocation location = createHttpHeaderContentLocation();
    location->import("/index.html");
    if(!location->toString()->equals("/index.html")) {
      printf("---[HttpHeaderContentLocation test toString case1] [FAILED]--- ,str is %s\n",location->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderContentLocation test toString case100] [OK]--- \n");

}
