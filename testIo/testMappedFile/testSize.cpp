#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"
#include "MappedFile.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSize() {
    while(1) {
      File f = File::New("./tmp/testMapGetInputStream2.txt");
      f->createNewFile();
      
      FileOutputStream output = FileOutputStream::New(f);
      output->open(O_TRUNC);
      output->writeString(String::New("hello!!"));
      
      MappedFile file = MappedFile::New("./tmp/testMapGetInputStream1.txt",
                                          256);
      if(file->size() != 256) {
          TEST_FAIL("TestMappedFile size case1");
      }
      break;
    }
    

    TEST_OK("TestMappedFile size case100");
}
