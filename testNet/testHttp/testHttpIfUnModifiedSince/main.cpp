#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testPatchParse();
extern void testPatchToString();
extern void testSetToHeader();

int main() {
    testSetToHeader();
    testPatchParse();
    testPatchToString();
    return 0;
}
