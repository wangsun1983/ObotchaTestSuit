#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "Integer.hpp"

using namespace obotcha;

extern void testtostring();
extern void basetest();
extern void equaltest();
extern void testIntegerParse();
extern void testIntegerParseWrong();
extern void testIntegerWithCRLF();

int main() {
    basetest();
    equaltest();
    testtostring();
    testIntegerParse();
    testIntegerParseWrong();
    testIntegerWithCRLF();
    return 0;
}
