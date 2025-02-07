#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "Log.hpp"

using namespace obotcha;

//extern int testcreate();
extern int testConfValueSet();
extern int testImport();
extern int testReflectTo();

int main() {
    ConfValue v = ConfValue::New();
    testConfValueSet();
    testImport();
    testReflectTo();
    return 0;
}
