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
extern void testHash();
extern void updatetest();
extern void TestParseException();
extern void testUint8WithCRLF();
extern void testParse();

int main() {
    testParse();
    basetest();
    equaltest();
    testtostring();
    testHash();
    updatetest();
    TestParseException();
    testUint8WithCRLF();
    return 0;
}
