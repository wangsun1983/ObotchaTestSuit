#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "FileInputStream.hpp"

using namespace obotcha;

void testFileCreateDirs() {
    File f = File::New("./tmp/a/b/c");
    f->createDirs();
    
    if(access("./tmp/a/b/c",F_OK) != 0) {
        TEST_FAIL("[File Test {createDirs()} case1]");
    }
    
    DIR *p = opendir("./tmp/a/b/c");
    if(p == NULL) {
        TEST_FAIL("[File Test {createDirs()} case2]");
    }
    
    free(p);
    
    TEST_OK("[File Test {createDirs()} case100]");

}
