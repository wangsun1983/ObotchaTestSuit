#include "StringBuffer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      if(!buffer->toString(0,4)->sameAs("abca")) {
        TEST_FAIL("StringBuffer toString test1");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append('a','b','c');
      if(!buffer->toString(0,2)->sameAs("ab")) {
        TEST_FAIL("StringBuffer toString test2");
      }
      break;
    }

    TEST_OK("StringBuffer toString test100");
}
