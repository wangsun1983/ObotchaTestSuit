#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileGetAbsPath() {
    File file;
    String name;

    //getCurrentpath
    char buff[256];
    char *p = getcwd(buff , 256);

    //test1
    file = createFile("abc.cpp");
    name = file->getAbsolutePath();
    if(name != nullptr ) {
      TEST_FAIL("[File Test {getAbsolutePath()} case1]");
    }

    //test2
    file = createFile("makefile");
    name = file->getAbsolutePath();
    if(name == nullptr ) {
      TEST_FAIL("[File Test {getAbsolutePath()} case2]");
    }

    char buff1[512];
    snprintf(buff1,512,"%s/%s",buff,"makefile");
    if(!name->equals(buff1)) {
        TEST_FAIL("[File Test {getAbsolutePath()} case3]");
    }

    TEST_OK("[File Test {getAbsolutePath()} case100]");
}
