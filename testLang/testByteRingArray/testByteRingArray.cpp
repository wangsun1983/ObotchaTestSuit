#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

#define FILL_VALUE 1


//test push(byte)
void testPush_byte() {
  //test pop and push
  ByteRingArray array = createByteRingArray(5);
  array->push(1);
  array->push(2);
  array->push(3);
  array->push(4);
  array->push(5);

  for(int index = 0;index < 5;index++) {
    if(array->at(index) != (index + 1)) {
      break;
    }
  }

  bool isException = false;
  try {
    array->push(6);
  } catch(ArrayIndexOutOfBoundsException e) {
    isException = true;
  }

  if(!isException) {
    TEST_FAIL("[ByteRingArray Test {pushByte(byte val)} case1]");
    return;
  }

  if(array->getStoredDataSize() != 5) {
    TEST_FAIL("[ByteRingArray Test {pushByte(byte val)} case2]");
    return;
  }

  TEST_OK("[ByteRingArray Test {pushByte(byte val)} case3]");
}

//test push(ByteArray)
void testPush_bytearray() {
  //push array with one data

  ByteRingArray ringarray = createByteRingArray(5);
  ByteArray array1 = createByteArray(1);
  array1[0] = 1;
  ringarray->push(array1);

  if(ringarray->at(0) != 1) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case0]");
    return;
  }

  if(ringarray->getStoredDataSize() != 1) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case1]");
    return;
  }

  //push array with two datas
  ringarray = createByteRingArray(5);
  ByteArray array2 = createByteArray(2);
  array2[0] = 1;
  array2[1] = 2;
  ringarray->push(array2);

  if(ringarray->at(0) != 1 ||
     ringarray->at(1) != 2) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case2]");
    return;
  }

  if(ringarray->getStoredDataSize() != 2) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case3]");
    return;
  }

  //push array with three datas
  ringarray = createByteRingArray(5);
  ByteArray array3 = createByteArray(3);
  array3[0] = 1;
  array3[1] = 2;
  array3[2] = 3;
  ringarray->push(array3);

  if(ringarray->at(0) != 1 ||
     ringarray->at(1) != 2 ||
     ringarray->at(2) != 3) {

    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case4]");
    return;
  }

  if(ringarray->getStoredDataSize() != 3) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case5]");
    return;
  }

  //push array with four datas
  ringarray = createByteRingArray(5);
  ByteArray array4 = createByteArray(4);
  array4[0] = 1;
  array4[1] = 2;
  array4[2] = 3;
  array4[3] = 4;
  ringarray->push(array4);

  if(ringarray->at(0) != 1 ||
     ringarray->at(1) != 2 ||
     ringarray->at(2) != 3 ||
     ringarray->at(3) != 4) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case6]");
    return;
  }

  if(ringarray->getStoredDataSize() != 4) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case7]");
    return;
  }

  //push array with five datas
  ringarray = createByteRingArray(5);
  ByteArray array5 = createByteArray(5);
  array5[0] = 1;
  array5[1] = 2;
  array5[2] = 3;
  array5[3] = 4;
  array5[4] = 5;
  ringarray->push(array5);

  if(ringarray->at(0) != 1 ||
     ringarray->at(1) != 2 ||
     ringarray->at(2) != 3 ||
     ringarray->at(3) != 4 ||
     ringarray->at(4) != 5) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case8]");
    return;
  }

  if(ringarray->getStoredDataSize() != 5) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case9]");
    return;
  }

  //push array with six datas
  ringarray = createByteRingArray(5);
  ByteArray array6 = createByteArray(6);
  array6[0] = 1;
  array6[1] = 2;
  array6[2] = 3;
  array6[3] = 4;
  array6[4] = 5;
  array6[5] = 6;
  bool isException = false;

  try {
    ringarray->push(array6);
  } catch(ArrayIndexOutOfBoundsException e) {
    isException = true;
  }

  if(!isException) {
    TEST_FAIL("[ByteRingArray Test {pushByte(ByteArray val)} case10]");
    return;
  }

  TEST_OK("[ByteRingArray Test {pushByte(ByteArray val)} case11]");
}


