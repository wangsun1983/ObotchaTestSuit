#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testConnectionParse();
extern void testConnectionToString();
extern void testSetToHeader();

int main() {
    testSetToHeader();
    testConnectionParse();
    testConnectionToString();
    return 0;
}
