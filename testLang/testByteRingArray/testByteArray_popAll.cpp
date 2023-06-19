#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testPopAll() {

  //case1
  //data:[1(start),2,3,4,5(end)]
  while(1) {
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    array->push(2);
    array->push(3);
    array->push(4);
    array->push(5);

    ByteRingArray arr1 = createByteRingArray(array);
    arr1->setEndIndex(0);
    arr1->setSize(5);

    ByteArray result = arr1->popAll();
    if(result->size() != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case1]");
      break;
    }

    if(result[0] != 1 || result[1] != 2 || result[2] != 3 || result[3] != 4 || result[4] != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case2]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(0);
    arr1->setSize(4);

    result = arr1->popAll();
    if(result->size() != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case2]");
      break;
    }

    if(result[0] != 2 || result[1] != 3 || result[2] != 4 || result[3] != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case3]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(0);
    arr1->setSize(3);

    result = arr1->popAll();
    if(result->size() != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case4]");
      break;
    }

    if(result[0] != 3 || result[1] != 4 || result[2] != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case5]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(0);
    arr1->setSize(2);

    result = arr1->popAll();
    if(result->size() != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case6]");
      break;
    }

    if(result[0] != 4 || result[1] != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case7]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(0);
    arr1->setSize(1);

    result = arr1->popAll();
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case8]");
      break;
    }

    if(result[0] != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case9]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(1);
    arr1->setSize(5);

    result = arr1->popAll();
    if(result->size() != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case10]");
      break;
    }

    if(result[0] != 2 || result[1] != 3 || result[2] != 4 || result[3] != 5 || result[4] != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case11]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(1);
    arr1->setSize(4);

    result = arr1->popAll();
    if(result->size() != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case12]");
      break;
    }

    if(result[0] != 3 || result[1] != 4 || result[2] != 5 || result[3] != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case13]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(1);
    arr1->setSize(3);

    result = arr1->popAll();
    if(result->size() != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case14]");
      break;
    }

    if(result[0] != 4 || result[1] != 5 || result[2] != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case15]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(1);
    arr1->setSize(2);

    result = arr1->popAll();
    if(result->size() != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case16]");
      break;
    }

    if(result[0] != 5 || result[1] != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case17]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(1);
    arr1->setSize(1);

    result = arr1->popAll();
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case18]");
      break;
    }

    if(result[0] != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case19]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(5);

    result = arr1->popAll();
    if(result->size() != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case20]");
      break;
    }

    if(result[0] != 3 || result[1] != 4 || result[2] != 5 || result[3] != 1 || result[4] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case21]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(4);

    result = arr1->popAll();
    if(result->size() != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case20]");
      break;
    }

    if(result[0] != 4 || result[1] != 5 || result[2] != 1 || result[3] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case21]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(3);

    result = arr1->popAll();
    if(result->size() != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case21]");
      break;
    }

    if(result[0] != 5 || result[1] != 1 || result[2] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case22]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(2);

    result = arr1->popAll();
    if(result->size() != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case23]");
      break;
    }

    if(result[0] != 1 || result[1] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case24]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(1);

    result = arr1->popAll();
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case25]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case26]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(5);

    result = arr1->popAll();
    if(result->size() != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case27]");
      break;
    }

    if(result[0] != 3 || result[1] != 4 || result[2] != 5 || result[3] != 1 || result[4] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case28]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(4);

    result = arr1->popAll();
    if(result->size() != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case29]");
      break;
    }

    if(result[0] != 4 || result[1] != 5 || result[2] != 1 || result[3] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case30]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(3);

    result = arr1->popAll();
    if(result->size() != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case31]");
      break;
    }

    if(result[0] != 5 || result[1] != 1 || result[2] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case32]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(2);

    result = arr1->popAll();
    if(result->size() != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case32]");
      break;
    }

    if(result[0] != 1 || result[1] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case33]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(2);
    arr1->setSize(1);

    result = arr1->popAll();
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case34]");
      break;
    }

    if(result[0] != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case35]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(3);
    arr1->setSize(5);

    result = arr1->popAll();
    if(result->size() != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case36]");
      break;
    }

    if(result[0] != 4 || result[1] != 5 || result[2] != 1 || result[3] != 2 || result[4] != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case37]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(3);
    arr1->setSize(4);

    result = arr1->popAll();
    if(result->size() != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case38]");
      break;
    }

    if(result[0] != 5|| result[1] != 1 || result[2] != 2 || result[3] != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case39]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(3);
    arr1->setSize(3);

    result = arr1->popAll();
    if(result->size() != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case38]");
      break;
    }

    if(result[0] != 1|| result[1] != 2 || result[2] != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case39]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(3);
    arr1->setSize(2);

    result = arr1->popAll();
    if(result->size() != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case40]");
      break;
    }

    if(result[0] != 2|| result[1] != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case41]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(3);
    arr1->setSize(1);

    result = arr1->popAll();
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case42]");
      break;
    }

    if(result[0] != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case43]");
      break;
    }

    //
    arr1 = createByteRingArray(array);
    arr1->setEndIndex(4);
    arr1->setSize(5);

    result = arr1->popAll();
    if(result->size() != 5) {
      TEST_FAIL("[ByteRingArray Test PopAll case44]");
      break;
    }

    if(result[0] != 5 || result[1] != 1 || result[2] != 2 || result[3] != 3 || result[4] != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case45]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(4);
    arr1->setSize(4);

    result = arr1->popAll();
    if(result->size() != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case46]");
      break;
    }

    if(result[0] != 1 || result[1] != 2 || result[2] != 3 || result[3] != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case47]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(4);
    arr1->setSize(3);

    result = arr1->popAll();
    if(result->size() != 3) {
      TEST_FAIL("[ByteRingArray Test PopAll case48]");
      break;
    }

    if(result[0] != 2 || result[1] != 3 || result[2] != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case49]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(4);
    arr1->setSize(2);

    result = arr1->popAll();
    if(result->size() != 2) {
      TEST_FAIL("[ByteRingArray Test PopAll case50]");
      break;
    }

    if(result[0] != 3 || result[1] != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case51]");
      break;
    }

    arr1 = createByteRingArray(array);
    arr1->setEndIndex(4);
    arr1->setSize(1);

    result = arr1->popAll();
    if(result->size() != 1) {
      TEST_FAIL("[ByteRingArray Test PopAll case52]");
      break;
    }

    if(result[0] != 4) {
      TEST_FAIL("[ByteRingArray Test PopAll case53]");
      break;
    }

    TEST_OK("[ByteRingArray Test PopAll case99]");
    break;
  }

  return;
}