//test push(ByteArray) loop
void testPush_bytearray_loop_1() {

  //{x,1,2,3,x}
  ByteRingArray ringarray = createByteRingArray(5);
  for(int index = 0;index < 4;index++) {
    ringarray->push(index);
  }

  ringarray->pop(1);

  ByteArray bytearray1 = createByteArray(2);
  bytearray1[0] = 9;
  bytearray1[1] = 10;

  ringarray->push(bytearray1);

  if(ringarray->at(0) != 10 ||
     ringarray->at(1) != 1 ||
     ringarray->at(2) != 2 ||
     ringarray->at(3) != 3 ||
     ringarray->at(4) != 9) {
    TEST_FAIL("[ByteRingArray Test loop {pushByte(ByteArray val)} case0]");
    return;
  }

  //{x,1,2,x,x}
  ringarray = createByteRingArray(5);
  for(int index = 0;index < 3;index++) {
    ringarray->push(index);
  }

  ringarray->pop(1);

  ByteArray bytearray2 = createByteArray(3);
  bytearray2[0] = 9;
  bytearray2[1] = 10;
  bytearray2[2] = 11;
  ringarray->push(bytearray2);

  if(ringarray->at(0) != 11 ||
     ringarray->at(1) != 1 ||
     ringarray->at(2) != 2 ||
     ringarray->at(3) != 9 ||
     ringarray->at(4) != 10) {
    TEST_FAIL("[ByteRingArray Test loop {pushByte(ByteArray val)} case1]");
    return;
  }

  //{x,1,x,x,x}
  ringarray = createByteRingArray(5);
  for(int index = 0;index < 2;index++) {
    ringarray->push(index);
  }

  ringarray->pop(1);

  ByteArray bytearray3 = createByteArray(4);
  bytearray3[0] = 9;
  bytearray3[1] = 10;
  bytearray3[2] = 11;
  bytearray3[3] = 12;
  ringarray->push(bytearray3);

  if(ringarray->at(0) != 12 ||
     ringarray->at(1) != 1  ||
     ringarray->at(2) != 9 ||
     ringarray->at(3) != 10 ||
     ringarray->at(4) != 11) {
    TEST_FAIL("[ByteRingArray Test loop {pushByte(ByteArray val)} case2]");
    return;
  }

  TEST_OK("[ByteRingArray Test loop {pushByte(ByteArray val)} case10]");
  return;
}

//test push(ByteArray) loop
void testPush_bytearray_loop_2() {
  //{x,x,2,3,x}
  ByteRingArray ringarray = createByteRingArray(5);
  for(int index = 0;index < 4;index++) {
    ringarray->push(index);
  }

  ringarray->pop(1);
  ringarray->pop(1);

  ByteArray array1 = createByteArray(3);
  array1[0] = 10;
  array1[1] = 11;
  array1[2] = 12;

  ringarray->push(array1);

  if(ringarray->at(0) != 11 ||
     ringarray->at(1) != 12  ||
     ringarray->at(2) != 2 ||
     ringarray->at(3) != 3 ||
     ringarray->at(4) != 10) {
    TEST_FAIL("[ByteRingArray Test loop2 {pushByte(ByteArray val)} case0]");
    return;
  }

  //{x,x,2,x,x}
  ringarray = createByteRingArray(5);
  for(int index = 0;index < 3;index++) {
    ringarray->push(index);
  }
  ringarray->pop(1);
  ringarray->pop(1);

  array1 = createByteArray(4);
  array1[0] = 10;
  array1[1] = 11;
  array1[2] = 12;
  array1[3] = 13;

  ringarray->push(array1);

  if(ringarray->at(0) != 12 ||
     ringarray->at(1) != 13  ||
     ringarray->at(2) != 2 ||
     ringarray->at(3) != 10 ||
     ringarray->at(4) != 11) {
    TEST_FAIL("[ByteRingArray Test loop2 {pushByte(ByteArray val)} case1]");
    return;
  }


  TEST_OK("[ByteRingArray Test loop2 {pushByte(ByteArray val)} case10]");
  return;
}

void testPush_bytearray_continue() {

  ByteRingArray ringarray = createByteRingArray(6);
  ByteArray bytearray1 = createByteArray(2);
  bytearray1[0] = 1;
  bytearray1[1] = 2;

  ByteArray bytearray2 = createByteArray(2);
  bytearray2[0] = 1;
  bytearray2[1] = 2;

  ByteArray bytearray3 = createByteArray(2);
  bytearray3[0] = 1;
  bytearray3[1] = 2;

  ringarray->push(bytearray1);
  ringarray->push(bytearray2);
  ringarray->push(bytearray3);

  if(ringarray->at(0) != 1 ||
     ringarray->at(1) != 2 ||
     ringarray->at(2) != 1 ||
     ringarray->at(3) != 2 ||
     ringarray->at(4) != 1 ||
     ringarray->at(5) != 2 ) {

    TEST_FAIL("[ByteRingArray Test continue {push(ByteArray val)} case1]");
    return;
  }

  //{x,x,3,4,x,x,}
  ringarray = createByteRingArray(6);
  for(int index = 0;index < 4;index++) {
    ringarray->push(index + 1);
  }

  ringarray->pop(2);

  ByteArray bytearray4 = createByteArray(2);
  bytearray4[0] = 10;
  bytearray4[1] = 11;
  ringarray->push(bytearray4);

  ByteArray bytearray5 = createByteArray(2);
  bytearray5[0] = 12;
  bytearray5[1] = 13;
  ringarray->push(bytearray5);

  if(ringarray->at(0) != 12 ||
     ringarray->at(1) != 13 ||
     ringarray->at(2) != 3 ||
     ringarray->at(3) != 4 ||
     ringarray->at(4) != 10 ||
     ringarray->at(5) != 11 ) {

    TEST_FAIL("[ByteRingArray Test continue {push(ByteArray val)} case2]");
    return;
  }

  TEST_OK("[ByteRingArray Test continue {push(ByteArray val)} case10]");
  return;
}


