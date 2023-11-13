#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testFileMode() {
    File file = createFile("./tmp/mode.data");
    if(!file->exists()) {
        file->createNewFile();
    }
    
    file->setExecuteOnly();
    auto mode = file->getMode();
    if((mode & S_IXOTH) == 0 ||
        (mode & S_IXUSR) == 0 ||
        (mode & S_IXGRP) == 0) {
        TEST_FAIL("[File Test {setMode/getMode} case1]");    
    }
    
    if((mode & S_IRUSR) != 0 ||
        (mode & S_IRGRP) != 0 ||
        (mode & S_IROTH) != 0) {
        TEST_FAIL("[File Test {setMode/getMode} case2]");    
    }
    
    if((mode & S_IWUSR) != 0 ||
        (mode & S_IWGRP) != 0 ||
        (mode & S_IWOTH) != 0) {
        TEST_FAIL("[File Test {setMode/getMode} case3]");    
    }
    
    file->setReadOnly();
    mode = file->getMode();
    if((mode & S_IXOTH) != 0 ||
        (mode & S_IXUSR) != 0 ||
        (mode & S_IXGRP) != 0) {
        TEST_FAIL("[File Test {setMode/getMode} case4]");    
    }
    
    if((mode & S_IRUSR) == 0 ||
        (mode & S_IRGRP) == 0 ||
        (mode & S_IROTH) == 0) {
        TEST_FAIL("[File Test {setMode/getMode} case5]");    
    }
    
    if((mode & S_IWUSR) != 0 ||
        (mode & S_IWGRP) != 0 ||
        (mode & S_IWOTH) != 0) {
        TEST_FAIL("[File Test {setMode/getMode} case6]");    
    }
    
    file->setWriteOnly();
    mode = file->getMode();
    if((mode & S_IXOTH) != 0 ||
        (mode & S_IXUSR) != 0 ||
        (mode & S_IXGRP) != 0) {
        TEST_FAIL("[File Test {setMode/getMode} case7]");    
    }
    
    if((mode & S_IRUSR) != 0 ||
        (mode & S_IRGRP) != 0 ||
        (mode & S_IROTH) != 0) {
        TEST_FAIL("[File Test {setMode/getMode} case8]");    
    }
    
    if((mode & S_IWUSR) == 0 ||
        (mode & S_IWGRP) == 0 ||
        (mode & S_IWOTH) == 0) {
        TEST_FAIL("[File Test {setMode/getMode} case9]");    
    }
    
    TEST_OK("[File Test {setMode/getMode} case10]");

}
