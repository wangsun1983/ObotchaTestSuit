#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "ConcurrentQueue.hpp"
#include "Inspect.hpp"

using namespace obotcha;

int testInspect1() {
    int value = 1;
    Inspect(value == 1,100);

    return 1;
}

int testInspect2() {
    int value = 1;
    Inspect(value != 1,100);

    return 1;
}

void testInspect3() {
    int value = 1;
    Inspect(value == 1);
    TEST_FAIL("[testInspect case3]");
}

int result = 0;
void testInspect4() {
    int value = 2;
    Inspect(value == 1);
    result = 1;
}

void testInspect() {
    if(testInspect1() != 100) {
        TEST_FAIL("[testInspect case1]");
    }

    if(testInspect2() != 1) {
        TEST_FAIL("[testInspect case2]");
    }

    testInspect3();

    testInspect4();
    if(result != 1) {
        TEST_FAIL("[testInspect case4]");
    }

    TEST_OK("[testInspect case100]");
}
