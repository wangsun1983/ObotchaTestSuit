#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint8.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHash() {
   Uint8 t1 = createUint8(1);
   Uint8 t2 = createUint8(2);
   if(t1->hashcode() == t2->hashcode()) {
    TEST_FAIL("Uint8 hashcode test1");
    return;
   }

   t1 = createUint8(1);
   t2 = createUint8(1);
   if(t1->hashcode() != t2->hashcode()) {
    TEST_FAIL("Uint8 hashcode test2");
    return;
   }

   TEST_OK("Uint8 hashcode test3");
   return;
}
