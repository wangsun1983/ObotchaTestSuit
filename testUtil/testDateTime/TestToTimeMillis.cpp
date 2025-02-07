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

void testToTimeMillis() {
	Calendar now = Calendar::New();
	DateTime date = now->getDateTime();
	if(date->toTimeMillis() != now->toTimeMillis()) {
		TEST_FAIL("DateTime toTimeMillis test1,now is %ld,date is %ld",now->toTimeMillis(),date->toTimeMillis());
    }

	TEST_OK("DateTime toTimeMillis test100");
}
