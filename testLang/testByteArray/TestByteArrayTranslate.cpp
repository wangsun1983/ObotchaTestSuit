#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

struct DataStruct1 {
int v1;
int v2;
};

void testByteArrayTranslate() {

  while(1) {
      DataStruct1 data = {.v1 = 1,.v2 = 100};
      auto arr = st(ByteArray)::Translate(&data);
      if(arr->size() != sizeof(DataStruct1)) {
          TEST_FAIL("ByteArray testTranslate case1");
      }
      
      DataStruct1 *q = st(ByteArray)::Translate<DataStruct1>(arr);
      if(q->v1 != 1) {
          TEST_FAIL("ByteArray testTranslate case2");
      }
      
      if(q->v2 != 100) {
          TEST_FAIL("ByteArray testTranslate case3");
      }
      
      free(q);
      break;
  }

  TEST_OK("ByteArray testTranslate case100");
  return;
}
