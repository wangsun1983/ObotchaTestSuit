#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCanRwx() {

    int fd1 = open("./tmp/readonly",O_RDWR|O_CREAT,0444);
    int fd2 = open("./tmp/executeonly",O_RDWR|O_CREAT,0111);
    int fd3 = open("./tmp/writeonly",O_RDWR|O_CREAT,0222);

    File readFile = createFile("./tmp/readonly");
    File executeFile = createFile("./tmp/executeonly");
    File writeFile = createFile("./tmp/writeonly");

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
