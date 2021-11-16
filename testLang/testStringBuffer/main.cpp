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

int main() {
    testAppend();
    testToString();
    testSubString();
    //testPerformance();
    return 0;
}
