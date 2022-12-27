#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ByteArray.hpp"

using namespace obotcha;

extern int testDefaultPipe();
extern int testDirectPipe();
extern int testCloseOnExecPipe();
extern int testNoBlockPipe();
extern void testGetPipe();

int main() {
    testDefaultPipe();
    testDirectPipe();
    testCloseOnExecPipe();
    testNoBlockPipe();
    testGetPipe();

}
