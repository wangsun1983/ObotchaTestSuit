#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"

using namespace obotcha;

extern void testToString();
extern void testToJson();
extern void testToXml();

int main() {
    testToString();
    testToJson();
    testToXml();
    return 0;
}
