#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
    Double d1 = createDouble(1.1);
    if(!d1->toString()->sameAs("1.1")) {
        TEST_FAIL("Double toString test1,d1 is %s \n",d1->toString()->toChars());
    }
	
	d1 = createDouble(12.1231);
	if(!d1->toString()->sameAs("12.1231")) {
	    TEST_FAIL("Double toString test2,d1 is %s \n",d1->toString()->toChars());
	}

    TEST_OK("Double toString test2");
}
