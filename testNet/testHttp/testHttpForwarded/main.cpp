#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testForwardedParse();
extern void testForwardedToString();
extern void testSetToHeader();

int main() {
    testForwardedParse();
    testForwardedToString();
    testSetToHeader();
    return 0;
}
