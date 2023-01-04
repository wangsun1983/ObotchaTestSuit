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

int main() {
    testToString();
    testToJson();
    return 0;
}
