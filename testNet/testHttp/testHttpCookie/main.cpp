#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testCookieParse();
extern void testSetToHeader();

int main() {
    testCookieParse();
    testSetToHeader();
    return 0;
}
