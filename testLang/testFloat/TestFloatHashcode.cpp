#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Float.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void hashcodetest() {
  Float t1 = Float::New(1.1);
  Float t2 = Float::New(1.1);
  if(t1->hashcode() != t2->hashcode()) {
    TEST_FAIL("Float hashcode test1");
  }

  Float t3 = Float::New(1.10);
  if(t1->hashcode() != t3->hashcode()) {
    TEST_FAIL("Float hashcode test2");
  }

  Float t4 = Float::New(1.100000001);
  if(t1->hashcode() != t4->hashcode()) {
    TEST_FAIL("Float hashcode test3");
  }

  TEST_OK("Float hashcode test100");
}
