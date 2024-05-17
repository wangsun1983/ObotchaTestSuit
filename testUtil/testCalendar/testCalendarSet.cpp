#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "Calendar.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "ArrayList.hpp"
#include "testCalendar.hpp"
#include "ForEveryOne.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

extern ArrayList<TimeData> dateList;
extern ArrayList<TimeData> hourList;
extern ArrayList<TimeData> minuteList;
extern ArrayList<TimeData> secondList;
extern ArrayList<TimeData> yearList;
extern ArrayList<TimeData> monthList;
extern int convertDayOfWeekFromJava(int);

void testCalendarSetYear() {
    int size = yearList->size();
    TimeData d1 = yearList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    
    for(int i = 1;i < size;i = i+3) {
		d1 = yearList->get(i);
        c1->set(st(Calendar)::Field::Year,d1->year);
        if(c1->get(st(Calendar)::Field::Year) != d1->year ||
             c1->get(st(Calendar)::Field::Month) != d1->month ||
             c1->get(st(Calendar)::Field::DayOfYear) != (d1->dayOfYear - 1) ||
             c1->get(st(Calendar)::Field::DayOfWeek) != convertDayOfWeekFromJava(d1->dayOfWeek)||
             c1->get(st(Calendar)::Field::DayOfMonth) != d1->dayOfMonth ||
             c1->get(st(Calendar)::Field::Hour) != d1->hour ||
             c1->get(st(Calendar)::Field::Minute) != d1->minute ||
             c1->get(st(Calendar)::Field::Second) != d1->second ||
             c1->get(st(Calendar)::Field::MilliSecond) != d1->millisecond) {
               printf("Calndear year is %d,data year is %d \n",c1->get(st(Calendar)::Field::Year),d1->year);
               printf("Calndear month is %d,data month is %d \n",c1->get(st(Calendar)::Field::Month),d1->month);
               printf("Calndear dayOfYear is %d,data dayOfYear is %d \n",c1->get(st(Calendar)::Field::DayOfYear),d1->dayOfYear -1);
               printf("Calndear dayOfWeek is %d,data dayOfWeek is %d \n",c1->get(st(Calendar)::Field::DayOfWeek),convertDayOfWeekFromJava(d1->dayOfWeek));
               printf("Calndear dayOfMonth is %d,data dayOfMonth is %d \n",c1->get(st(Calendar)::Field::DayOfMonth),d1->dayOfMonth);
               printf("Calndear hour is %d,data hour is %d \n",c1->get(st(Calendar)::Field::Hour),d1->hour);
               printf("Calndear minute is %d,data minute is %d \n",c1->get(st(Calendar)::Field::Minute),d1->minute);
               printf("Calndear second is %d,data second is %d \n",c1->get(st(Calendar)::Field::Second),d1->second);
               printf("Calndear millisecond is %d,data millisecond is %d \n",c1->get(st(Calendar)::Field::MilliSecond),d1->millisecond);
               printf("current time is %ld \n",d1->time);
               TEST_FAIL("[Calendar Test {testCalendarSet Year()} case1]");
               break;
        }
    }
    
    TEST_OK("testCalendarSet Year case100");
}

