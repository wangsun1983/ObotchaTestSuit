#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "TestLog.hpp"
#include "ByteArrayTransformer.hpp"

using namespace obotcha;

void testByteArrayIsOverFlow() {
  ByteArray data = createByteArray(3);
  
  //start 0
  if(data->isOverflow(0,1)) {
      TEST_FAIL("ByteArray isOverflow case1");
  }
  
  if(data->isOverflow(0,2)) {
      TEST_FAIL("ByteArray isOverflow case2");
  }
  
  if(data->isOverflow(0,3)) {
      TEST_FAIL("ByteArray isOverflow case3");
  }
  
  if(!data->isOverflow(0,4)) {
      TEST_FAIL("ByteArray isOverflow case4");
  }
  
  //start 1
  if(data->isOverflow(1,1)) {
      TEST_FAIL("ByteArray isOverflow case5");
  }
  
  if(data->isOverflow(1,2)) {
      TEST_FAIL("ByteArray isOverflow case6");
  }
  
  if(!data->isOverflow(1,3)) {
      TEST_FAIL("ByteArray isOverflow case7");
  }
  
  if(!data->isOverflow(1,4)) {
      TEST_FAIL("ByteArray isOverflow case8");
  }
  
  //start 2
  if(data->isOverflow(2,1)) {
      TEST_FAIL("ByteArray isOverflow case9");
  }
  
  if(!data->isOverflow(2,2)) {
      TEST_FAIL("ByteArray isOverflow case10");
  }
  
  if(!data->isOverflow(2,3)) {
      TEST_FAIL("ByteArray isOverflow case11");
  }
  
  if(!data->isOverflow(2,4)) {
      TEST_FAIL("ByteArray isOverflow case12");
  }
  
  //start 3
  if(!data->isOverflow(3,1)) {
      TEST_FAIL("ByteArray isOverflow case13");
  }
  
  if(!data->isOverflow(3,2)) {
      TEST_FAIL("ByteArray isOverflow case14");
  }
  
  if(!data->isOverflow(3,3)) {
      TEST_FAIL("ByteArray isOverflow case15");
  }
  
  if(!data->isOverflow(3,4)) {
      TEST_FAIL("ByteArray isOverflow case16");
  }
  
  if(!data->isOverflow(3,0)) {
      TEST_FAIL("ByteArray isOverflow case17");
  }
  
  TEST_OK("ByteArray isOverflow case100");
}
