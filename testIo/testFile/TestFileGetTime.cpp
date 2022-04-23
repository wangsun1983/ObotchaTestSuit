#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testFileGetTime() {
    File f = createFile("./tmp/time.txt");
    if(f->exists()) {
        f->removeAll();
    }
    f->createNewFile();
    long time = st(System)::currentTimeMillis();

    if((time - f->lastModified()) > 10) {
        TEST_FAIL("[File Test {getTime()} case1]");
    }

    if((time - f->lastAccess()) > 10) {
        TEST_FAIL("[File Test {getTime()} case2]");
    }

    if((time - f->lastStatusChanged()) > 10) {
        TEST_FAIL("[File Test {getTime()} case3]");
    }

    TEST_OK("[File Test {getTime()} case100]");
}
