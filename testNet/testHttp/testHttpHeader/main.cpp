#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testHttpHeaderToString();
extern void testHttpHeaderSet();
extern void testHttpHeaderParse();
extern void testResponseReason();

int main() {
    testHttpHeaderSet();
    testHttpHeaderToString();
    testResponseReason();
    
    //testHttpHeaderParse(); TODO
    return 0;
}
