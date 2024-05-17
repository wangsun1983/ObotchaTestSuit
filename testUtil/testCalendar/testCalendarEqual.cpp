#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "Calendar.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "ArrayList.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testCalendarEqual() {
    auto time = st(System)::CurrentTimeMillis();
	auto c1 = Calendar::New(time);
	auto c2 = Calendar::New(time);
	if(c1 != c2) {
		TEST_FAIL("testCalendar equal case1");
	}
	
	auto c3 = Calendar::New(time + 1);
	if(c1 == c3) {
		TEST_FAIL("testCalendar equal case2");
	}
    
    TEST_OK("testCalendar equal case100");
}
