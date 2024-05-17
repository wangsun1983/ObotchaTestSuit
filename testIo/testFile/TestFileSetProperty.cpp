#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testFileSetProperty() {
    File file = File::New("./tmp/property.data");
    if(!file->exists()) {
        file->createNewFile();
    }
    
    file->setReadOnly();
    String result = st(System)::ExecuteForResult(" ls ./tmp -la |grep -i property");
    if(!result->contains("-r--r--r--")) {
        TEST_FAIL("[File Test {Set Property} case1]");
    }
    if(file->canWrite()) {
        TEST_FAIL("[File Test {Set Property} case1_1]");
    }
    
    if(file->canExecute()) {
        TEST_FAIL("[File Test {Set Property} case2]");
    }

    file->setWritable();
    if(!file->canWrite()) {
        TEST_FAIL("[File Test {Set Property} case2_1]");
    }
    
    if(file->canExecute()) {
        TEST_FAIL("[File Test {Set Property} case2_2]");
    }
    
    result = st(System)::ExecuteForResult(" ls ./tmp -la |grep -i property");
    if(!result->contains("-rw-rw-rw-")) {
        TEST_FAIL("[File Test {Set Property} case2_3]");
    }
    
    file->setExecutable();
    if(!file->canWrite()) {
        TEST_FAIL("[File Test {Set Property} case2_4]");
    }
    
    if(!file->canExecute()) {
        TEST_FAIL("[File Test {Set Property} case2_5]");
    }
    
    result = st(System)::ExecuteForResult(" ls ./tmp -la |grep -i property");
    if(!result->contains("-rwxrwxrwx")) {
        TEST_FAIL("[File Test {Set Property} case2_6]");
    }
    
    file->setWriteOnly();
    result = st(System)::ExecuteForResult(" ls ./tmp -la |grep -i property");
    if(!result->contains("--w--w--w-")) {
        TEST_FAIL("[File Test {Set Property} case3_1],ret is %s",result->toChars());
    }
    
    if(file->canRead()) {
        TEST_FAIL("[File Test {Set Property} case3]");
    }
    
    if(file->canExecute()) {
        TEST_FAIL("[File Test {Set Property} case4]");
    }
    
    file->setReadable();
    if(!file->canRead()) {
        TEST_FAIL("[File Test {Set Property} case4_1]");
    }
    result = st(System)::ExecuteForResult(" ls ./tmp -la |grep -i property");
    if(!result->contains("-rw-rw-rw-")) {
        TEST_FAIL("[File Test {Set Property} case4_2],ret is %s",result->toChars());
    }
    
    file->setExecuteOnly();
    result = st(System)::ExecuteForResult(" ls ./tmp -la |grep -i property");
    if(!result->contains("---x--x--x")) {
        TEST_FAIL("[File Test {Set Property} case5_1],ret is %s",result->toChars());
    }
    
    if(file->canRead()) {
        TEST_FAIL("[File Test {Set Property} case5]");
    }
    
    if(file->canWrite()) {
        TEST_FAIL("[File Test {Set Property} case6]");
    }
    
    file->removeAll();
    TEST_OK("[File Test {Set Property} case10]");

}
