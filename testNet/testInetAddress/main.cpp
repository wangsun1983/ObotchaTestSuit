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


int main() {
    testToString();
    testHashCode();
    testSockAddress();
    testGetFamily();
    return 0;
}
