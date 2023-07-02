#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "Log.hpp"

using namespace obotcha;

extern int basetest();
extern void testConfIterator();
extern int testReadContent();

int main() {
    basetest();
    testConfIterator();
    testReadContent();
}
