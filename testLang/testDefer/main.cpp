#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"

using namespace obotcha;

extern void testDefer();

int main() {
    testDefer();
    return 0;
}
