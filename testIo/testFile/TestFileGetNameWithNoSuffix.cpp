#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileGetNameWithNoSuffix() {
    File file;

    //test1
    file = createFile("abc.cpp");
    String name = file->getNameWithNoSuffix();
    if(!name->equals("abc")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case1]");
    }

    //test2
    file = createFile("abc.cpp.ca");
    name = file->getNameWithNoSuffix();
    if(!name->equals("abc.cpp")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case2]");
    }

    //test3
    file = createFile(".");
    name = file->getNameWithNoSuffix();
    if(!name->equals(".")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case3]");
    }

    //test4
    file = createFile("1.3");
    name = file->getNameWithNoSuffix();
    if(!name->equals("1")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case4]");
    }

    //test5
    file = createFile("abc/tt");
    name = file->getNameWithNoSuffix();
    if(!name->equals("tt")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case5]");
    }

    //test6
    file = createFile("/abc/tt.zip");
    name = file->getNameWithNoSuffix();
    if(!name->equals("tt")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case6]");
    }

    TEST_OK("[File Test {getNameWithNoSuffix()} case100]");
}
