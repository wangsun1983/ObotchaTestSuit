#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderContentLength.hpp"

using namespace obotcha;

void testSetGet() {
  while(1) {
    HttpHeaderContentLength content = HttpHeaderContentLength::New();
    content->load(" 123 ");
    if(content->get() != 123) {
      TEST_FAIL("[HttpHeaderContentLength test GetSet case1]");
    }
    
    content->set(12);
    if(content->get() != 12) {
        TEST_FAIL("[HttpHeaderContentLength test GetSet case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLength test GetSet case100]");
}
