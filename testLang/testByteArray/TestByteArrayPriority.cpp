#include "ByteArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPriority() {
#if 0    
  ByteArray array = createByteArray(10);
  array->setPriorityWeight(100);
  if(array->getPriorityWeight() != 100) {
    TEST_OK("ByteArray testPriority test 1");
  }
#endif
}
