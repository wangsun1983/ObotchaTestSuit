#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Float.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

const float EPSINON = 0.00001;

void compareTest() {
	if(st(Float)::Compare(2.11,2.110) != 0) {
		TEST_FAIL("Float compare test1");
	}
	
	if(st(Float)::Compare(2.11,2.09) != 1) {
		TEST_FAIL("Float compare test2");
	}
	
	if(st(Float)::Compare(1.11,2.09) != -1) {
		TEST_FAIL("Float compare test3");
	}
	
	TEST_OK("Float compare test4");
}
