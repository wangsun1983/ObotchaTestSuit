#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testFileExists() {
    File f = createFile("./test_exists.tag");
    if(!f->exists()) {
        TEST_FAIL("[File Test {exists()} case1]");
    }
    
    if(!st(File)::Exists("./test_exists.tag")) {
        TEST_FAIL("[File Test {exists()} case2]");
    }
    
    File f2 = createFile("./test_exists123.tag");
    if(f2->exists()) {
        TEST_FAIL("[File Test {exists()} case3]");
    }
    
    if(st(File)::Exists("./test_exists123.tag")) {
        TEST_FAIL("[File Test {exists()} case4]");
    }

    TEST_OK("[File Test {getTime()} case100]");
}
