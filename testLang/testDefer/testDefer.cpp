#include <stdio.h>
#include <unistd.h>

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "Defer.hpp"

using namespace obotcha;

void testDefer() {
   while(1) {
       int value = 0;
       {
           Defer f([&value] {
              value++; 
           });
       }
       
       {
           Defer f([&value] {
              value++; 
           });
       }
       
       {
           Defer f([&value] {
              value++; 
           });
       }
       
       if(value != 3) {
           TEST_FAIL("Defer test case1");
       }
       break;
   }
   TEST_OK("Defer test case100");
}
