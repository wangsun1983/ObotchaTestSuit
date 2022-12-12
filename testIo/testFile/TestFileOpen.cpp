#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "FileInputStream.hpp"

using namespace obotcha;

void testFileOpen() {
    File f = createFile("./tmp/testOpen.txt");
    f->createNewFile();
    auto fd = f->open();
    if(fd == nullptr) {
        TEST_OK("[File Test {open()} case1]");
    }
    
    int _fd = fd->getFd();
    if(_fd <= 0) {
        TEST_OK("[File Test {open()} case2]");
    }
    
    char *p = "abcd";
    int ret = write(_fd,(const void *)p,4);
    if(ret != 4) {
        TEST_OK("[File Test {open()} case3]");
    }
    
    FileInputStream s = createFileInputStream(f);
    s->open();
    auto content = s->readAll();
    if(!content->toString()->equals("abcd")) {
        TEST_OK("[File Test {open()} case4]");
    }
    
    TEST_OK("[File Test {open()} case100]");

}
