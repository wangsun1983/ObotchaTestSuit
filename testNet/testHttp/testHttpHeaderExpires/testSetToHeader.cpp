#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderExpires.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    //HttpHeaderExpires headerDate = HttpHeaderExpires::New();
    header->set(String::New("Expires"),String::New(" Wed, 21 Oct 2015 07:28:00 GMT"));
    auto headerDate = header->getExpires();
    auto date = headerDate->get()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderExpires test SetToHeader case1]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderExpires test SetToHeader case2]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderExpires test SetToHeader case3]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderExpires test SetToHeader case4]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderExpires test SetToHeader case5]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderExpires test SetToHeader case6]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderExpires test SetToHeader case100]");

}
