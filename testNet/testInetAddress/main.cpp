#include <stdio.h>
#include <unistd.h>

#include "InetAddress.hpp"
#include "ArrayList.hpp"
#include "Log.hpp"

using namespace obotcha;

extern void testToString();
extern void testHashCode();
extern void testSockAddress();
extern void testGetFamily();
extern void testSetPort();

int main() {
    testToString();
    testHashCode();
    testSockAddress();
    testGetFamily();
    testSetPort();
    return 0;
}
