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
      File f = createFile("./tmp/testMapGetInputStream2.txt");
      f->createNewFile();
      
      FileOutputStream output = createFileOutputStream(f);
      output->open(O_TRUNC);
      output->writeString(createString("hello!!"));
      
      MappedFile file = createMappedFile("./tmp/testMapGetInputStream1.txt",
                                          256);
      if(file->size() != 256) {
          TEST_FAIL("TestMappedFile size case1");
      }
      break;
    }
    

    TEST_OK("TestMappedFile size case100");
}
