#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileNotFoundException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileInputStreamReadTo() {
  while(1) {
    File f = File::New("./tmp/data.txt");

    FileInputStream stream = FileInputStream::New(f);
    stream->open();

    File f2 = File::New("./tmp/read_to_case1.txt");
    f2->removeAll();

    int fd = open("./tmp/read_to_case1.txt",O_CREAT|O_WRONLY|O_APPEND,0666);
    ByteArray buff = ByteArray::New(32*1024);
    while(1) {
        int length = stream->read(buff);
        if(length == 0) {
          break;
        }
        write(fd,buff->toValue(),length);
    }

    close(fd);

    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/data.txt"));
    String v2 = md5->encodeFile(File::New("./tmp/read_to_case1.txt"));
    if(v1 != v2) {
      TEST_FAIL("testFileInputStreamReadTo test1 ");
      break;
    }
    break;
  }
  TEST_OK("testFileInputStreamReadTo test100");
}
