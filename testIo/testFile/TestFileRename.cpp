#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "FileOutputStream.hpp"
#include "Md.hpp"

using namespace obotcha;

void testFileRename() {
    //test1
    Md md = createMd(st(Md)::Md5);
    
    auto file = createFile("./tmp/abc.cpp");
    file->createNewFile();
    
    FileOutputStream stream = createFileOutputStream(file);
    stream->open();
    stream->writeString("aaaabbbccc");
    stream->flush();
    stream->close();
    auto md1 = md->encodeFile(file);
    
    file->rename("tt.cpp");
    
    if(access("./tmp/tt.cpp",F_OK) != 0) {
        TEST_FAIL("[File Test {rename()} case1]");
    }
    
    if(!file->getName()->sameAs("tt.cpp")) {
        TEST_FAIL("[File Test {rename()} case2]");
    }
    
    if(access("./tmp/abc.cpp",F_OK) == 0) {
        TEST_FAIL("[File Test {rename()} case3]");
    }
    
    auto md2 = md->encodeFile(file);
    if(!md1->equals(md2)) {
        TEST_FAIL("[File Test {rename()} case4]");
    }
    
    TEST_OK("[File Test {getName()} case100]");

}
