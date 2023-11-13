#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testIsFile() {
    File f1 = createFile("./tmp/dir1.txt");
    f1->createDirs();
    
    if(f1->isFile()) {
        TEST_FAIL("[File Test {isFile()} case1]");
    }
    f1->removeAll();
    
    File f2 = createFile("./tmp/dir1.txt");
    f2->createNewFile();
    
    if(!f2->isFile()) {
        TEST_FAIL("[File Test {isFile()} case2]");
    }
    f2->removeAll();

    File f3 = createFile("./tmp/dir2.txt");
    if(f3->isFile()) {
        TEST_FAIL("[File Test {isFile()} case3]");
    }
    TEST_OK("[File Test {isFile()} case100]");
}
