#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "FileDescriptor.hpp"
#include "TestLog.hpp"
#include "File.hpp"

using namespace obotcha;

void testSetGetOption() {
    File f = createFile("./tmp/abc.txt");
    f->createNewFile();
    
    auto fd = f->open();
    int option = fd->getOption();
    if((option & st(FileDescriptor)::ReadWriteOnly) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case1],option is %x",option);
    }
    
    fd->addOption(st(FileDescriptor)::NonBlock);
    option = fd->getOption();
    if((option & st(FileDescriptor)::ReadWriteOnly) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case2]");
    }
    
    if((option & st(FileDescriptor)::NonBlock) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case3]");
    }
    
    fd->removeOption(st(FileDescriptor)::NonBlock);
    option = fd->getOption();
    if((option & st(FileDescriptor)::NonBlock) == st(FileDescriptor)::NonBlock) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case4],option is %x",option);
    }
    
    fd->setOption(st(FileDescriptor)::NonBlock);
    option = fd->getOption();
    if((option & st(FileDescriptor)::NonBlock) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case5]option is %x",option);
    }
    
    TEST_OK("[FileDescriptor Set/Get/Remove/Option Test case100]");
}
