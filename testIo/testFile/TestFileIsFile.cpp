#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testIsFile() {
    File f1 = File::New("./tmp/dir1.txt");
    f1->createDirs();
    
    if(f1->isFile()) {
        TEST_FAIL("[File Test {isFile()} case1]");
    }
    f1->removeAll();
    
    File f2 = File::New("./tmp/dir1.txt");
    f2->createNewFile();
    
    if(!f2->isFile()) {
        TEST_FAIL("[File Test {isFile()} case2]");
    }
    f2->removeAll();

    File f3 = File::New("./tmp/dir2.txt");
    if(f3->isFile()) {
        TEST_FAIL("[File Test {isFile()} case3]");
    }
    TEST_OK("[File Test {isFile()} case100]");
}
