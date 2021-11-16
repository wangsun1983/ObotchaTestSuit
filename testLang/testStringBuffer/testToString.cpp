#include "StringBuffer.hpp"

using namespace obotcha;

void testToString() {
    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append("abc","abc2","abc3");
      if(!buffer->toString(0,4)->equals("abca")) {
        printf("StringBuffer toString test1-------[FAILED] \n");
      }
      break;
    }

    while(1) {
      StringBuffer buffer = createStringBuffer(1);
      buffer->append('a','b','c');
      if(!buffer->toString(0,2)->equals("ab")) {
        printf("StringBuffer toString test2-------[FAILED] \n");
      }
      break;
    }

    printf("StringBuffer toString test100-------[OK] \n");
}
