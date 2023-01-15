#include <stdio.h>
#include <unistd.h>
#include <fstream>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ZipFileStream.hpp"
#include "Exception.hpp"
#include "MethodNotSupportException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testZipFileStreamRead() {
  while(1) {
    ZipFileStream stream = createZipFileStream();
    ByteArray data = createByteArray(1024);
    try {
        stream->read(data);
        TEST_FAIL("ZipFileStreamRead case1");
    } catch(...){}
    
    try {
        stream->read(data,1,1);
        TEST_FAIL("ZipFileStreamRead case2");
    } catch(...){}
    
    try {
        stream->read(data,1);
        TEST_FAIL("ZipFileStreamRead case3");
    } catch(...){}
    
    break;
  }

  TEST_OK("ZipFileStreamRead case100");
}
