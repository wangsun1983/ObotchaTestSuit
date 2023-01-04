#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testHttpUrlParse();
extern void testHttpUrlWithoutPath();
extern void testHttpUrlToString();

int main() {
    testHttpUrlParse();
    testHttpUrlToString();
    testHttpUrlWithoutPath();
    return 0;
}
