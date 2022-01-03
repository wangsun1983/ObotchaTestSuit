#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testByteRingArrayPop() {

  //case1
  //data:[1(start),2,3,4,5(end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    if(array->pop() != 1 || array->pop() != 2
      ||array->pop() != 3 || array->pop() != 4
      ||array->pop() != 5) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test1} case1]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test1} case2]");
    break;
  }

  //case2
  //data:[1(start),2,3,4,5(end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    ByteArray arr = array->popAll();
    if(arr->at(0) != 1 ||arr->at(1) != 2||arr->at(2) != 3||arr->at(3) != 4||arr->at(4) != 5) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test2} case1]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test2} case2]");
    break;
  }

  //case 3
  //data:[1,2(start),3,4,5(end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->pop();

    ByteArray arr = array->popAll();
    if(arr->size() != 4) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test3} case1]");
      return;
    }

    if(arr->at(0) != 2 ||arr->at(1) != 3||arr->at(2) != 4||arr->at(3) != 5) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test3} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test3} case3]");
    break;
  }

  //case 4
  //data:[1,2,3(start),4,5(end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->pop();
    array->pop();

    ByteArray arr = array->popAll();
    if(arr->size() != 3) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test4} case1]");
      return;
    }

    if(arr->at(0) != 3 ||arr->at(1) != 4||arr->at(2) != 5) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test4} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test4} case3]");
    break;
  }

  //case 5
  //data:[1,2,3,4(start),5(end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->pop();
    array->pop();
    array->pop();

    ByteArray arr = array->popAll();
    if(arr->size() != 2) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test5} case1]");
      return;
    }

    if(arr->at(0) != 4) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test5} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test5} case3]");
    break;
  }

  //case 6
  //data:[1,2,3,4,5(start/end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->pop();
    array->pop();
    array->pop();
    array->pop();
    ByteArray arr = array->popAll();
    if(arr->size() != 1) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test6} case1]");
      return;
    }

    if(arr->at(0) != 5) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test6} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test6} case3]");
    break;
  }

  //case 7
  //data:[1(end),2,3,4,5(start)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->setEndIndex(0);
    array->setSize(1);

    ByteArray arr = array->popAll();
    if(arr->size() != 1) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test7} case1]");
      return;
    }

    if(arr->at(0) != 5) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test7} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test7} case3]");
    break;
  }

  //case 8
  //data:[1,2(end),3,4,5(start)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->setSize(2);
    array->setEndIndex(1);
    ByteArray arr = array->popAll();
    if(arr->size() != 2) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test8} case1]");
      return;
    }

    if(arr->at(0) != 5 || arr->at(1) != 1) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test8} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test8} case3]");
    break;
  }

  //case 9
  //data:[1,2,3(end),4,5(start)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->setSize(3);
    array->setEndIndex(2);
    ByteArray arr = array->popAll();
    if(arr->size() != 3) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test9} case1]");
      return;
    }

    if(arr->at(0) != 5 || arr->at(1) != 1 || arr->at(2)!= 2) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test9} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test9} case3]");
    break;
  }

  //case 10
  //data:[1,2,3,4(end),5(start)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    array->setSize(4);
    array->setEndIndex(3);
    ByteArray arr = array->popAll();
    if(arr->size() != 4) {
      TEST_FAIL("---[ByteRingArray Test pop {push_test10} case1]");
      return;
    }

    if(arr->at(0) != 5 || arr->at(1) != 1 || arr->at(2)!= 2 || arr->at(3) != 3) {
        TEST_FAIL("---[ByteRingArray Test pop {push_test10} case2]");
        return;
    }

    TEST_OK("---[ByteRingArray Test pop {push_test10} case3]");
    break;
  }
  return;
}
