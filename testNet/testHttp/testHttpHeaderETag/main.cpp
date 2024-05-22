#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testETagParse();
extern void testEtagSet();
extern void testEtagToString();
extern void testSetToHeader();

int main() {
    testETagParse();
    testEtagSet();
    testEtagToString();
    testSetToHeader();
    return 0;
}
