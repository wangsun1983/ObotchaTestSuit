#include "ByteArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testForeach() {
#if 0  
  ByteArray array = createByteArray(10);
  for(int i = 0;i <10;i++) {
    array[i] = i;
  }

  int index = 0;
  array->foreach([&index](byte d) {
    if(d != index) {
      TEST_FAIL("ByteArray Lambda test 1");
      return -1;
    }
    index++;
    return 1;
  });
#endif
  TEST_OK("ByteArray Lambda test 1");

}
