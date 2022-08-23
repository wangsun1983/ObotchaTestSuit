#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"

using namespace obotcha;

extern void testtostring();
extern void basetest();
extern void equaltest();
extern void hashcodeTest();
extern void testLongParse();
extern void testLongParseWrong();
extern void testLongWithCRLF();

int main() {
    basetest();
    equaltest();
    testtostring();
    hashcodeTest();
    testLongParse();
    testLongParseWrong();
    testLongWithCRLF();
    return 0;
}