void testCalendarSetMonth() {
    int size = monthList->size();
    TimeData d1 = monthList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    for(int i = 1;i < size;i = i+3) {
		d1 = monthList->get(i);
		c1->set(st(Calendar)::Field::Year,d1->year);
        c1->set(st(Calendar)::Field::Month,d1->month);
        if(c1->get(st(Calendar)::Field::Year) != d1->year ||
             c1->get(st(Calendar)::Field::Month) != d1->month ||
             c1->get(st(Calendar)::Field::DayOfYear) != (d1->dayOfYear - 1) ||
             c1->get(st(Calendar)::Field::DayOfWeek) != convertDayOfWeekFromJava(d1->dayOfWeek)||
             c1->get(st(Calendar)::Field::DayOfMonth) != d1->dayOfMonth ||
             c1->get(st(Calendar)::Field::Hour) != d1->hour ||
             c1->get(st(Calendar)::Field::Minute) != d1->minute ||
             c1->get(st(Calendar)::Field::Second) != d1->second ||
             c1->get(st(Calendar)::Field::MilliSecond) != d1->millisecond) {
               printf("Calndear year is %d,data year is %d \n",c1->get(st(Calendar)::Field::Year),d1->year);
               printf("Calndear month is %d,data month is %d \n",c1->get(st(Calendar)::Field::Month),d1->month);
               printf("Calndear dayOfYear is %d,data dayOfYear is %d \n",c1->get(st(Calendar)::Field::DayOfYear),d1->dayOfYear -1);
               printf("Calndear dayOfWeek is %d,data dayOfWeek is %d \n",c1->get(st(Calendar)::Field::DayOfWeek),convertDayOfWeekFromJava(d1->dayOfWeek));
               printf("Calndear dayOfMonth is %d,data dayOfMonth is %d \n",c1->get(st(Calendar)::Field::DayOfMonth),d1->dayOfMonth);
               printf("Calndear hour is %d,data hour is %d \n",c1->get(st(Calendar)::Field::Hour),d1->hour);
               printf("Calndear minute is %d,data minute is %d \n",c1->get(st(Calendar)::Field::Minute),d1->minute);
               printf("Calndear second is %d,data second is %d \n",c1->get(st(Calendar)::Field::Second),d1->second);
               printf("Calndear millisecond is %d,data millisecond is %d \n",c1->get(st(Calendar)::Field::MilliSecond),d1->millisecond);
               printf("current time is %ld \n",d1->time);
               TEST_FAIL("[Calendar Test {testCalendarSetMonth()} case1]");
               break;
        }
    }

    TEST_OK("[Calendar Test {testCalendarSetMonth()} case2]");
}


void testCalendarSetDayOfWeek() {
	auto now = st(System)::CurrentTimeMillis();
	auto c = Calendar::New(now);
    auto year = c->get(st(Calendar)::Field::Year);
	auto month = c->get(st(Calendar)::Field::Month);
	auto dayOfWeek = c->get(st(Calendar)::Field::DayOfWeek);
	auto dayOfMonth = c->get(st(Calendar)::Field::DayOfMonth);
	auto dayOfYear = c->get(st(Calendar)::Field::DayOfYear);
	
	auto baseTimes = c->toTimeMillis() - ((long)dayOfWeek + 1) * 24*60*60*1000;
	for(int i = 0;i < 128;i++) {
		auto value = i%7;
		c->set(st(Calendar)::Field::DayOfWeek,value);
		auto expectTime = baseTimes + ((long)value + 1)*24*60*60*1000;
		auto expectDate = Calendar::New(expectTime);
		if(c->get(st(Calendar)::Field::Year) != expectDate->get(st(Calendar)::Field::Year) ||
		   c->get(st(Calendar)::Field::Month) != expectDate->get(st(Calendar)::Field::Month) ||
		   c->get(st(Calendar)::Field::DayOfWeek) != expectDate->get(st(Calendar)::Field::DayOfWeek) ||
		   c->get(st(Calendar)::Field::DayOfMonth) != expectDate->get(st(Calendar)::Field::DayOfMonth) ||
		   c->get(st(Calendar)::Field::DayOfYear) != expectDate->get(st(Calendar)::Field::DayOfYear)) {
		   TEST_FAIL("[Calendar Test {testCalendarSetDayOfWeek()} case1]");
		}
	}
	
	TEST_OK("[Calendar Test {testCalendarSetDayOfWeek()} case2]");
}

