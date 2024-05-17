#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "DateTime.hpp"
#include "Calendar.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void parseISO8601()
{
	DateTime dt = DateTime::New("2005-01-08T12:30:00Z");
	if(dt->year() != 2005 ||
	   dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseISO8601 test1");
	}

	dt = DateTime::New("2005-01-08T12:30:00+01:00");
	if(dt->year() != 2005 ||
	   dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != 3600) {
      TEST_FAIL("DateTime parseISO8601 test2");
	}

	dt = DateTime::New("2005-01-08T12:30:00-01:00");
	if(dt->year() != 2005 ||
	   dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != -3600) {
      TEST_FAIL("DateTime parseISO8601 test3");
	}

	dt = DateTime::New("2005-01-08");
	if(dt->year() != 2005 ||
	   dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 0||
		 dt->minute() != 0||
		 dt->second() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseISO8601 test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
 			        dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
	}
	TEST_OK("DateTime parseISO8601 test5");
}

void parseISO8601Frac()
{
	int tzd;
	DateTime dt = DateTime::New("2005-01-08T12:30:00Z");

	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime testISO8601Frac test1");
	}

	dt = DateTime::New("2005-01-08T12:30:00+01:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != 3600) {
			TEST_FAIL("DateTime testISO8601Frac test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
	}

	dt = DateTime::New("2005-01-08T12:30:00-01:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime testISO8601Frac test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
	}

	dt = DateTime::New("2005-01-08T12:30:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime testISO8601Frac test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
	}

	dt = DateTime::New("2005-01-08");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 0||
		 dt->minute() != 0||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime testISO8601Frac test5,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("2005-01-08T12:30:00.1Z");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 100||
		 dt->microsecond() != 0||
		 dt->tzd() != 0) {
			 TEST_FAIL("DateTime testISO8601Frac test6,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,millsecond is %d,microsecond is %d,tzd is %d \n",
 							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->millisecond(),dt->microsecond(),dt->tzd());

			
	}

	dt = DateTime::New("2005-01-08T12:30:00.123+01:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 123||
		 dt->microsecond() != 0||
		 dt->tzd() != 3600) {
			TEST_FAIL("DateTime testISO8601Frac test7,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("2005-01-08T12:30:00.12345-01:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 123||
		 dt->microsecond() != 450||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime testISO8601Frac test8,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("2010-09-23T16:17:01.2817002+02:00");
	if(dt->year() != 2010 ||
		 dt->month() != st(Calendar)::September ||
		 dt->dayOfMonth() != 23 ||
		 dt->hour() != 16||
		 dt->minute() != 17||
		 dt->second() != 1||
		 dt->millisecond() != 281||
		 dt->microsecond() != 700||
		 dt->tzd() != 7200) {
			TEST_FAIL("DateTime testISO8601Frac test9,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("2005-01-08T12:30:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime testISO8601Frac test10,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("2005-01-08T12:30:00.123456");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->millisecond() != 123||
		 dt->microsecond() != 456||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime testISO8601Frac test11,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("2005-01-08");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 0||
		 dt->minute() != 0||
		 dt->second() != 0||
		 dt->millisecond() != 0||
		 dt->microsecond() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime testISO8601Frac test12,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

  TEST_OK("DateTime testISO8601Frac test13");
}

void parseRFC822() {
	int tzd;
	DateTime dt = DateTime::New("Sat, 8 Jan 05 12:30:00 GMT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseRFC822 test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Sat, 8 Jan 05 12:30:00 +0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != 3600) {
			TEST_FAIL("DateTime parseRFC822 test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Sat, 8 Jan 05 12:30:00 -0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime parseRFC822 test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Tue, 18 Jan 05 12:30:00 CDT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 18 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != -18000) {
			TEST_FAIL("DateTime parseRFC822 test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Wed, 12 Sep 73 02:01:12 CST");
	if(dt->year() != 1973 ||
		 dt->month() != st(Calendar)::September ||
		 dt->dayOfMonth() != 12 ||
		 dt->hour() != 2||
		 dt->minute() != 1||
		 dt->second() != 12||
		 dt->tzd() != -21600) {
			TEST_FAIL("DateTime parseRFC822 test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("12 Sep 73 02:01:12 EST");
	if(dt->year() != 1973 ||
		 dt->month() != st(Calendar)::September ||
		 dt->dayOfMonth() != 12 ||
		 dt->hour() != 2||
		 dt->minute() != 1||
		 dt->second() != 12||
		 dt->tzd() != -18000) {
			TEST_FAIL("DateTime parseRFC822 test5,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}
	TEST_OK("DateTime parseRFC822 test6");
}

void parseRFC1123()
{
	DateTime dt = DateTime::New("Sat, 8 Jan 2005 12:30:00 GMT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime RFC1123 test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}


	dt = DateTime::New("Sat, 8 Jan 2005 12:30:00 +0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != 3600) {
			TEST_FAIL("DateTime RFC1123 test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Sat, 8 Jan 2005 12:30:00 -0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime RFC1123 test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Tue, 18 Jan 2005 12:30:00 CDT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 18 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0||
		 dt->tzd() != -18000) {
			TEST_FAIL("DateTime RFC1123 test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Wed, 12 Sep 1973 02:01:12 CST");
	if(dt->year() != 1973 ||
		 dt->month() != st(Calendar)::September ||
		 dt->dayOfMonth() != 12 ||
		 dt->hour() != 2||
		 dt->minute() != 1||
		 dt->second() != 12||
		 dt->tzd() != -21600) {
			TEST_FAIL("DateTime RFC1123 test5,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("12 Sep 1973 02:01:12 EST");
	if(dt->year() != 1973 ||
		 dt->month() != st(Calendar)::September ||
		 dt->dayOfMonth() != 12 ||
		 dt->hour() != 2||
		 dt->minute() != 1||
		 dt->second() != 12||
		 dt->tzd() != -18000) {
			TEST_FAIL("DateTime RFC1123 test6,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}
  TEST_OK("DateTime RFC1123 test7");
}

void parseHTTP()
{
	DateTime dt = DateTime::New("Sat, 08 Jan 2005 12:30:00 GMT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0) {
			TEST_FAIL("DateTime parseHttp test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Sat, 08 Jan 2005 12:30:00 +0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
	   dt->tzd() != 3600) {
			TEST_FAIL("DateTime parseHttp test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());

			
	}

	dt = DateTime::New("Sat, 08 Jan 2005 12:30:00 -0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime parseHttp test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}
  TEST_OK("DateTime parseHttp test4");
}

void parseRFC850()
{
	DateTime dt = DateTime::New("Saturday, 8-Jan-05 12:30:00 GMT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseRFC850 test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New("Saturday, 8-Jan-05 12:30:00 +0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != 3600) {
			TEST_FAIL("DateTime parseRFC850 test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New("Saturday, 8-Jan-05 12:30:00 -0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime parseRFC850 test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New("Wed, 12-Sep-73 02:01:12 CST");
	if(dt->year() != 1973 ||
		 dt->month() != st(Calendar)::September ||
		 dt->dayOfMonth() != 12 ||
		 dt->hour() != 2||
		 dt->minute() != 1||
		 dt->second() != 12 ||
		 dt->tzd() != -21600) {
			TEST_FAIL("DateTime parseRFC850 test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}
	TEST_OK("DateTime parseRFC850 test5");
}

void parseRFC1036() {
	DateTime dt = DateTime::New("Saturday, 8 Jan 05 12:30:00 GMT");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseRFC1036 test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New("Saturday, 8 Jan 05 12:30:00 +0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != 3600) {
			TEST_FAIL("DateTime parseRFC1036 test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New("Saturday, 8 Jan 05 12:30:00 -0100");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != -3600) {
			TEST_FAIL("DateTime parseRFC1036 test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}
	TEST_OK("DateTime parseRFC1036 test4");
}

void parseASCTIME() {
	DateTime dt = DateTime::New("Sat Jan  8 12:30:00 2005");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseASCTIME test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}
	TEST_OK("DateTime parseASCTIME test1");
}

void parseSORTABLE() {
	DateTime dt = DateTime::New("2005-01-08 12:30:00");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseSORTABLE test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New("2005-01-08");
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 8 ||
		 dt->hour() != 0||
		 dt->minute() != 0||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseSORTABLE test2,DateTime parseCustom test1year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}
	TEST_OK("DateTime parseSORTABLE test3");
}

void parseCustom() {
	DateTime dt = DateTime::New(String::New("%d-%b-%Y"),String::New("18-Jan-2005"));
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 18 ||
		 dt->hour() != 0||
		 dt->minute() != 0||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseCustom test1,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New(String::New("%m/%d/%y"),String::New("01/18/05"));
	if(dt->year() != 2005 ||
		 dt->month() != st(Calendar)::January ||
		 dt->dayOfMonth() != 18 ||
		 dt->hour() != 0||
		 dt->minute() != 0||
		 dt->second() != 0 ||
		 dt->tzd() != 0) {
			TEST_FAIL("DateTime parseCustom test2,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New(String::New("%h:%M %a"),String::New("12:30 am"));
	if(dt->hour() != 0||
		 dt->minute() != 30||
		 dt->second() != 0 ) {
			TEST_FAIL("DateTime parseCustom test3,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	dt = DateTime::New(String::New("%h:%M %a"),String::New("12:30 PM"));
	if(dt->hour() != 12||
		 dt->minute() != 30||
		 dt->second() != 0 ) {
			TEST_FAIL("DateTime parseCustom test4,year is %d,month is %d,dayOfMonth is %d,hour is %d,minute is %d,second is %d,tzd is %d \n",
							dt->year(),dt->month(),dt->dayOfMonth(),dt->hour(),dt->minute(),dt->second(),dt->tzd());
			
	}

	TEST_OK("DateTime parseCustom test5");
}

void parsetest() {
	parseISO8601();
	parseISO8601Frac();
	parseRFC822();
	parseRFC1123();
	parseHTTP();
	parseRFC850();
	parseRFC1036();
	parseASCTIME();
	parseSORTABLE();
	parseCustom();
}
