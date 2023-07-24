#include "StringBuffer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testReset() {
    StringBuffer buff = createStringBuffer();
    buff->append("hello ")
        ->append("world");

    if(!buff->toString()->sameAs("hello world")) {
      TEST_FAIL("StringBuffer testReset test1");
    }

    buff->reset();

    String str = buff->toString();
    if(str->size() != 0) {
      TEST_FAIL("StringBuffer testReset test2,size is %d",str->size());
    }

    TEST_OK("StringBuffer testReset test100");
}
