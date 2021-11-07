#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpContentSecurityPolicy.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpContentSecurityPolicy policy = createHttpContentSecurityPolicy();
    policy->import("default-src   'self'; img-src *;  media-src media1.com   media2.com; script-src   userscripts.example.com");
    if(!policy->toString()->equals("default-src 'self'; img-src *; media-src media1.com media2.com; script-src userscripts.example.com")) {
      printf("---[HttpContentSecurityPolicy test toString case1] [FAILED]---,str is %s \n",policy->toString()->toChars());
    }
    break;
  }

  printf("---[HttpContentSecurityPolicy test toString case100] [OK]--- \n");

}
