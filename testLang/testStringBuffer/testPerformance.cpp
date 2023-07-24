#include "StringBuffer.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPerformance() {
    TimeWatcher t = createTimeWatcher();
    t->start();
    for(int i = 0;i < 1024*1024;i++) {
      StringBuffer buffer = createStringBuffer(256);
      buffer->append("abc");
      buffer->append("abc2");
      buffer->append("abc3");
      if(!buffer->toString()->sameAs("abcabc2abc3")) {
        TEST_FAIL("StringBuffer append test1");
      }
    }
    auto v = t->stop();
    TEST_FAIL("string buff cost:%ld ms \n",v);

    t->start();
    for(int i = 0;i < 1024*1024;i++) {
      String buffer = createString("");
      buffer = buffer->append("abc");
      buffer = buffer->append("abc2");
      buffer = buffer->append("abc3");
      if(!buffer->sameAs("abcabc2abc3")) {
        TEST_FAIL("StringBuffer append test2");
      }
    }
    auto v2 = t->stop();
    TEST_FAIL("string cost:%ld ms \n",v2);

    TEST_OK("StringBuffer append test100");
}
