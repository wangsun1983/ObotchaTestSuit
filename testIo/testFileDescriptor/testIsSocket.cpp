#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <memory.h>
#include <netinet/in.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "FileDescriptor.hpp"
#include "TestLog.hpp"
#include "File.hpp"

using namespace obotcha;

void testIsSocket() {
    while(1) {
        int sock = socket(PF_INET,SOCK_STREAM, 0);
        FileDescriptor fd = createFileDescriptor(sock);
        if(!fd->isSocket()) {
            TEST_FAIL("[FileDescriptor isSocket Test case1]");
        }
        
        fd->close();
        if(fd->isSocket()) {
            TEST_FAIL("[FileDescriptor isSocket Test case2]");
        }
        break;
    }
    
    while(1) {
        int fd = open("./tmp/base_data",O_RDONLY);
        FileDescriptor descripor = createFileDescriptor(fd);
        if(descripor->isSocket()) {
            TEST_FAIL("[FileDescriptor isSocket Test case3]");
        }
        
        descripor->close();
        if(descripor->isSocket()) {
            TEST_FAIL("[FileDescriptor isSocket Test case4]");
        }
        break;
    }
    TEST_OK("[FileDescriptor isSocket Test case100]");
}
