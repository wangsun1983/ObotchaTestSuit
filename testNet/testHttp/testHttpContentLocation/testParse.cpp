#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentLocation.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentLocation location = createHttpHeaderContentLocation();
    location->import("/index.html");
    if(location->get() == nullptr || !location->get()->equals("/index.html")) {
      printf("---[HttpHeaderContentLocation test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderContentLocation test Parse case100] [OK]--- \n");

}
