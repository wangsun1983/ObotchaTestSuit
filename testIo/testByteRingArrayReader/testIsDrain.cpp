#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testIsDrained() {
  //case1
  //data:[1(start/end),2,3,4,5]
  while(1) {
    ByteRingArray ringarray = createByteRingArray(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    auto reader = createByteRingArrayReader(ringarray);
    if(reader->isDrained()) {
        TEST_FAIL("[ByteRingArrayReader Test isDrain case1]");
    }
    
    byte v = 0;
    reader->read(v);
    reader->read(v);
    reader->read(v);
    reader->read(v);
    reader->read(v);
    reader->pop();
    
    if(!reader->isDrained()) {
        TEST_FAIL("[ByteRingArrayReader Test isDrain case2]");
    }
    
    break;
  }

}
