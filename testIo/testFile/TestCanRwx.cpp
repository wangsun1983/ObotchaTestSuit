#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCanRwx() {
    File readFile = createFile("readonly");
    File executeFile = createFile("executeonly");
    File writeFile = createFile("writeonly");

    //test read
    if(!readFile->canRead()) {
        TEST_FAIL("[File Test {CanRead()} case1]");
    }

    if(executeFile->canRead()) {
        TEST_FAIL("[File Test {CanRead()} case2]");
    }

    if(writeFile->canRead()) {
        TEST_FAIL("[File Test {CanRead()} case2]");
    }

    //testwrite
    if(readFile->canWrite()) {
        TEST_FAIL("[File Test {CanWrite()} case1]");
    }

    if(executeFile->canWrite()) {
        TEST_FAIL("[File Test {CanWrite()} case2]");
    }

    if(!writeFile->canWrite()) {
        TEST_FAIL("[File Test {CanWrite()} case2]");
    }

    //testexe
    if(readFile->canExecute()) {
        TEST_FAIL("[File Test {canExecute()} case1]");
    }

    if(!executeFile->canExecute()) {
        TEST_FAIL("[File Test {canExecute()} case2]");
    }

    if(writeFile->canExecute()) {
        TEST_FAIL("[File Test {canExecute()} case2]");
    }

    TEST_OK("[File Test {canRead/canWrite/canExecute()} case100]");

}
