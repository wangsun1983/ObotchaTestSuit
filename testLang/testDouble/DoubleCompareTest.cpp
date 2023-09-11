#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void compareTest() {
	if(st(Double)::Compare(2.11,2.110) != 0) {
		TEST_FAIL("Double compare test1");
	}
	
	if(st(Double)::Compare(2.11,2.09) != 1) {
		TEST_FAIL("Double compare test2");
	}
	
	if(st(Double)::Compare(1.11,2.09) != -1) {
		TEST_FAIL("Double compare test3");
	}
	
	TEST_OK("Double compare test4");
}
