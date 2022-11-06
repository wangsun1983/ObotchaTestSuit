#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "BufferedReader.hpp"
#include "TestLog.hpp"
#include "MappedFile.hpp"
#include "MappedFileInputStream.hpp"

using namespace obotcha;

void testMappedFileOutputStream() {

  //readLine();
  while(1) {
      MappedFile file = createMappedFile("./tmp/base_data",128);
      OutputStream stream = file->getOutputStream();
      
      stream->write(createString("abcdef")->toByteArray());
      stream->flush();

      FileInputStream fstream = createFileInputStream("./tmp/base_data");
      fstream->open();
      ByteArray dd = createByteArray(256);
      fstream->read(dd);

      if(!dd->toString()->equals("abcdefworld,this is a test data.")) {
        TEST_FAIL("MappedFileOutputStream Test case1");
      }
      break;
  }

  TEST_OK("[MappedFileOutputStream Test case100]");
}
