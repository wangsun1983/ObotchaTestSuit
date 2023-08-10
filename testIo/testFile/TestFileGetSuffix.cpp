#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileGetSuffix() {
    File file;
    String name;

    //test1
    file = createFile("abc.cpp");
    String suffix = file->getSuffix();
    if(!suffix->sameAs("cpp")) {
       TEST_FAIL("[File Test {getSuffix()} case1]");
    }

    //test2
    file = createFile("abc.cpp.ca");
    suffix = file->getSuffix();
    if(!suffix->sameAs("ca")) {
       TEST_FAIL("[File Test {getSuffix()} case2]");
    }

    //test3
    file = createFile(".");
    suffix = file->getSuffix();
    if(suffix != nullptr) {
       TEST_FAIL("[File Test {getSuffix()} case3]");
    }

    //test4
    file = createFile("1.3");
    suffix = file->getSuffix();
    if(!suffix->sameAs("3")) {
       TEST_FAIL("[File Test {getSuffix()} case4]");
    }

    //test5
    file = createFile("abc/tt");
    suffix = file->getSuffix();
    if(suffix != nullptr) {
       TEST_FAIL("[File Test {getSuffix()} case5]");
    }

    //test6
    file = createFile("/abc/tt.zip");
    suffix = file->getSuffix();
    if(!suffix->sameAs("zip")) {
       TEST_FAIL("[File Test {getSuffix()} case6]");
    }

    TEST_OK("[File Test {getSuffix()} case100]");
}
