#include "StringBuffer.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testAppend() {
    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      if(!buffer->toString()->sameAs("abcabc2abc3")) {
        TEST_FAIL("StringBuffer append test1");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append('a','b','c');
      if(!buffer->toString()->sameAs("abc")) {
        TEST_FAIL("StringBuffer append test2");
      }
      break;
    }

    TEST_OK("StringBuffer append test100");
}
