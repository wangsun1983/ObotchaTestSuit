#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "Log.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testcreate() {

    try {
        ConfReader reader = createConfReader("abcd.conf");
        TEST_FAIL("[ConfReader create test} case1]");
    } catch(InitializeException e) {}

    return 0;
}
