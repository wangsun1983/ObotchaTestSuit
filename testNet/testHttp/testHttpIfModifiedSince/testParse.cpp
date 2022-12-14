#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderIfModifiedSince.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPatchParse() {
  while(1) {
    HttpHeaderIfModifiedSince modifiedSince = createHttpHeaderIfModifiedSince();
    modifiedSince->import(" Wed, 21 Oct 2015 07:28:00 GMT");
    auto date = modifiedSince->get()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case1]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case2]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case3]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case4]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case5]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case6]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderIfModifiedSince modifiedSince = createHttpHeaderIfModifiedSince(" Wed, 21 Oct 2015 07:28:00 GMT");
    auto date = modifiedSince->get()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case7]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case8]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case9]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case10]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case11]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderIfModifiedSince test Parse case12]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderIfModifiedSince test Parse case100]");

}
