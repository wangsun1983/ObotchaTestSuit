#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileNotFoundException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileInputStreamReadAll() {
  while(1) {
    File f = File::New("./tmp/data.txt");
    FileInputStream stream = FileInputStream::New(f);
    stream->open();

    ByteArray data = stream->readAll();

    int fd = open("./tmp/read_all_case1.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);
    write(fd,data->toValue(),data->size());
    close(fd);

    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/data.txt"));
    String v2 = md5->encodeFile(File::New("./tmp/read_all_case1.txt"));
    if(v1 != v2) {
      TEST_FAIL("testFileInputStreamReadAll test1 ");
      break;
    }
    break;
  }
  TEST_OK("testFileInputStreamReadAll test100");
}
