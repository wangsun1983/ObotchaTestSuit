#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Float.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"

using namespace obotcha;

extern void basetest();
extern void equaltest();
extern void updatetest();
extern void hashcodetest();
extern void parseWrongTest();
extern void compareTest();

int main() {
    basetest();
    equaltest();
    updatetest();
    hashcodetest();
    parseWrongTest();
	compareTest();
    return 0;
}
