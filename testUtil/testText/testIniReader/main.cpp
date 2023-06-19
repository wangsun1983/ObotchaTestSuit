#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"

using namespace obotcha;

extern void testIniReader();
extern void testIniValue();
extern void testIniReaderLoadContent();

int main() {
    testIniReaderLoadContent();    
    testIniReader();
    testIniValue();
    return 0;
}
