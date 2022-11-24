#include <stdio.h>
#include <unistd.h>

#include "InetAddress.hpp"
#include "ArrayList.hpp"
#include "Log.hpp"

using namespace obotcha;

extern void testToString();
extern void testHashCode();

int main() {
    testToString();
    testHashCode();
    return 0;
}
