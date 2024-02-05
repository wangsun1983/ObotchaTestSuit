#include <stdio.h>
#include <unistd.h>

extern void testClose();
extern void testStartWatch();
extern void testStopWatch();
extern void testWriteFile();
extern void testCloseNoWrite();
extern void testWriteFileLambda();

int main() {
    testWriteFileLambda();
    testCloseNoWrite();  
    testWriteFile();
    testStartWatch();
    testClose();
    testStopWatch();

    return 0;
}
