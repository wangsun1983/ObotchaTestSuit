#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testNoDataRead() {
    ByteRingArray ringarray = createByteRingArray(5);
    auto reader = createByteRingArrayReader(ringarray);
    reader->move(0);
    ByteArray data = reader->pop();
    if(data != nullptr) {
        TEST_FAIL("[TestByteRingArrayReader no data test1");
    }
    
    TEST_OK("[TestByteRingArrayReader no data test100");
}
