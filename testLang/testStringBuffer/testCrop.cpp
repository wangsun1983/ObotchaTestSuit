#include "StringBuffer.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCrop() {
    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      buffer->crop(0,4)->append("123");
      if(!buffer->toString()->sameAs("abca123")) {
        TEST_FAIL("StringBuffer crop test1,buffer is %s",buffer->toString()->toChars());
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      buffer->crop(1,4)->append("123");
      if(!buffer->toString()->sameAs("bcab123")) {
        TEST_FAIL("StringBuffer crop test2,buffer is %s",buffer->toString()->toChars());
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer();
      buffer->append("abcd");
      buffer->crop(1,3);
      if(!buffer->toString()->sameAs("bcd")) {
        TEST_FAIL("StringBuffer crop test3");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcd");
      //TEST_FAIL("capacity is %d,size is %d \n",buffer->capacity(),buffer->size());

      buffer->crop(0,4);
      if(!buffer->toString()->sameAs("abcd")) {
        TEST_FAIL("StringBuffer crop test4");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcd");
      bool isExcept = false;
      try {
        buffer->crop(1,4);
      } catch(...) {
        isExcept = true;
      }

      if(!isExcept) {
        TEST_FAIL("StringBuffer crop test5");
      }
      break;
    }
    
    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcde");
      
      if(!buffer->toString()->sameAs("abcde")) {
          TEST_FAIL("StringBuffer crop test6");
      }
      
      buffer->crop(1,3);
      if(!buffer->toString()->sameAs("bcd")) {
          TEST_FAIL("StringBuffer crop test7");
      }
      
      buffer->crop(1,1);
      if(!buffer->toString()->sameAs("c")) {
          TEST_FAIL("StringBuffer crop test8");
      }
      break;
    }

    TEST_OK("StringBuffer crop test100");
}
