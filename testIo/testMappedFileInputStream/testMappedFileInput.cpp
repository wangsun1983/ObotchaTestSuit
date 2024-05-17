#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "TextLineReader.hpp"
#include "TestLog.hpp"
#include "MappedFile.hpp"
#include "MappedFileInputStream.hpp"

using namespace obotcha;

void testMappedFileInputStream() {

  //readLine();
  while(1) {
      MappedFile file = MappedFile::New("./tmp/base_data");
      InputStream stream = file->getInputStream();
      ByteArray data = ByteArray::New(128);
      int len = stream->read(data);
      if(len != 32) {
         TEST_FAIL("[MappedFileInputStream Test case1]");
         break;
      }

      if(!data->toString()->sameAs("hello world,this is a test data.")) {
        TEST_FAIL("[MappedFileInputStream Test case2]");
        break;
      }
      break;
  }

  TEST_OK("[MappedFileInputStream Test case100]");
}
