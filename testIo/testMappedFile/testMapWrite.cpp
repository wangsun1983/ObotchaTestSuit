#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"
#include "MappedFile.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testMapWrite() {
    //int fd = open("./tmp/abc.txt",O_CREAT | O_RDWR | O_TRUNC,S_IRUSR | S_IWUSR);
    //char *txt = "hello world,this is a mapped file test";
    //write(fd,txt,strlen(txt));
    //close(fd);

    while(1) {
      File f = File::New("./tmp/write_test.txt");
      f->createNewFile();
      
      MappedFile file = MappedFile::New("./tmp/write_test.txt",256);
      auto stream = file->getOutputStream();
      stream->open();
      const char *v = "hello world,this is a mapped file test";
      ByteArray data = ByteArray::New((byte *)v,strlen(v));
      stream->write(data);
      stream->flush();

      MappedFile file2 = MappedFile::New("./tmp/write_test.txt",256);
      auto stream2 = file->getInputStream();
      ByteArray data2 = ByteArray::New(256);
      stream2->read(data2);
      
      if(!data2->toString()->equals(data->toString())) {
        TEST_FAIL("TestMappedFile write case1,data2 is %s,data is %s \n",data2->toString()->toChars(),data->toString()->toChars());
      }

      break;
    }

    TEST_OK("TestMappedFile write case100");
}
