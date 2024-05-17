#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"
#include "MappedFile.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testMapRead() {
    int fd = open("./tmp/abc.txt",O_CREAT | O_RDWR | O_TRUNC,S_IRUSR | S_IWUSR);
    char *txt = "hello world,this is a mapped file test";
    write(fd,txt,strlen(txt));
    close(fd);

    while(1) {
      MappedFile f = MappedFile::New("./tmp/abc.txt",256);
      auto stream = f->getInputStream();
      stream->open();
      ByteArray data = ByteArray::New(1024);
      String str = nullptr;     
      stream->read(data);

      str = data->toString();
      if(!str->sameAs(txt)) {
        TEST_FAIL("TestMappedFile read case1,str is %s \n",str->toChars());
        break;
      }

      fd = open("./tmp/abc.txt",O_CREAT | O_RDWR | O_TRUNC,S_IRUSR | S_IWUSR);
      char *tt = "write again";
      write(fd,tt,strlen(tt));

      stream->read(data);
      str = data->toString();
      //printf("dump2 str is %s \n",str->toChars());
      if(!str->sameAs(tt)) {
        TEST_FAIL("TestMappedFile read case2,str is %s \n",str->toChars());
        break;
      }

      TEST_OK("TestMappedFile read case100");
      break;
    }
}
