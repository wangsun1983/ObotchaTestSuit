#include "StringBuffer.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSubString() {
    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      buffer->subString(0,4)->append("123");
      if(!buffer->toString()->equals("abca123")) {
        TEST_FAIL("StringBuffer subString test1,buffer is %s",buffer->toString()->toChars());
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      buffer->subString(1,4)->append("123");
      if(!buffer->toString()->equals("bcab123")) {
        TEST_FAIL("StringBuffer subString test2,buffer is %s",buffer->toString()->toChars());
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer();
      buffer->append("abcd");
      buffer->subString(1,3);
      if(!buffer->toString()->equals("bcd")) {
        TEST_FAIL("StringBuffer subString test3");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcd");
      //TEST_FAIL("capacity is %d,size is %d \n",buffer->capacity(),buffer->size());

      buffer->subString(0,4);
      if(!buffer->toString()->equals("abcd")) {
        TEST_FAIL("StringBuffer subString test4");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcd");
      bool isExcept = false;
      try {
        buffer->subString(1,4);
      } catch(...) {
        isExcept = true;
      }

      if(!isExcept) {
        TEST_FAIL("StringBuffer subString test5");
      }
      break;
    }
    
    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcde");
      
      if(!buffer->toString()->equals("abcde")) {
          TEST_FAIL("StringBuffer subString test6");
      }
      
      buffer->subString(1,3);
      if(!buffer->toString()->equals("bcd")) {
          TEST_FAIL("StringBuffer subString test7");
      }
      
      buffer->subString(1,1);
      if(!buffer->toString()->equals("c")) {
          TEST_FAIL("StringBuffer subString test8");
      }
      break;
    }

    TEST_OK("StringBuffer subString test100");
}
