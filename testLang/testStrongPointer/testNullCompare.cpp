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

DECLARE_CLASS(TestNullData) {
public:
	int v;
};

void testNullCompare() {
  //test null compare
  while(1) {
	TestNullData d1;
	if(d1 != nullptr) {
		TEST_FAIL("StrongPointer operator null  case1");
	}
	
	break;
  }
  
  TEST_OK("StrongPointer operator null case100");
}
