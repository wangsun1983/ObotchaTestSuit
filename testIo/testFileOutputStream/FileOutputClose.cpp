#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "File.hpp"
#include "TestLog.hpp"
#include "FileDescriptor.hpp"

using namespace obotcha;

void fileoutput_close_test() {

    while(1) {
        File file = createFile("./tmp/output_close_test.txt");
        file->createNewFile();

        FileDescriptor fd = createFileDescriptor(open("./tmp/output_close_test.txt",O_WRONLY));
        {
          FileOutputStream stream = createFileOutputStream(fd);
        }

        byte buf[2] = {0x1,0x2};
        int len = write(fd->getFd(),buf,2);
        if(len != 2) {
          TEST_FAIL("[TestFileOutputStream Test close case1] [FAILED] ,len is %d\n",len);
          break;
        }

        close(fd->getFd());
        break;
    }

    while(1) {
        File file = createFile("./tmp/output_close_test.txt");
        file->createNewFile();

        FileDescriptor fd = createFileDescriptor(open("./tmp/output_close_test.txt",O_RDONLY));
        FileOutputStream stream = createFileOutputStream(fd);
        stream->close();

        byte buf[2] = {0x1,0x2};
        int len = write(fd->getFd(),buf,2);
        if(len != -1) {
          TEST_FAIL("[TestFileOutputStream Test close case2]");
          break;
        }

        close(fd->getFd());
        break;
    }

    TEST_OK("[TestFileOutputStream Test close case3]");
}