//pop()
void test_pop() {
  ByteRingArray ringarray = createByteRingArray(6);
  ringarray->push(1);
  ringarray->push(2);
  ringarray->push(3);
  ringarray->push(4);
  ringarray->push(5);
  ringarray->push(6);

  int v1 = ringarray->pop();
  int v2 = ringarray->pop();
  int v3 = ringarray->pop();
  int v4 = ringarray->pop();
  int v5 = ringarray->pop();
  int v6 = ringarray->pop();

  if(v1 != 1 ||
     v2 != 2 ||
     v3 != 3 ||
     v4 != 4 ||
     v5 != 5 ||
     v6 != 6) {
    TEST_FAIL("[ByteRingArray Test pop {pop()} case2]");
    return;
  }

  TEST_OK("[ByteRingArray Test pop {pop()} cas10]");
  return;

}

//pop(int)
/*
void test_pop_size() {
  ByteRingArray ringarray = createByteRingArray(6);
  ringarray->push(1);
  ringarray->push(2);
  ringarray->push(3);
  ringarray->push(4);
  ringarray->push(5);
  ringarray->push(6);

  ByteArray b1 = ringarray->pop(2);
  ByteArray b2 = ringarray->pop(2);
  ByteArray b3 = ringarray->pop(2);

  if(b1->at(0) != 1 ||
     b1->at(1) != 2 ||
     b2->at(0) != 3 ||
     b2->at(1) != 4 ||
     b3->at(0) != 5 ||
     b3->at(1) != 6 ) {
    TEST_FAIL("[ByteRingArray Test pop_size {pop(int)} case1]");
    return;
  }

  ringarray = createByteRingArray(6);
  ringarray->push(1);
  ringarray->push(2);
  ringarray->push(3);
  ringarray->push(4);
  ringarray->push(5);
  ringarray->push(6);

  ringarray->pop();
  ringarray->push(7);

  b1 = ringarray->pop(2);
  b2 = ringarray->pop(2);
  b3 = ringarray->pop(2);

  if(b1->at(0) != 2 ||
     b1->at(1) != 3 ||
     b2->at(0) != 4 ||
     b2->at(1) != 5 ||
     b3->at(0) != 6 ||
     b3->at(1) != 7 ) {
    TEST_FAIL("b1[0] is %d,b1[1] is %d \n",b1[0],b1[1]);
    TEST_FAIL("b2[0] is %d,b2[1] is %d \n",b2[0],b2[1]);
    TEST_FAIL("b3[0] is %d,b3[1] is %d \n",b3[0],b3[1]);
    TEST_FAIL("[ByteRingArray Test pop_size {pop(int)} case2]");
    return;
  }

  ringarray = createByteRingArray(6);
  ringarray->push(1);
  ringarray->push(2);
  ringarray->push(3);
  ringarray->push(4);
  ringarray->push(5);
  ringarray->push(6);

  ringarray->pop();
  ringarray->pop();
  ringarray->pop();

  ringarray->push(7);
  ringarray->push(8);
  ringarray->push(9);

  b1 = ringarray->pop(6);
  if(b1->at(0) != 4 ||
     b1->at(1) != 5 ||
     b1->at(2) != 6 ||
     b1->at(3) != 7 ||
     b1->at(4) != 8 ||
     b1->at(5) != 9 ) {
    TEST_FAIL("[ByteRingArray Test pop_size {pop(int)} case3]");
    return;
  }

  ringarray->push(15);
  ringarray->push(16);
  ringarray->push(17);
  ringarray->push(18);
  if(ringarray->getStoredDataSize() != 4) {
    TEST_FAIL("[ByteRingArray Test pop_size {pop(int)} case4]");
    return;
  }

  b2 = ringarray->pop(4);

  if(b2->at(0) != 15 ||
     b2->at(1) != 16 ||
     b2->at(2) != 17 ||
     b2->at(3) != 18 ) {
    TEST_FAIL("[ByteRingArray Test pop_size {pop(int)} case5]");
    return;
  }

  TEST_FAIL("[ByteRingArray Test pop_size {pop(int)} case10] [OK] \n");
  return;
}
*/

void normal_test() {
  testPush_byte();
  testPush_bytearray();
  testPush_bytearray_loop_1();
  testPush_bytearray_loop_2();
  testPush_bytearray_continue();
  test_pop();
  //test_pop_size();
}
