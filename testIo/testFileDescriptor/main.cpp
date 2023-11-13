#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

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
extern void testFileRdLock();
extern void testFileWrLock();
extern void testFileMonitor();

int main() {
    File f = createFile("./tmp/base_data");
    f->createNewFile();
    testFileMonitor();
    
    testFileRdLock();
    testFileWrLock();
    
    testIsClosed();
    testIsSocket();
    testSetGetOption();
    testIsAsync();
    return 0;
}
