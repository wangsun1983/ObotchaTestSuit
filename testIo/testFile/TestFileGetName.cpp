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
      TEST_FAIL("[File Test {getName()} case1],name is %s",name->toChars());
    }

    //test2
    file = createFile("Obotcha/test/testFile/abcdir/");
    name = file->getName();
    if(name == nullptr || !name->equals("abcdir")) {
      TEST_FAIL("[File Test {getName()} case2],name is %s",name->toChars());
    }
    //test3
    file = createFile("abc11.cpp");
    name = file->getName();
    if(name == nullptr || !name->equals("abc11.cpp")) {
      TEST_FAIL("[File Test {getName()} case3]");
    }

    //test4
    file = createFile("/");
    name = file->getName();
    if(name == nullptr || !name->equals("/")) {
      TEST_FAIL("[File Test {getName()} case4]");
    }

    //test5
    file = createFile("/a");
    name = file->getName();
    if(name == nullptr || !name->equals("a")) {
      TEST_FAIL("[File Test {getName()} case5]");
    }

    //test6
    file = createFile("a");
    name = file->getName();
    if(name == nullptr || !name->equals("a")) {
      TEST_FAIL("[File Test {getName()} case6]");
    }

    //test7
    file = createFile("a/c");
    name = file->getName();
    if(name == nullptr || !name->equals("c")) {
      TEST_FAIL("[File Test {getName()} case7]");
    }

    TEST_OK("[File Test {getName()} case100]");

}
