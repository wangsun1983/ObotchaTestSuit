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
extern void testHttpUrlSet();
extern void testHttpUrlInetAddress();

int main() {
    testHttpUrlInetAddress();
    testHttpUrlParse();
    testHttpUrlToString();
    testHttpUrlWithoutPath();
    testHttpUrlSet();
    return 0;
}
