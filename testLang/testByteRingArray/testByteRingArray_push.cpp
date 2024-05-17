#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;


ByteRingArray createStartBiggerThanEnd() {
  //{7,  8,  3,  4,  5,  6}
  //         |end    |start
  ByteRingArray ringarray = ByteRingArray::New(6);
  ringarray->push(1);
  ringarray->push(2);
  ringarray->push(3);
  ringarray->push(4);
  ringarray->push(5);
  ringarray->push(6);

  ringarray->pop(1);
  ringarray->pop(1);


  ringarray->push(7);
  ringarray->push(8);

  ringarray->pop(1);
  ringarray->pop(1);

  return ringarray;
}

void push_test() {
  ByteRingArray array = createStartBiggerThanEnd();
  //pop 2 data
  ByteArray b1 = array->pop(2);
  if(b1->at(0) != 5 ||
     b1->at(1) != 6) {
    TEST_FAIL("[ByteRingArray Test push_test {push_test} case1]");
    return;
  }

  if(array->getStartIndex() != 0
    ||array->getEndIndex() != 2) {
    TEST_FAIL("[ByteRingArray Test push_test {push_test} case2]");
    return;
  }

  int v2 = array->pop();
  if(v2 != 7) {
    TEST_FAIL("[ByteRingArray Test push_test {push_test} case3]");
    return;
  }

  b1 = ByteArray::New(5);
  b1[0] = 19;
  b1[1] = 19;
  b1[2] = 19;
  b1[3] = 19;
  b1[4] = 19;
  array->push(b1);

  if(array->at(0) != 19 ||
     array->at(1) != 8  ||
     array->at(2) != 19 ||
     array->at(3) != 19 ||
     array->at(4) != 19 ||
     array->at(5) != 19 ) {
    TEST_FAIL("[ByteRingArray Test push_test {push_test} case4]");
    return;
  }


  TEST_OK("[ByteRingArray Test push_test {push_test} case10]");
}
