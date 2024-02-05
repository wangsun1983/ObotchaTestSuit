#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "Calendar.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "ArrayList.hpp"
#include "testCalendar.hpp"
#include "TextLineReader.hpp"
#include "ForEveryOne.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "System.hpp"

using namespace obotcha;

DECLARE_CLASS(MaxiumData) {
public:
	long millseconds;
	int maxDayOfWeek;
	int maxDayOfMonth;
	int maxDayOfYear;
};

void testCalendarGetMaxium() {
	//load data first
	ArrayList<MaxiumData> list = createArrayList<MaxiumData>();
	File f = createFile("./testData/maxium.txt");
	if(!f->exists()) {
		printf("file not found \n");
	}
	TextLineReader reader = createTextLineReader(f);
	MaxiumData data = nullptr;
	
	while(1) {
	    String content = reader->readLine();
		if(content == nullptr) {
			break;
		}

		if(content->indexOf("-------") != -1) {
			if(data != nullptr) {
				list->add(data);
			}
			data = createMaxiumData();
		} else if(content->indexOf("time is") != -1) {
			int index = content->lastIndexOf(" ");
			String timeStr = content->subString(index + 1,content->size() - index - 1);
			long value = timeStr->toBasicLong();
			data->millseconds = value;
		} else if(content->indexOf("MaxDayOfYear") != -1) {
			int index = content->lastIndexOf(" ");
			String timeStr = content->subString(index + 1,content->size() - index - 1);
			int value = timeStr->toBasicInt();
			data->maxDayOfYear = value;
		} else if(content->indexOf("MaxDayOfMonth") != -1) {
			int index = content->lastIndexOf(" ");
			String timeStr = content->subString(index + 1,content->size() - index - 1);
			int value = timeStr->toBasicInt();
			data->maxDayOfMonth = value;
		} else if(content->indexOf("MaxDayOfWeek") != -1) {
			int index = content->lastIndexOf(" ");
			String timeStr = content->subString(index + 1,content->size() - index - 1);
			int value = timeStr->toBasicInt();
			data->maxDayOfWeek = value;
		}
	}
	
	ForEveryOne(date,list) {
		auto millseconds = date->millseconds;
		auto c = createCalendar(millseconds);
		if(c->getMaximum(st(Calendar)::Field::DayOfYear) != date->maxDayOfYear) {
			TEST_FAIL("Calendar getMax case1,year is %d,maxDayOfYear is %d,expected is %d",
						c->get(st(Calendar)::Field::Year),
						c->getMaximum(st(Calendar)::Field::DayOfYear),
						date->maxDayOfYear);
			break;
		}
		
		if(c->getMaximum(st(Calendar)::Field::DayOfMonth) != date->maxDayOfMonth) {
			TEST_FAIL("Calendar getMax case2,year is %d,maxDayOfMonth is %d,expected is %d",
						c->get(st(Calendar)::Field::Year),
						c->getMaximum(st(Calendar)::Field::DayOfMonth),
						date->maxDayOfYear);
			break;
		}
		
		if(c->getMaximum(st(Calendar)::Field::DayOfWeek) != date->maxDayOfWeek) {
			TEST_FAIL("Calendar getMax case3");
			break;
		}
	}
	TEST_OK("Calendar getMax case100");
}