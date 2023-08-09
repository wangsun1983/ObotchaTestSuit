#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ShareMemory.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testShareMemory() {
  const int testDatalength = 32;
  char testData[testDatalength];
  for(int i = 0;i<testDatalength;i++) {
    testData[i] = i;
  }

  //int write(ByteArray);
  //int read(ByteArray);
  //int read(int index,ByteArray);
  //int read(int);
  int pid = fork();
  if(pid == 0) {
      ShareMemory memory = createShareMemory("shareMemoryabc",testDatalength,st(ShareMemory)::WriteRead);
      
      ByteArray arr = createByteArray((byte *)&testData[0],32);
      memory->write(arr);
      exit(0);
  } else {
      sleep(1);
      ShareMemory memory = createShareMemory("shareMemoryabc",testDatalength,st(ShareMemory)::Read);
      

      ByteArray b = createByteArray(32);
      int length = memory->read(b);

      if(length < testDatalength) {
          TEST_FAIL("[ShareMemory Test {write/read()} case1]");
          return;
      }

      for(int i = 0; i < testDatalength;i++) {
        if(b->at(i) != i) {
          TEST_FAIL("[ShareMemory Test {write/read()} case2]");
          break;
        }

        if(memory->read(i) != i) {
          TEST_FAIL("[ShareMemory Test {write/read()} case3]");
          break;
        }
      }

      ByteArray b2 = createByteArray(64);
      int length2 = memory->read(b2);
      if(length2 < testDatalength) {
          TEST_FAIL("[ShareMemory Test {write/read()} case4]");
          return;
      }

      for(int i = 0; i < testDatalength;i++) {
        if(b2->at(i) != i) {
          TEST_FAIL("[ShareMemory Test {write/read()} case5]");
          break;
        }
      }

      ByteArray b3 = createByteArray(64);
      if(memory->read(256,b3) != -EINVAL) {
        TEST_FAIL("[ShareMemory Test {write/read()} case6]");
      }

      if(memory->read(16,b3) < 0) {
        TEST_FAIL("[ShareMemory Test {write/read()} case7]");
      }

      for(int i = 0; i < (testDatalength-16);i++) {
        if(b3->at(i) != i) {
          TEST_FAIL("[ShareMemory Test {write/read()} case8]");
          break;
        }
      }

      TEST_OK("[ShareMemory Test {write/read()} case9]");

      //while(1) {}
  }

  //int write(ByteArray);
  //int write(int index,ByteArray);
  //int write(int index,char v);
  pid = fork();
  if(pid == 0) {
    ShareMemory memory = createShareMemory("shareMemoryabc",testDatalength,st(ShareMemory)::WriteRead);
    
    ByteArray arr = createByteArray((byte *)&testData[0],32);
    if(memory->write(256,arr) != -EINVAL) {
      TEST_FAIL("[ShareMemory Test {write/read()} case10]");
    }

    if(memory->write(256,'c') != -EINVAL) {
      TEST_FAIL("[ShareMemory Test {write/read()} case11]");
    }

    memory->write(16,'c');
    exit(0);
  } else {
    sleep(1);
    ShareMemory memory = createShareMemory("shareMemoryabc",testDatalength,st(ShareMemory)::WriteRead);
    
    if(memory->read(16) != 'c') {
      TEST_FAIL("[ShareMemory Test {write/read()} case12]");
    }

    TEST_OK("[ShareMemory Test {write/read()} case13]");
  }

}
