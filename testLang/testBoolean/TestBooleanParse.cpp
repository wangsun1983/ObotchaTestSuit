#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"
#include "String.hpp"

using namespace obotcha;

void testBooleanParse() {

    String s1 = String::New("true");
    if(!st(Boolean)::Parse(s1)->toValue()) {
      TEST_FAIL("testBooleanParse case1");
    }

    String s2 = String::New("false");
    if(st(Boolean)::Parse(s2)->toValue()) {
      TEST_FAIL("testBooleanParse case2");
    }

    String s3;
    try {
      auto v = st(Boolean)::Parse(s3);
      TEST_FAIL("testBooleanParse case3");
    }catch(...) {

    }
}
