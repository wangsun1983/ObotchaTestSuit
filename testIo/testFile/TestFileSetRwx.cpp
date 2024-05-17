#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileSetRwx() {
    File file = File::New("./tmp/setreadonly.data");
    if(!file->exists()) {
        file->createNewFile();
    }
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
    file = File::New("./tmp/setwriteonly.data");
    if(!file->exists()) {
        file->createNewFile();
    }
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
    file = File::New("./tmp/setexecuteonly.data");
    if(!file->exists()) {
        file->createNewFile();
    }
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
