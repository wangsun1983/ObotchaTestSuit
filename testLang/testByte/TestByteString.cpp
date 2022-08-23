#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "InitializeException.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testByteString() {
    //case1
    byte v = 10;
    String s = createString(v);
    byte v2 = s->toBasicByte();
    if(v != v2) {
      TEST_FAIL("Byte String test1");
    }

    //case2
    v = 0x12;
    s = createString(v);
    v2 = s->toBasicByte();
    if(v != v2) {
      TEST_FAIL("Byte String test2");
    }

    //case3
    TEST_OK("Byte String test100");
}
