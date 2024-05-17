#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderParser.hpp"
#include "ByteRingArrayReader.hpp"
#include "HttpMethod.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "Math.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHttpHeaderSize() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    auto version = header->getVersion();
    if(version == nullptr) {
        TEST_FAIL("[HttpHeader test Size case1]");
    }
    
    //it contains version！！！
    for(int i = 2;i < 1024;i++) {
        header->set(String::New(i),String::New(i));
        if(header->size() != i) {
            printf("head size is %d,expect is %d \n",header->size(),i+1);
            TEST_FAIL("[HttpHeader test Size case1]");
        }
    }  
    break;
  }
 
  TEST_OK("[HttpHeader test Size case100]");

}
