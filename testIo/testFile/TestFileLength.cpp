#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"
#include "FileOutputStream.hpp"

using namespace obotcha;

void testFileLength() {
    File f1 = createFile("./tmp/len1.txt");
    if(f1->length() != -1) {
        TEST_FAIL("[File Test {length()} case1],ret is %ld",f1->length());
    }
    
    f1->createNewFile();
    if(f1->length() != 0) {
        TEST_FAIL("[File Test {length()} case2]");
    }
    
    FileOutputStream stream = createFileOutputStream(f1);
    stream->open();
    stream->write(createString("hello")->toByteArray());
    stream->close();
    
    if(f1->length() != 5) {
        TEST_OK("[File Test {length()} case3]");
    }
    
    stream = createFileOutputStream(f1);
    stream->open(st(IO)::FileControlFlags::Append);
    
    stream->write(createString("hello")->toByteArray());
    stream->close();
    if(f1->length() != 10) {
        TEST_OK("[File Test {length()} case4]");
    }
    
    f1->removeAll();
    TEST_OK("[File Test {length()} case100]");
}
