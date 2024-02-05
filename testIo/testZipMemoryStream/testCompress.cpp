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
     String testData = createString("hello,this is ss");
     ZipMemoryStream stream = createZipMemoryStream();
     auto compressData = stream->compress(testData->toByteArray());
     auto decompressData = stream->decompress(compressData)->toString();
     
     if(!testData->equals(decompressData)) {
         TEST_FAIL("[ZipeMemoryStream Decompress Test case1]");
     }
     
     String testData2 = createString("hello,this is dd");
     auto compressData2 = stream->compress(testData2->toByteArray());
     auto decompressData2 = stream->decompress(compressData2);
     
     if(!testData2->equals(decompressData2->toString())) {
         TEST_FAIL("[ZipeMemoryStream Decompress Test case2]");
     }
     break;
  }
  
  while(1) {
      ByteArray data = createByteArray(1024*1024*4);
      for(long i = 0;i < 1024*1024*4;i++) {
          data[i] = i%128;
      }
      
      ZipMemoryStream stream = createZipMemoryStream();
      auto compressData = stream->compress(data);
      auto decompressData = stream->decompress(compressData);
      
      if(decompressData->size() != 1024*1024*4) {
          TEST_FAIL("[ZipeMemoryStream Decompress Test case3]");
      }
      
      for(long i = 0;i < 1024*1024*4;i++) {
          if(data[i] != decompressData[i]) {
              TEST_FAIL("[ZipeMemoryStream Decompress Test case4]");
          }
      }
      break;
  }
  
  while(1) {
      ByteArray data = createByteArray(1);
      data[0] = 123;
      
      ZipMemoryStream stream = createZipMemoryStream();
      auto compressData = stream->compress(data);
      auto decompressData = stream->decompress(compressData);
      
      if(decompressData->size() != 1) {
          TEST_FAIL("[ZipeMemoryStream Decompress Test case5]");
      }
      
      if(decompressData[0] != 123) {
          TEST_FAIL("[ZipeMemoryStream Decompress Test case6]");
      }
      break;
  }
    
  TEST_OK("[ZipeMemoryStream Decompress Test case100]");
}
