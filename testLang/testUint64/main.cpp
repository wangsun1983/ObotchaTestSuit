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
extern void TestParseException();
extern void testHash();
extern void testUint64WithCRLF();
extern void testHashCode();

int main() {
    testHashCode();
    basetest();
    equaltest();
    testtostring();
    TestParseException();
    testUint64WithCRLF();
    return 0;
}
