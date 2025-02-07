#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"
#include "MappedFile.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testMapGetInputStream() {
    while(1) {
      File f = File::New("./tmp/testMapGetInputStream1.txt");
      f->createNewFile();
      
      FileOutputStream output = FileOutputStream::New(f);
      output->open(O_TRUNC);
      output->writeString(String::New("hello!!"));
      
      MappedFile file = MappedFile::New("./tmp/testMapGetInputStream1.txt",
                                          256);
      auto stream = file->getInputStream();
      if(stream == nullptr) {
          TEST_FAIL("TestMappedFile getInputStream case1");
      }
      stream->open();
      auto data = stream->readAll();
      if(!data->toString()->sameAs("hello!!")) {
          TEST_FAIL("TestMappedFile getInputStream case2");
      }
      break;
    }
    

    TEST_OK("TestMappedFile getInputStream case100");
}
