#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint64.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Uint64.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashCode() {

  while(1) {
      Uint64 v1 = createUint64(10);
      Uint64 v2 = createUint64(10);
      if(v1->hashcode() != v2->hashcode()){
          TEST_FAIL("Uint64 hashcode test1");
          break;
      }

      Uint64 v3 = createUint64(10);
      Uint64 v4 = createUint64(11);
      if(v3->hashcode() == v4->hashcode()){
          TEST_FAIL("Uint64 hashcode test2");
          break;
      }

      TEST_OK("Uint64 hashcode test3");
      break;
  }
}
