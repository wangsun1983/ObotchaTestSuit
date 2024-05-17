#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "FifoPipe.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testSyncFifoPipe() {
  const int testDatalength = 32;
  char testData[testDatalength];
  for(int i = 0;i<testDatalength;i++) {
    testData[i] = i;
  }
  
  st(FifoPipe)::Create("mytest123");
  int pid = fork();
  if(pid == 0) {
    //child process,start write
    FifoPipe fifo = FifoPipe::New("mytest123",st(FifoPipe)::Type::Write);
    ByteArray array = ByteArray::New((byte *)&testData[0],testDatalength);
    fifo->write(array);
    return;
  } else {
    ByteArray array = ByteArray::New(testDatalength);
    FifoPipe fifo = FifoPipe::New("mytest123",st(FifoPipe)::Type::Read);
    int length = fifo->read(array);
    if(length != testDatalength) {
      TEST_FAIL("[FifoPipe Test {write/read()} case1,length is %d,err is %s]",length,CurrentError);
    }

    for(int i = 0; i < testDatalength;i++) {
      if(array->at(i) != i) {
        TEST_FAIL("[FifoPipe Test {write/read()} case2]");
        break;
      }
    }
    TEST_OK("[FifoPipe Test {write/read()} case3]");
  }


  //int release();
  pid = fork();
  if(pid == 0) {
    //child process,start write
    FifoPipe fifo = FifoPipe::New("mytest123",st(FifoPipe)::Type::Write);
    fifo->close();
    return;
  } else {
    ByteArray array = ByteArray::New(testDatalength);
    FifoPipe fifo = FifoPipe::New("mytest123",st(FifoPipe)::Type::Read);
    
    sleep(1);
    int length = fifo->read(array);
    if(length > 0) {
      TEST_FAIL("[FifoPipe Test {close()} case1],length is %d",length);
    }

    //fifo->clear();
    TEST_OK("[FifoPipe Test {close()} case2]");
  }

  //check clean
  st(FifoPipe)::Create("mytest1ab");
  FifoPipe fifo = FifoPipe::New("mytest1ab",st(FifoPipe)::Type::AsyncRead);
  if(access(fifo->getName()->toChars(),F_OK) != 0) {
    TEST_FAIL("[FifoPipe Test {clear()} case1]");
  }
  //fifo->clear();
  st(FifoPipe)::Clear("mytest1ab");
  if(access(fifo->getName()->toChars(),F_OK) == 0) {
    TEST_FAIL("[FifoPipe Test {clear()} case2]");
  }

  TEST_OK("[FifoPipe Test {clear()} case3]");
}
