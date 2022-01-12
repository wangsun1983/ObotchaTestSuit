#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileGetName() {
    File file;
    String name;

    //test1
    file = createFile("Obotcha/test/testFile/abc.cpp");
    name = file->getName();
    if(name == nullptr || !name->equals("abc.cpp")) {
      TEST_FAIL("[File Test {getName()} case1]");
    }

    //test2
    file = createFile("Obotcha/test/testFile/abcdir/");
    name = file->getName();
    if(name == nullptr || !name->equals("abcdir")) {
      TEST_FAIL("[File Test {getName()} case2]");
    }
    //test3
    file = createFile("abc11.cpp");
    name = file->getName();
    if(name == nullptr || !name->equals("abc11.cpp")) {
      TEST_FAIL("[File Test {getName()} case3]");
    }

    TEST_OK("[File Test {getName()} case100]");

}
