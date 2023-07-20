#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentSecurityPolicy.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderContentSecurityPolicy policy = createHttpHeaderContentSecurityPolicy();
    policy->load("default-src   'self'; img-src *;  media-src media1.com   media2.com; script-src   userscripts.example.com");
    if(!policy->toString()->equals("default-src 'self'; img-src *; media-src media1.com media2.com; script-src userscripts.example.com")) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test toString case1],str is %s",policy->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderContentSecurityPolicy test toString case100]");

}
