#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Float.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"

using namespace obotcha;

extern void testAppend();
extern void testPerformance();
extern void testToString();
extern void testSubString();
extern void testReset();

int main() {
    testAppend();
    testToString();
    testSubString();
    testReset();
    //testPerformance();
    return 0;
}