void testCalendarSetDayOfMonth() {
	auto now = st(System)::CurrentTimeMillis();
	auto c = Calendar::New(now);
	auto year = c->get(st(Calendar)::Field::Year);
	auto month = c->get(st(Calendar)::Field::Month);
	auto dayOfWeek = c->get(st(Calendar)::Field::DayOfWeek);
	auto dayOfMonth = c->get(st(Calendar)::Field::DayOfMonth);
	auto dayOfYear = c->get(st(Calendar)::Field::DayOfYear);
	
	auto baseTimes = c->toTimeMillis() - ((long)dayOfMonth) * 24*60*60*1000;
	auto maxdays = c->getMaximum(st(Calendar)::Field::DayOfMonth);
	
	for(int i = 0;i < 128;i++) {
		auto value = i%(maxdays - 1) + 1;
		c->set(st(Calendar)::Field::DayOfMonth,value);
		auto expectTime = baseTimes + ((long)value)*24*60*60*1000;
		auto expectDate = Calendar::New(expectTime);
		if(c->get(st(Calendar)::Field::Year) != expectDate->get(st(Calendar)::Field::Year) ||
		   c->get(st(Calendar)::Field::Month) != expectDate->get(st(Calendar)::Field::Month) ||
		   c->get(st(Calendar)::Field::DayOfWeek) != expectDate->get(st(Calendar)::Field::DayOfWeek) ||
		   c->get(st(Calendar)::Field::DayOfMonth) != expectDate->get(st(Calendar)::Field::DayOfMonth) ||
		   c->get(st(Calendar)::Field::DayOfYear) != expectDate->get(st(Calendar)::Field::DayOfYear)) {
		   TEST_FAIL("[Calendar Test {testCalendarSetDayOfMonth()} case1]");
		}
	}
	
	TEST_OK("[Calendar Test {testCalendarSetDayOfMonth()} case2]");
}

void testCalendarSetDayOfYear() {
	auto now = st(System)::CurrentTimeMillis();
	auto c = Calendar::New(now);
	auto year = c->get(st(Calendar)::Field::Year);
	auto month = c->get(st(Calendar)::Field::Month);
	auto dayOfWeek = c->get(st(Calendar)::Field::DayOfWeek);
	auto dayOfMonth = c->get(st(Calendar)::Field::DayOfMonth);
	auto dayOfYear = c->get(st(Calendar)::Field::DayOfYear);
	
	auto baseTimes = c->toTimeMillis() - ((long)dayOfYear + 1) * 24*60*60*1000;
	auto maxdays = c->getMaximum(st(Calendar)::Field::DayOfYear);
    //printf("maxdays is %d \n",maxdays);
	
	for(int i = 0;i < 366;i++) {
		auto value = i%maxdays;
		c->set(st(Calendar)::Field::DayOfYear,value);
		auto expectTime = baseTimes + ((long)value + 1)*24*60*60*1000;
		auto expectDate = Calendar::New(expectTime);
		if(c->get(st(Calendar)::Field::Year) != expectDate->get(st(Calendar)::Field::Year) ||
		   c->get(st(Calendar)::Field::Month) != expectDate->get(st(Calendar)::Field::Month) ||
		   c->get(st(Calendar)::Field::DayOfWeek) != expectDate->get(st(Calendar)::Field::DayOfWeek) ||
		   c->get(st(Calendar)::Field::DayOfMonth) != expectDate->get(st(Calendar)::Field::DayOfMonth) ||
		   c->get(st(Calendar)::Field::DayOfYear) != expectDate->get(st(Calendar)::Field::DayOfYear)) {
		printf("value is %d \n",value);
		printf("current year is %d,expected is %d \n",c->get(st(Calendar)::Field::Year),expectDate->get(st(Calendar)::Field::Year));
		printf("current month is %d,expected is %d \n",c->get(st(Calendar)::Field::Month),expectDate->get(st(Calendar)::Field::Month));
		printf("current dayofweek is %d,expected is %d \n",c->get(st(Calendar)::Field::DayOfWeek),expectDate->get(st(Calendar)::Field::DayOfWeek));
		printf("current dayofmonth is %d,expected is %d \n",c->get(st(Calendar)::Field::DayOfMonth),expectDate->get(st(Calendar)::Field::DayOfMonth));
		printf("current dayofyear is %d,expected is %d \n",c->get(st(Calendar)::Field::DayOfYear),expectDate->get(st(Calendar)::Field::DayOfYear));
		
		   TEST_FAIL("[Calendar Test {testCalendarSetDayOfYear()} case1]");
		}
	}
	
	TEST_OK("[Calendar Test {testCalendarSetDayOfYear()} case2]");
}

