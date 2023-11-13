#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"
#include "FileOutputStream.hpp"

using namespace obotcha;

void testFileGetTime() {
    File f = createFile("./tmp/time.txt");
    if(f->exists()) {
        f->removeAll();
    }
    f->createNewFile();
    long time = st(System)::CurrentTimeMillis();

    if((time - f->lastModified()) > 10) {
        TEST_FAIL("[File Test {getTime()} case1]");
    }

    if((time - f->lastAccess()) > 10) {
        TEST_FAIL("[File Test {getTime()} case2]");
    }

    if((time - f->lastStatusChanged()) > 10) {
        TEST_FAIL("[File Test {getTime()} case3]");
    }
    
    FileOutputStream stream = createFileOutputStream("./tmp/time.txt");
    stream->open();
    stream->write(createString("hello")->toByteArray());
    stream->close();
    usleep(500*1000);
    time = st(System)::CurrentTimeMillis();
    
    if((time - f->lastModified()) > 510 || (time - f->lastModified()) < 495) {
        TEST_FAIL("[File Test {getTime()} case4],time is %ld,modified is %ld \n",
            time,f->lastModified());
    }
    
    if((time - f->lastAccess()) > 510 || (time - f->lastAccess()) < 495) {
        TEST_FAIL("[File Test {getTime()} case5]");
    }
    
    if((time - f->lastStatusChanged()) > 510 || (time - f->lastStatusChanged()) < 495) {
        TEST_FAIL("[File Test {getTime()} case6]");
    }
    
    TEST_OK("[File Test {getTime()} case100]");
}
