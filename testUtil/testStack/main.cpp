#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"

extern void testStackSize();
extern void testStackPush();
extern void testTop();

using namespace obotcha;

int main() {
    testTop();
    testStackPush();
    testStackSize();
    return 0;
}
