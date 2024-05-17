#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
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

void test_pop() {
    //{1,2,3,4,5,6}
    ByteRingArray ringarray = ByteRingArray::New(6);
    ByteArray array = ByteArray::New(6);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;

    ringarray->push(array);
    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);

    byte v = 0;
    reader->readNext(v);
    reader->readNext(v);

    ByteArray poparray = reader->pop();

    if(poparray->size() != 2 ||
       poparray->at(0) != 1 ||
       poparray->at(1) != 2 ) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case0],size is %d,array[0] is %d,array[1] is %d",
          poparray->size(),poparray->at(0),poparray->at(1));
        return;
    }

    reader->readNext(v);
    reader->readNext(v);
    poparray = reader->pop();
    if(poparray->size() != 2 ||
       poparray->at(0) != 3 ||
       poparray->at(1) != 4 ) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case1]");
        return;
    }

    reader->readNext(v);

    poparray = reader->pop();
    if(poparray->size() != 1 ||
       poparray->at(0) != 5 ) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case2]");
        return;
    }

    poparray = reader->pop();
    if(poparray != nullptr) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case3],poparray size is %d",poparray->size());
        poparray->dump("--pop(byte)--");
        return;
    }

    //{7,2,3,4,5,6}
    ringarray = ByteRingArray::New(6);
    array = ByteArray::New(5);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    ringarray->push(array);
    ringarray->pop(1);

    ByteArray array2 = ByteArray::New(2);
    array2[0] = 6;
    array2[1] = 7;
    ringarray->push(array2);
    auto status = st(IO)::Reader::Result::HasContent;
    reader = ByteRingArrayReader::New(ringarray);
    byte ind = 2;
    while(1) {
        byte value = 0;
        status = reader->readNext(value);
        if(status == st(IO)::Reader::Result::NoContent) {
          break;
        }

        if(value != ind) {
            TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case3_1],value is %d,ind is %d",value,ind);
            break;
        }
        ind++;
    }

    poparray = reader->pop();
    if(poparray->at(0) != 2 ||
       poparray->at(1) != 3 ||
       poparray->at(2) != 4 ||
       poparray->at(3) != 5 ||
       poparray->at(4) != 6 ||
       poparray->at(5) != 7 ) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case4]");
        return;
    }

    //{7,  8,  3,  4,  5,  6}
    //         |end    |start
    ringarray = createStartBiggerThanEnd();
    reader = ByteRingArrayReader::New(ringarray);
    status = st(IO)::Reader::Result::HasContent;

    while(status != st(IO)::Reader::Result::NoContent) {
        byte value = 0;
        status = reader->readNext(value);
        ind++;
    }

    poparray = reader->pop();
    if(poparray->size() != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case6]");
        return;
    }
    if(poparray->at(0) != 5 ||
       poparray->at(1) != 6 ||
       poparray->at(2) != 7 ||
       poparray->at(3) != 8 ) {
        TEST_FAIL("[ByteRingArrayReader Test {pop(byte val)} case7]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {pop(byte val)} case10]");
}
