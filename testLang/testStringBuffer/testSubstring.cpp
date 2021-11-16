#include "StringBuffer.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testSubString() {
    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      buffer->subString(0,4)->append("123");
      if(!buffer->toString()->equals("abca123")) {
        printf("StringBuffer subString test1-------[FAILED] \n");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      buffer->subString(1,4)->append("123");
      if(!buffer->toString()->equals("bcab123")) {
        printf("StringBuffer subString test2-------[FAILED] \n");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer();
      buffer->append("abcd");
      buffer->subString(1,3);
      if(!buffer->toString()->equals("bcd")) {
        printf("StringBuffer subString test3-------[FAILED] \n");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(5);
      buffer->append("abcd");
      //printf("capacity is %d,size is %d \n",buffer->capacity(),buffer->size());

      buffer->subString(0,4);
      if(!buffer->toString()->equals("abcd")) {
        printf("StringBuffer subString test4-------[FAILED] \n");
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
        printf("StringBuffer subString test5-------[FAILED] \n");
      }
      break;
    }

    printf("StringBuffer subString test100-------[OK] \n");
}
