#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ZipMemoryStream.hpp"
#include "Exception.hpp"
#include "MethodNotSupportException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testZipDecompress() {
  while(1) {
     String testData = String::New("hello,this is ss");
     ZipMemoryStream stream = ZipMemoryStream::New();
     auto compressData = stream->compress(testData->toByteArray());
     auto decompressData = stream->decompress(compressData)->toString();
     
     if(!testData->equals(decompressData)) {
         TEST_FAIL("[ZipeMemoryStream Decompress Test case1]");
     }
     
     String testData2 = String::New("hello,this is dd");
     auto compressData2 = stream->compress(testData2->toByteArray());
     auto decompressData2 = stream->decompress(compressData2);
     
     if(!testData2->equals(decompressData2->toString())) {
         TEST_FAIL("[ZipeMemoryStream Decompress Test case2]");
     }
     break;
  }
    
  TEST_OK("[ZipeMemoryStream Decompress Test case100]");
}
