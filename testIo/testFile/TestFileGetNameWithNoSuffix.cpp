#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileGetNameWithNoSuffix() {
    File file;

    //test1
    file = File::New("abc.cpp");
    String name = file->getNameWithNoSuffix();
    if(!name->sameAs("abc")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case1,name is %s]",name->toChars());
    }

    //test2
    file = File::New("abc.cpp.ca");
    name = file->getNameWithNoSuffix();
    if(!name->sameAs("abc.cpp")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case2]");
    }

    //test3
    file = File::New(".");
    name = file->getNameWithNoSuffix();
    if(!name->sameAs(".")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case3]");
    }

    //test4
    file = File::New("1.3");
    name = file->getNameWithNoSuffix();
    if(!name->sameAs("1")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case4]");
    }

    //test5
    file = File::New("abc/tt");
    name = file->getNameWithNoSuffix();
    if(!name->sameAs("tt")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case5],name is %s",name->toChars());
    }

    //test6
    file = File::New("/abc/tt.zip");
    name = file->getNameWithNoSuffix();
    if(!name->sameAs("tt")) {
       TEST_FAIL("[File Test {getNameWithNoSuffix()} case6]");
    }

    TEST_OK("[File Test {getNameWithNoSuffix()} case100]");
}
