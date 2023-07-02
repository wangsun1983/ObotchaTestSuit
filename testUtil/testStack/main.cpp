#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"

extern void testStackSize();
extern void testStackPush();
extern void testTop();
extern void testStackPop();

using namespace obotcha;

int main() {
    testStackPop();
    testTop();
    testStackPush();
    testStackSize();
    return 0;
}
