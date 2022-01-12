#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileSetRwx() {
    File file = createFile("setpropfle.data");
    //test1
    int value = file->setReadOnly();

    if(file->canWrite()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case1]");
    }

    if(file->canExecute()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case2]");
    }

    if(!file->canRead()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case3]");
    }

    //test2
    file->setWriteOnly();
    if(!file->canWrite()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case4]");
    }

    if(file->canExecute()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case5]");
    }

    if(file->canRead()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case6]");
    }

    //test3
    file->setExecuteOnly();
    if(file->canWrite()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case7]");
    }

    if(!file->canExecute()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case8]");
    }

    if(file->canRead()) {
        TEST_FAIL("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case9]");
    }

    TEST_OK("[File Test {setReadOnly/setWriteOnle/SetExecuteOnly()} case10]");

}
