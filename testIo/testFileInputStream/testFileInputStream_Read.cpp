#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileNotFoundException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"


using namespace obotcha;

void testFileInputStreamRead() {

  while(1) {
    File f = File::New("./tmp/data.txt");

    FileInputStream stream = FileInputStream::New(f);
    stream->open();

    File f2 = File::New("./tmp/test_read.txt");
    f2->removeAll();

    int fd = open("./tmp/test_read.txt",O_CREAT|O_WRONLY|O_APPEND,0666);
    while(1) {
        ByteArray data = stream->read(32*1024);
        if(data == nullptr) {
          break;
        }
        write(fd,data->toValue(),data->size());
    }

    close(fd);

    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/data.txt"));
    String v2 = md5->encodeFile(File::New("./tmp/test_read.txt"));
    if(v1 != v2) {
      TEST_FAIL("testFileInputStreamRead test1 ");
      break;
    }
    break;
  }
  
  while(1) {
    File f = File::New("./tmp/data.txt");

    FileInputStream stream = FileInputStream::New(f);
    stream->open();

    File f2 = File::New("./tmp/test_read_by_bytearray.txt");
    f2->removeAll();

    int fd = open("./tmp/test_read_by_bytearray.txt",O_CREAT|O_WRONLY|O_APPEND,0666);
    ByteArray data = ByteArray::New(32*1024);

    while(1) {
        long len = stream->read(data);
        if(len == 0) {
          break;
        }
        write(fd,data->toValue(),len);
    }

    close(fd);

    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/data.txt"));
    String v2 = md5->encodeFile(File::New("./tmp/test_read_by_bytearray.txt"));
    if(v1 != v2) {
      TEST_FAIL("testFileInputStreamRead test2 ");
      break;
    }
    break;
  }
  
  while(1) {
    File f = File::New("./tmp/data.txt");

    FileInputStream stream = FileInputStream::New(f);
    stream->open();

    File f2 = File::New("./tmp/test_read_by_bytearray2.txt");
    f2->removeAll();

    int fd = open("./tmp/test_read_by_bytearray2.txt",O_CREAT|O_WRONLY|O_APPEND,0666);
    ByteArray data = ByteArray::New(32*1024);

    while(1) {
        long len = stream->read(data,1024);
        if(len == 0) {
          break;
        }
        write(fd,data->toValue()+1024,len);
    }

    close(fd);

    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/data.txt"));
    String v2 = md5->encodeFile(File::New("./tmp/test_read_by_bytearray2.txt"));
    if(v1 != v2) {
      TEST_FAIL("testFileInputStreamRead test3 ");
      break;
    }
    break;
  }

  TEST_OK("testFileInputStreamRead test100");
}
