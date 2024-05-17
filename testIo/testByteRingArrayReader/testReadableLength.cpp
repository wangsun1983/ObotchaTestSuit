#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testReadableLength() {

    //case1
    //data:[1(start/end/cursor),2,3,4,5]
    while(1) {
      ByteRingArray ringarray = ByteRingArray::New(5);
      ringarray->push(1);
      ringarray->push(2);
      ringarray->push(3);
      ringarray->push(4);
      ringarray->push(5);

      ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(0);
      int length = reader->getReadableLength();
      if(length != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case1],length is %d",length);
        return;
      }
      TEST_OK("[ByteRingArrayReader Test {testReadableLength} case2]");
      break;
    }

    while(1) {
      ByteRingArray ringarray = ByteRingArray::New(5);
      ringarray->push(1);
      ringarray->push(2);
      ringarray->push(3);
      ringarray->push(4);
      ringarray->push(5);

      ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(1);
      int length = reader->getReadableLength();
      if(length != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case3],length is %d",length);
        return;
      }
      TEST_OK("[ByteRingArrayReader Test {testReadableLength} case4]");
      break;
    }

    while(1) {
      ByteRingArray ringarray = ByteRingArray::New(5);
      ringarray->push(1);
      ringarray->push(2);
      ringarray->push(3);
      ringarray->push(4);
      ringarray->push(5);

      ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(2);
      int length = reader->getReadableLength();
      if(length != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case5],length is %d",length);
        return;
      }
      TEST_OK("[ByteRingArrayReader Test {testReadableLength} case6]");
      break;
    }

    while(1) {
      ByteRingArray ringarray = ByteRingArray::New(5);
      ringarray->push(1);
      ringarray->push(2);
      ringarray->push(3);
      ringarray->push(4);
      ringarray->push(5);

      ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(3);
      int length = reader->getReadableLength();
      if(length != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case7],length is %d",length);
        return;
      }
      TEST_OK("[ByteRingArrayReader Test {testReadableLength} case8]");
      break;
    }

    while(1) {
      ByteRingArray ringarray = ByteRingArray::New(5);
      ringarray->push(1);
      ringarray->push(2);
      ringarray->push(3);
      ringarray->push(4);
      ringarray->push(5);

      ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(4);
      int length = reader->getReadableLength();
      if(length != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case9],length is %d",length);
        return;
      }
      TEST_OK("[ByteRingArrayReader Test {testReadableLength} case10]");
      break;
    }

    //
    while(1) {
      ByteRingArray ringarray = ByteRingArray::New(5);
      ringarray->push(1);
      ringarray->push(2);
      ringarray->push(3);
      ringarray->push(4);
      ringarray->push(5);

      ringarray->setEndIndex(1);
      ringarray->setSize(5);


      ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(0);
      int length = reader->getReadableLength();
      if(length != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case11],length is %d",length);
        return;
      }

      reader->setCursor(1);
      length = reader->getReadableLength();
      if(length != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case12],length is %d",length);
        return;
      }

      reader->setCursor(2);
      length = reader->getReadableLength();
      if(length != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case13],length is %d",length);
        return;
      }

      reader->setCursor(3);
      length = reader->getReadableLength();
      if(length != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case14],length is %d",length);
        return;
      }

      reader->setCursor(4);
      length = reader->getReadableLength();
      if(length != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case15],length is %d",length);
        return;
      }

      //
      ringarray->setEndIndex(2);
      ringarray->setSize(5);

      reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(0);
      length = reader->getReadableLength();
      if(length != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case16],length is %d",length);
        return;
      }

      reader->setCursor(1);
      length = reader->getReadableLength();
      if(length != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case17],length is %d",length);
        return;
      }

      reader->setCursor(2);
      length = reader->getReadableLength();
      if(length != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case18],length is %d",length);
        return;
      }

      reader->setCursor(3);
      length = reader->getReadableLength();
      if(length != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case19],length is %d",length);
        return;
      }

      reader->setCursor(4);
      length = reader->getReadableLength();
      if(length != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case20],length is %d",length);
        return;
      }


      //
      ringarray->setEndIndex(3);
      ringarray->setSize(5);

      reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(0);
      length = reader->getReadableLength();
      if(length != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case21],length is %d",length);
        return;
      }

      reader->setCursor(1);
      length = reader->getReadableLength();
      if(length != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case22],length is %d",length);
        return;
      }

      reader->setCursor(2);
      length = reader->getReadableLength();
      if(length != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case23],length is %d",length);
        return;
      }

      reader->setCursor(3);
      length = reader->getReadableLength();
      if(length != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case24],length is %d",length);
        return;
      }

      reader->setCursor(4);
      length = reader->getReadableLength();
      if(length != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case25],length is %d",length);
        return;
      }

      //
      ringarray->setEndIndex(4);
      ringarray->setSize(5);

      reader = ByteRingArrayReader::New(ringarray);
      reader->setCursor(0);
      length = reader->getReadableLength();
      if(length != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case26],length is %d",length);
        return;
      }

      reader->setCursor(1);
      length = reader->getReadableLength();
      if(length != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case27],length is %d",length);
        return;
      }

      reader->setCursor(2);
      length = reader->getReadableLength();
      if(length != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case28],length is %d",length);
        return;
      }

      reader->setCursor(3);
      length = reader->getReadableLength();
      if(length != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case29],length is %d",length);
        return;
      }

      reader->setCursor(4);
      length = reader->getReadableLength();
      if(length != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadableLength} case30],length is %d",length);
        return;
      }

      TEST_OK("[ByteRingArrayReader Test {testReadableLength} case100]");
      break;
    }
}
