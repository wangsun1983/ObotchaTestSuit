#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "TestLog.hpp"
#include "String.hpp"

using namespace obotcha;


void testByteArrayStringConvert() {
  while(1) {
    String str = createString("abc test");
    ByteArray array = str->toByteArray();

    String v = array->toString();
    //TEST_FAIL("v is %s \n",v->toChars());
    if(!v->equals(str)) {
      TEST_FAIL("ByteArray  ByteArray String Convert test 1");
    }
    break;
  }

  TEST_OK("ByteArray  ByteArray String Convert test 100");
}
