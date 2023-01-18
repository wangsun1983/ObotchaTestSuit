#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "File.hpp"

using namespace obotcha;

extern void testIsClosed();
extern void testIsSocket();
extern void testIsAsync();
extern void testSetGetOption();
int main() {
    File f = createFile("./tmp/base_data");
    f->createNewFile();
    
    testIsClosed();
    testIsSocket();
    testSetGetOption();
    testIsAsync();
    return 0;
}
