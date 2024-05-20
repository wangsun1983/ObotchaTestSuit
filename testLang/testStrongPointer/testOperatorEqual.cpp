#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "System.hpp"
#include "File.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

DECLARE_CLASS(TestEqualData) {
public:
	int v;
};

DECLARE_CLASS(TestEqualData1) {
public:
	int v;
	bool equals(Object o) {
		auto val = Cast<TestEqualData1>(o);
		return val->v == v;
	}
};

void testOperatorEqual() {
  //test null compare
  while(1) {
	TestEqualData d1 = TestEqualData::New();
	if(d1 == nullptr) {
		TEST_FAIL("StrongPointer operator equal case1");
	}
	
	TestEqualData d2 = TestEqualData::New();
	TestEqualData d3;
	if(d2 == d3 || d3 == d2) {
		TEST_FAIL("StrongPointer operator equal case2");
	}
	
	TestEqualData d4;
	TestEqualData d5;
	if(d4 != d5) {
		TEST_FAIL("StrongPointer operator equal case3");
	}
	
	if(d4 != nullptr) {
		TEST_FAIL("StrongPointer operator equal case4");
	}
	break;
  }
  
  while(1) {
	  TestEqualData1 d1 = TestEqualData1::New();
	  d1->v = 1123;
	  
	  TestEqualData1 d2 = TestEqualData1::New();
	  d2->v = 1123;
	  
	  if(d1 != d2 || d2 != d1) {
		  TEST_FAIL("StrongPointer operator equal case5");
	  }
	  
	  TestEqualData1 d3;
	  TestEqualData1 d4;
	  if(d3 != d4 || d3 != d4) {
	  	TEST_FAIL("StrongPointer operator equal case6");
	  }
	  
	  break;
  }
  
  TEST_OK("StrongPointer operator equal case100");
}
