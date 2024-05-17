#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "Calendar.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "ArrayList.hpp"
#include "testCalendar.hpp"
#include "TestLog.hpp"

using namespace obotcha;

extern ArrayList<TimeData> dateList;
extern ArrayList<TimeData> hourList;
extern ArrayList<TimeData> minuteList;
extern ArrayList<TimeData> secondList;
extern ArrayList<TimeData> yearList;
extern ArrayList<TimeData> monthList;

extern int convertDayOfWeekFromJava(int);

int testCalendarIncreaseYear() {
    int size = yearList->size();
    TimeData d1 = yearList->get(0);

    Calendar c1 = Calendar::New(d1->time);

    //printf("testCalendarIncreaseYear d1->year is %d \n",d1->year);
    //printf("testCalendarIncreaseYear c1 is %d \n",c1->get(st(Calendar)::Field::Year));

    for(int i = 1;i < size;i++) {
        c1->add(st(Calendar)::Field::Year,1);
        d1 = yearList->get(i);
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
               TEST_FAIL("[Calendar Test {testCalendarIncreaseYear()} case1]");
               return -1;
        }
    }

    TEST_OK("[Calendar Test {testCalendarIncreaseYear()} case2]");
    return 0;
}

int testCalendarIncreaseDay() {
    int size = dateList->size();
    TimeData d1 = dateList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    for(int i = 1;i < size;i++) {
        c1->add(st(Calendar)::Field::DayOfYear,1);
        d1 = dateList->get(i);
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
               TEST_FAIL("[Calendar Test {testCalendarIncreaseDay()} case1]");
               return -1;
        }
    }

    TEST_OK("[Calendar Test {testCalendarIncreaseDay()} case2]");
    return 0;
}

int testCalendarIncreaseMonth() {
    int size = monthList->size();
    TimeData d1 = monthList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    for(int i = 1;i < size;i++) {
        c1->add(st(Calendar)::Field::Month,1);
        d1 = monthList->get(i);
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
               TEST_FAIL("[Calendar Test {testCalendarIncreaseMonth()} case1]");
               return -1;
        }
    }

    TEST_OK("[Calendar Test {testCalendarIncreaseMonth()} case2]");
    return 0;
}


//increaseHour
int testCalendarIncreaseHour() {
    int size = hourList->size();
    TimeData d1 = hourList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    for(int i = 1;i < size;i++) {
        c1->add(st(Calendar)::Field::Hour,1);
        d1 = hourList->get(i);
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
               TEST_FAIL("[Calendar Test {increaseHour()} case1]");
               return -1;
        }
    }

    TEST_OK("[Calendar Test {increaseHour()} case2]");
    return 0;
}

//increaseMinute
int testCalendarIncreaseMinute() {
    int size = minuteList->size();
    TimeData d1 = minuteList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    for(int i = 1;i < size;i++) {
        c1->add(st(Calendar)::Field::Minute,1);
        d1 = minuteList->get(i);
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
               TEST_FAIL("[Calendar Test {increaseMinute()} case1]");
               return -1;
        }
    }

    TEST_OK("[Calendar Test {increaseMinute()} case2]");
    return 0;
}

//secondList
int testCalendarIncreaseSecond() {
    int size = secondList->size();
    TimeData d1 = secondList->get(0);
    Calendar c1 = Calendar::New(d1->time);
    for(int i = 1;i < size;i++) {
        c1->add(st(Calendar)::Field::Second,1);
        d1 = secondList->get(i);
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
               TEST_FAIL("[Calendar Test {increaseSecond()} case1]");
               return -1;
        }
    }

    TEST_OK("[Calendar Test {increaseSecond()} case2]");
    return 0;
}
