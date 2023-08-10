#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testByteRingArrayPopWithParam() {

  //
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    //
    ByteRingArray arr1 = createByteRingArray(array);
    arr1->setEndIndex(0);
    arr1->setSize(5);

    ByteArray result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case1]");
      break;
    }

    if(result[0] != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case2]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case3]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test pop with param case4]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case5]");
      break;
    }

    if(result[0] != 3) {
      TEST_FAIL("[ByteRingArray Test pop with param case6]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case7]");
      break;
    }

    if(result[0] != 4) {
      TEST_FAIL("[ByteRingArray Test pop with param case8]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case9]");
      break;
    }

    if(result[0] != 5) {
      TEST_FAIL("[ByteRingArray Test pop with param case10]");
      break;
    }

    bool isException = false;
    try {
      result = arr1->pop(1);
    } catch(...){
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ByteRingArray Test pop with param case11]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(4);
    arr1->setSize(5);

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case12]");
      break;
    }

    if(result[0] != 5) {
      TEST_FAIL("[ByteRingArray Test pop with param case13]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case14]");
      break;
    }

    if(result[0] != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case15]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case16]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test pop with param case17]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case18]");
      break;
    }

    if(result[0] != 3) {
      TEST_FAIL("[ByteRingArray Test pop with param case19]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case20]");
      break;
    }

    if(result[0] != 4) {
      TEST_FAIL("[ByteRingArray Test pop with param case21]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(3);
    arr1->setSize(5);

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case22]");
      break;
    }

    if(result[0] != 4) {
      TEST_FAIL("[ByteRingArray Test pop with param case23]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case24]");
      break;
    }

    if(result[0] != 5) {
      TEST_FAIL("[ByteRingArray Test pop with param case25]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case26]");
      break;
    }

    if(result[0] != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case27]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case28]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test pop with param case29]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case30]");
      break;
    }

    if(result[0] != 3) {
      TEST_FAIL("[ByteRingArray Test pop with param case31]");
      break;
    }

    isException = false;
    try {
      result = arr1->pop(1);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ByteRingArray Test pop with param case32]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(5);

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case42]");
      break;
    }

    if(result[0] != 3) {
      TEST_FAIL("[ByteRingArray Test pop with param case43]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case44]");
      break;
    }

    if(result[0] != 4) {
      TEST_FAIL("[ByteRingArray Test pop with param case45]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case46]");
      break;
    }

    if(result[0] != 5) {
      TEST_FAIL("[ByteRingArray Test pop with param case47]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case48]");
      break;
    }

    if(result[0] != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case49]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case50]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test pop with param case51]");
      break;
    }

    isException = false;
    try {
      result = arr1->pop(1);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ByteRingArray Test pop with param case52]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(1);
    arr1->setSize(5);

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case42]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test pop with param case43]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case44]");
      break;
    }

    if(result[0] != 3) {
      TEST_FAIL("[ByteRingArray Test pop with param case45]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case46]");
      break;
    }

    if(result[0] != 4) {
      TEST_FAIL("[ByteRingArray Test pop with param case47]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case48]");
      break;
    }

    if(result[0] != 5) {
      TEST_FAIL("[ByteRingArray Test pop with param case49]");
      break;
    }

    result = arr1->pop(1);
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case50]");
      break;
    }

    if(result[0] != 1) {
      TEST_FAIL("[ByteRingArray Test pop with param case51]");
      break;
    }

    isException = false;
    try {
      result = arr1->pop(1);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ByteRingArray Test pop with param case52]");
      break;
    }

    TEST_OK("[ByteRingArray Test pop with param case100]");
    break;
  }
  return;
}
