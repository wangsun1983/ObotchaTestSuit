#include "StringBuffer.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testPerformance() {
    TimeWatcher t = createTimeWatcher();
    t->start();
    for(int i = 0;i < 1024*1024;i++) {
      StringBuffer buffer = createStringBuffer(256);
      buffer->append("abc");
      buffer->append("abc2");
      buffer->append("abc3");
      if(!buffer->toString()->equals("abcabc2abc3")) {
        printf("StringBuffer append test1-------[FAILED] \n");
      }
    }
    auto v = t->stop();
    printf("string buff cost:%ld ms \n",v);

    t->start();
    for(int i = 0;i < 1024*1024;i++) {
      String buffer = createString("");
      buffer = buffer->append("abc");
      buffer = buffer->append("abc2");
      buffer = buffer->append("abc3");
      if(!buffer->equals("abcabc2abc3")) {
        printf("StringBuffer append test2-------[FAILED] \n");
      }
    }
    auto v2 = t->stop();
    printf("string cost:%ld ms \n",v2);

    printf("StringBuffer append test100-------[OK] \n");
}
