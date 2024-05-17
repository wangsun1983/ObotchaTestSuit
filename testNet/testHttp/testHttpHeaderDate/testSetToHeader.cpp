#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDate.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"
#include "HttpDate.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Date"),
                String::New(" Wed, 21 Oct 2015 07:28:00 GMT"));
    
    auto headerDate = header->getDate();
    auto date = headerDate->get()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case1]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case2]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case3]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case4]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case5]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case6]");
      break;
    }

    break;
  }
  
  while(1) {
    HttpHeader header = HttpHeader::New();
    HttpHeaderDate date_1 = HttpHeaderDate::New(String::New(" Wed, 21 Oct 2015 07:28:00 GMT"));
    header->setDate(date_1);
    
    auto headerDate = header->getDate();
    auto date = headerDate->get()->toDateTime();
    if(date->year() != 2015) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case7]");
      break;
    }

    if(date->month() != st(Calendar)::October) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case8]");
      break;
    }

    if(date->dayOfWeek() != st(Calendar)::Wednesday) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case9]");
      break;
    }

    if(date->hour() != 7) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case10]");
      break;
    }

    if(date->minute() != 28) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case11]");
      break;
    }

    if(date->second() != 0) {
      TEST_FAIL("[HttpHeaderDate test SetToHeader case12]");
      break;
    }

    break;
  }


  TEST_OK("[HttpHeaderDate test SetToHeader case100]");

}
