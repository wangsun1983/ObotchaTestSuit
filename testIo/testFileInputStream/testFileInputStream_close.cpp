#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileNotFoundException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"
#include "FileDescriptor.hpp"

using namespace obotcha;

void testFileInputStreamClose() {
  while(1) {
    auto fd = createFileDescriptor(open("./tmp/data.txt",O_RDONLY));
    {
      FileInputStream stream = createFileInputStream(fd);
      stream->open();
    }

    char data[1024];
    int len = read(fd->getFd(),data,1024);
    if(len != 1024) {
      TEST_FAIL("testFileInputStreamClose test1,len is %d ",len);
    }
    break;
  }

  while(1) {
    auto fd = createFileDescriptor(open("./tmp/data.txt",O_WRONLY));
    {
      FileInputStream stream = createFileInputStream(fd);
      stream->close();
    }

    char data[1024];
    int len = read(fd->getFd(),data,1024);
    if(len != -1) {
      TEST_FAIL("testFileInputStreamClose test1 ,len is %d",len);
    }
    break;
  }
  TEST_OK("testFileInputStreamClose test100 [OK] ");
}
