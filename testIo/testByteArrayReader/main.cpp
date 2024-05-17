#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testReadline();
extern void basetest();
extern void testByteArrayLittleEndian();
extern void testByteArrayBigEndian();
extern void testReaderArray();
extern void testReaderArrayIntToArray();
extern void testGetIndex();
extern void testGetRemainSize();
extern void testSetIndex();
extern void testIsReadable();

int main() {
    testReaderArray();
    testByteArrayLittleEndian();
    testByteArrayBigEndian();
    testReaderArrayIntToArray();
    testGetIndex();
    testGetRemainSize();
    testSetIndex();
    testIsReadable();
    return 0;
    
}
