#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHash() {
   Uint16 t1 = Uint16::New(1);
   Uint16 t2 = Uint16::New(2);
   if(t1->hashcode() == t2->hashcode()) {
    TEST_FAIL("Uint16 hashcode test1");
    return;
   }

   t1 = Uint16::New(1);
   t2 = Uint16::New(1);
   if(t1->hashcode() != t2->hashcode()) {
    TEST_FAIL("Uint16 hashcode test2");
    return;
   }

   TEST_OK("Uint16 hashcode test3");
   return;
}
