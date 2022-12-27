#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "FileInputStream.hpp"

using namespace obotcha;

void testFileIsDirectory() {
    File f = createFile("./tmp/a/b/c");
    f->createDirs();
    
    if(!f->isDirectory()) {
        TEST_FAIL("[File Test {isDirectory()} case1]");
    }
    
    File f2 = createFile("./makefile");
    if(f2->isDirectory()) {
        TEST_FAIL("[File Test {isDirectory()} case2]");
    }
    
    File f3 = createFile("./tmp/testIsDirectory");
    if(f3->isDirectory()) {
        TEST_FAIL("[File Test {isDirectory()} case3]");
    }
    TEST_OK("[File Test {isDirectory()} case100]");

}
