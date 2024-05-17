#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testMove() {

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

      int cursor = reader->move(1);
      if(cursor != 1) {
        TEST_FAIL("[ByteRingArrayReader Test move case1]");
        break;
      }

      cursor = reader->move(1);
      if(cursor != 2) {
        TEST_FAIL("[ByteRingArrayReader Test move case2]");
        break;
      }

      cursor = reader->move(1);
      if(cursor != 3) {
        TEST_FAIL("[ByteRingArrayReader Test move case3]");
        break;
      }

      cursor = reader->move(1);
      if(cursor != 4) {
        TEST_FAIL("[ByteRingArrayReader Test move case4]");
        break;
      }

      cursor = reader->move(1);
      if(cursor != 0) {
        TEST_FAIL("[ByteRingArrayReader Test move case5],cursor is %d",cursor);
        break;
      }

      cursor = reader->move(1);
      if(cursor != 1) {
        TEST_FAIL("[ByteRingArrayReader Test move case6]");
        break;
      }

      TEST_OK("[ByteRingArrayReader Test move case100]");
      break;
    }
}
