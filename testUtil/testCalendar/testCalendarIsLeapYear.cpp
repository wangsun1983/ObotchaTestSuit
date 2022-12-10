#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "Calendar.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "ArrayList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCalendarIsLeapYear() {
    int leapyear[] = {1952,1956,1960,1964,1968,
                      1972,1976,1980,1984,1988,
                      1992,1996,2000,2004,2008,
                      2012,2016,2020,2024,2028,
                      2032,2036,2040,2044,2048};
    
    for(int i = 1952;i < 2048;i++) {
        bool expectResult = false;
        for(int j = 0;j < sizeof(leapyear)/sizeof(int);j++) {
            if(i == leapyear[j]) {
                expectResult = true;
                break;
            }
        }
        
        if(expectResult != st(Calendar)::isLeapYear(i)) {
            TEST_FAIL("testCalendarIsLeapYear case1,year is %d",i);
        }
    }
    
    TEST_OK("testCalendarIsLeapYear case100");
}
