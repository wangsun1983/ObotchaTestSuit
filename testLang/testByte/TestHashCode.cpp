#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Byte.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHash() {
   Byte t1 = Byte::New(1);
   Byte t2 = Byte::New(2);
   if(t1->hashcode() == t2->hashcode()) {
    TEST_FAIL("Byte hashcode test1");
    return;
   }

   t1 = Byte::New(1);
   t2 = Byte::New(1);
   if(t1->hashcode() != t2->hashcode()) {
    TEST_FAIL("Byte hashcode test2");
    return;
   }

   TEST_OK("Byte hashcode test3");
   return;
}