void testCalendarSetYearSpecial() {
	auto c = Calendar::New(2000,st(Calendar)::Month::February,29,1,1,0,0);
	c->set(st(Calendar)::Field::Year,2023);
	// printf("current year is %d \n",c->get(st(Calendar)::Field::Year));
	// printf("current month is %d \n",c->get(st(Calendar)::Field::Month));
	// printf("current dayofweek is %d\n",c->get(st(Calendar)::Field::DayOfWeek));
	// printf("current dayofmonth is %d\n",c->get(st(Calendar)::Field::DayOfMonth));
	// printf("current dayofyear is %d\n",c->get(st(Calendar)::Field::DayOfYear));
	
	if(c->get(st(Calendar)::Field::Year) != 2023 ||
		c->get(st(Calendar)::Field::Month) != 1 ||
		c->get(st(Calendar)::Field::DayOfMonth) != 28 ||
		c->get(st(Calendar)::Field::DayOfWeek) != st(Calendar)::WeekDay::Tuesday) {
		TEST_FAIL("[Calendar Test {testCalendarSetYearSpecial()} case1]");
	}
	
	TEST_OK("[Calendar Test {testCalendarSetYearSpecial()} case2]");
}

void testCalendarSetMonthSpecial() {
	auto c = Calendar::New(2023,st(Calendar)::Month::February,28,1,1,0,0);
	c->set(st(Calendar)::Field::Month,st(Calendar)::Month::April);
	// printf("current year is %d \n",c->get(st(Calendar)::Field::Year));
	// printf("current month is %d \n",c->get(st(Calendar)::Field::Month));
	// printf("current dayofweek is %d\n",c->get(st(Calendar)::Field::DayOfWeek));
	// printf("current dayofmonth is %d\n",c->get(st(Calendar)::Field::DayOfMonth));
	// printf("current dayofyear is %d\n",c->get(st(Calendar)::Field::DayOfYear));
	
	if(c->get(st(Calendar)::Field::Year) != 2023 ||
		c->get(st(Calendar)::Field::Month) != st(Calendar)::Month::April ||
		c->get(st(Calendar)::Field::DayOfMonth) != 28 ||
		c->get(st(Calendar)::Field::DayOfWeek) != st(Calendar)::WeekDay::Friday) {
		TEST_FAIL("[Calendar Test {testCalendarSetMonthSpecial()} case1]");
	}
	
	TEST_OK("[Calendar Test {testCalendarSetYearSpecial()} case2]");
}

void testCalendarSetMonthSpecial2() {
	auto c = Calendar::New(2023,st(Calendar)::Month::April,30,1,1,0,0);
	c->set(st(Calendar)::Field::Month,st(Calendar)::Month::February);
	// printf("current year is %d \n",c->get(st(Calendar)::Field::Year));
	// printf("current month is %d \n",c->get(st(Calendar)::Field::Month));
	// printf("current dayofweek is %d\n",c->get(st(Calendar)::Field::DayOfWeek));
	// printf("current dayofmonth is %d\n",c->get(st(Calendar)::Field::DayOfMonth));
	// printf("current dayofyear is %d\n",c->get(st(Calendar)::Field::DayOfYear));
	
	if(c->get(st(Calendar)::Field::Year) != 2023 ||
		c->get(st(Calendar)::Field::Month) != st(Calendar)::Month::February ||
		c->get(st(Calendar)::Field::DayOfMonth) != 28 ||
		c->get(st(Calendar)::Field::DayOfWeek) != st(Calendar)::WeekDay::Tuesday) {
		TEST_FAIL("[Calendar Test {testCalendarSetMonthSpecial2()} case1]");
	}
	
	TEST_OK("[Calendar Test {testCalendarSetMonthSpecial2()} case2]");
}