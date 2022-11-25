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

void testMappedFileInputStream() {

  //readLine();
  while(1) {
      MappedFile file = createMappedFile("./tmp/base_data");
      InputStream stream = file->getInputStream();
      ByteArray data = createByteArray(128);
      int len = stream->read(data);
      if(len != 32) {
         TEST_FAIL("[MappedFileInputStream Test case1],len is %d",len);
         break;
      }

      if(!data->toString()->equals("hello world,this is a test data.")) {
        TEST_FAIL("[MappedFileInputStream Test case2]");
        break;
      }
      break;
  }

  TEST_OK("[MappedFileInputStream Test case100]");
}
