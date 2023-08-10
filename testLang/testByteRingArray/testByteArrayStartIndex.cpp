#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testStartIndex() {

  //case1
  //data:[1(start),2,3,4,5(end)]
    ByteRingArray array = createByteRingArray(5);
    array->push(1);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case1]");
      return;
    }

    array->push(2);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case2]");
      return;
    }

    array->push(3);
     if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case3]");
      return;
    }

    array->push(4);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case4]");
      return;
    }

    array->push(5);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case5]");
      return;
    }

    //mIndex 0
    array->setNextIndex(0);
    array->setSize(1);
    if(array->getStartIndex() != 4) {
      TEST_FAIL("[ByteRingArray Test Start Index case6]");
      return;
    }

    array->setNextIndex(0);
    array->setSize(2);
    if(array->getStartIndex() != 3) {
      TEST_FAIL("[ByteRingArray Test Start Index case7]");
      return;
    }

    array->setNextIndex(0);
    array->setSize(3);
    if(array->getStartIndex() != 2) {
      TEST_FAIL("[ByteRingArray Test Start Index case8]");
      return;
    }

    array->setNextIndex(0);
    array->setSize(4);
    if(array->getStartIndex() != 1) {
      TEST_FAIL("[ByteRingArray Test Start Index case9]");
      return;
    }

    array->setNextIndex(0);
    array->setSize(5);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case10]");
      return;
    }

    //mIndex 1
    array->setNextIndex(1);
    array->setSize(1);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case11]");
      return;
    }

    array->setNextIndex(1);
    array->setSize(2);
    if(array->getStartIndex() != 4) {
      TEST_FAIL("[ByteRingArray Test Start Index case12]");
      return;
    }

    array->setNextIndex(1);
    array->setSize(3);
    if(array->getStartIndex() != 3) {
      TEST_FAIL("[ByteRingArray Test Start Index case13]");
      return;
    }

    array->setNextIndex(1);
    array->setSize(4);
    if(array->getStartIndex() != 2) {
      TEST_FAIL("[ByteRingArray Test Start Index case14]");
      return;
    }

    array->setNextIndex(1);
    array->setSize(5);
    if(array->getStartIndex() != 1) {
      TEST_FAIL("[ByteRingArray Test Start Index case15]");
      return;
    }

    //mIndex 2
    array->setNextIndex(2);
    array->setSize(1);
    if(array->getStartIndex() != 1) {
      TEST_FAIL("[ByteRingArray Test Start Index case16]");
      return;
    }

    array->setNextIndex(2);
    array->setSize(2);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case17]");
      return;
    }

    array->setNextIndex(2);
    array->setSize(3);
    if(array->getStartIndex() != 4) {
      TEST_FAIL("[ByteRingArray Test Start Index case18]");
      return;
    }

    array->setNextIndex(2);
    array->setSize(4);
    if(array->getStartIndex() != 3) {
      TEST_FAIL("[ByteRingArray Test Start Index case19]");
      return;
    }

    array->setNextIndex(2);
    array->setSize(5);
    if(array->getStartIndex() != 2) {
      TEST_FAIL("[ByteRingArray Test Start Index case20]");
      return;
    }

    //mIndex 3
    array->setNextIndex(3);
    array->setSize(1);
    if(array->getStartIndex() != 2) {
      TEST_FAIL("[ByteRingArray Test Start Index case21]");
      return;
    }

    array->setNextIndex(3);
    array->setSize(2);
    if(array->getStartIndex() != 1) {
      TEST_FAIL("[ByteRingArray Test Start Index case22]");
      return;
    }

    array->setNextIndex(3);
    array->setSize(3);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case23]");
      return;
    }

    array->setNextIndex(3);
    array->setSize(4);
    if(array->getStartIndex() != 4) {
      TEST_FAIL("[ByteRingArray Test Start Index case24]");
      return;
    }

    array->setNextIndex(3);
    array->setSize(5);
    if(array->getStartIndex() != 3) {
      TEST_FAIL("[ByteRingArray Test Start Index case25]");
      return;
    }

    //mIndex 4
    array->setNextIndex(4);
    array->setSize(1);
    if(array->getStartIndex() != 3) {
      TEST_FAIL("[ByteRingArray Test Start Index case26]");
      return;
    }

    array->setNextIndex(4);
    array->setSize(2);
    if(array->getStartIndex() != 2) {
      TEST_FAIL("[ByteRingArray Test Start Index case27]");
      return;
    }

    array->setNextIndex(4);
    array->setSize(3);
    if(array->getStartIndex() != 1) {
      TEST_FAIL("[ByteRingArray Test Start Index case28]");
      return;
    }

    array->setNextIndex(4);
    array->setSize(4);
    if(array->getStartIndex() != 0) {
      TEST_FAIL("[ByteRingArray Test Start Index case29]");
      return;
    }

    array->setNextIndex(4);
    array->setSize(5);
    if(array->getStartIndex() != 4) {
      TEST_FAIL("[ByteRingArray Test Start Index case30]");
      return;
    }

}
