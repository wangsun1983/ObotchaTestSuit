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
#include "Runnable.hpp"
#include "Condition.hpp"
#include "Mutex.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
    TEST_FAIL("hello!!! %d",123);
    TEST_FAIL("hello");
}