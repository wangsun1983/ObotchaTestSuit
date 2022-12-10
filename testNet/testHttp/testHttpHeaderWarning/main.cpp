#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testParse();
extern void testToString();
extern void testSetToHeader();
extern void testGetSet();

int main() {
    testParse();
    testToString();
    testSetToHeader();
    testGetSet();
    return 0;
}
