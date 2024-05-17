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

void testParse() {
  while(1) {
    HttpHeaderContentLength upgrade = HttpHeaderContentLength::New();
    upgrade->load(" 123 ");
    if(upgrade->get() != 123) {
      TEST_FAIL("[HttpHeaderContentLength test Parse case1]");
    }
    break;
  }

  TEST_OK("[HttpHeaderContentLength test Parse case100]");
}
