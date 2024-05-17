#include "StringBuffer.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSubString() {
    while(1) {
      StringBuffer buffer = StringBuffer::New(1);
      buffer->append("abc","abc2","abc3");
      auto ret = buffer->subString(0,4)->append("123");
      if(!ret->sameAs("abca123")) {
        TEST_FAIL("StringBuffer subString test1,buffer is %s",buffer->toString()->toChars());
      }
      break;
    }

    while(1) {
      StringBuffer buffer = StringBuffer::New(1);
      buffer->append("abc","abc2","abc3");
      auto ret = buffer->subString(1,4)->append("123");
      if(!ret->sameAs("bcab123")) {
        TEST_FAIL("StringBuffer subString test2,buffer is %s",buffer->toString()->toChars());
      }
      break;
    }

    while(1) {
      StringBuffer buffer = StringBuffer::New();
      buffer->append("abcd");
      auto ret = buffer->subString(1,3);
      if(!ret->sameAs("bcd")) {
        TEST_FAIL("StringBuffer subString test3");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = StringBuffer::New(5);
      buffer->append("abcd");
      //TEST_FAIL("capacity is %d,size is %d \n",buffer->capacity(),buffer->size());

      auto ret = buffer->subString(0,4);
      if(!ret->sameAs("abcd")) {
        TEST_FAIL("StringBuffer subString test4");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = StringBuffer::New(5);
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
      StringBuffer buffer = StringBuffer::New(5);
      buffer->append("abcde");
      
      if(!buffer->toString()->sameAs("abcde")) {
          TEST_FAIL("StringBuffer subString test6");
      }
      
      auto ret = buffer->subString(1,3);
      if(!ret->sameAs("bcd")) {
          TEST_FAIL("StringBuffer subString test7");
      }
      
      ret = buffer->subString(1,1);
      if(!ret->sameAs("b")) {
          TEST_FAIL("StringBuffer subString test8,ret is %s",ret->toChars());
      }
      break;
    }

    TEST_OK("StringBuffer subString test100");
}
