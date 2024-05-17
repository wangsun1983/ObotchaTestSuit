#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testCharSetParse();
extern void testCharSetToString();
extern void testSetToHeader();

int main() {
    testCharSetParse();
    testCharSetToString();
    testSetToHeader();
    return 0;
}
