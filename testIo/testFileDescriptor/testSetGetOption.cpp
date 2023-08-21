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
    if((option & st(IO)::FileControlFlags::ReadWrite) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case1],option is %x",option);
    }
    
    fd->addOption(st(IO)::FileControlFlags::NonBlock);
    option = fd->getOption();
    if((option & st(IO)::FileControlFlags::ReadWrite) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case2]");
    }
    
    if((option & st(IO)::FileControlFlags::NonBlock) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case3]");
    }
    
    fd->removeOption(st(IO)::FileControlFlags::NonBlock);
    option = fd->getOption();
    if((option & st(IO)::FileControlFlags::NonBlock) == st(IO)::FileControlFlags::NonBlock) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case4],option is %x",option);
    }
    
    fd->setOption(st(IO)::FileControlFlags::NonBlock);
    option = fd->getOption();
    if((option & st(IO)::FileControlFlags::NonBlock) == 0) {
        TEST_FAIL("[FileDescriptor Set/Get/Remove/Option Test case5]option is %x",option);
    }
    
    TEST_OK("[FileDescriptor Set/Get/Remove/Option Test case100]");
}
