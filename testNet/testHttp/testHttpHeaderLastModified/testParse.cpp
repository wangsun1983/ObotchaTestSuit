#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderLastModified.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderLastModified headerDate = HttpHeaderLastModified::New();
    headerDate->load(" Wed, 21 Oct 2015 07:28:00 GMT");
    auto date = headerDate->get()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderLastModified test Parse case1]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderLastModified test Parse case2]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderLastModified test Parse case3]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderLastModified test Parse case4]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderLastModified test Parse case5]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderLastModified test Parse case6]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderLastModified test Parse case100]");

}
