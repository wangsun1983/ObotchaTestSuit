#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testNoBlockPipe() {

  const int testDatalength = 32;
  char testData[testDatalength];
  for(int i = 0;i<testDatalength;i++) {
    testData[i] = i;
  }

  //int write(PipeType type,ByteArray data);
  //int read(PipeType type,ByteArray buff);
  Pipe pp = createPipe(st(Pipe)::NonBlock);
  
  int pid = fork();
  if(pid == 0) {
     //child process
     ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
     pp->write(array);
     exit(0);
  } else {
     sleep(1);
     ByteArray array = createByteArray(testDatalength);
     int length = pp->read(array);

     if(length < testDatalength) {
         TEST_FAIL("[Pipe Test {noblock write/read()} case1]");
         return 1;
     }

     for(int i = 0; i < testDatalength;i++) {
       if(array->at(i) != i) {
         TEST_FAIL("[Pipe Test {noblock write/read()} case2]");
         break;
       }
     }
   }

   TEST_OK("[Pipe Test {noblock write/read()} case3]");


   Pipe pp1_1 = createPipe(st(Pipe)::NonBlock);

   pid = fork();
   if(pid == 0) {
      //child process
      sleep(1);
      ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
      pp->write(array);
      exit(0);
   } else {
      ByteArray array = createByteArray(testDatalength);
      int length = pp->read(array);
      if(length != -1) {
          TEST_FAIL("[Pipe Test {noblock write/read()} case4]");
          return 1;
      }
    }

    TEST_OK("[Pipe Test {noblock write/read()} case5]");


   //int closePipe(PipeType type);
   Pipe pp2 = createPipe(st(Pipe)::NonBlock);
   

   pid = fork();
   if(pid == 0) {
      //child process
      pp2->closeReadChannel();
      ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
      pp2->write(array);
      exit(0);
   } else {
      sleep(1);
      pp2->closeWriteChannel();
      ByteArray array = createByteArray(testDatalength);
      int length = pp2->read(array);

      if(length < testDatalength) {
          TEST_FAIL("[Pipe Test {noblock closePipe()} case1]");
          return 1;
      }

      for(int i = 0; i < testDatalength;i++) {
        if(array->at(i) != i) {
          TEST_FAIL("[Pipe Test {noblock closePipe()} case2]");
          break;
        }
      }
    }

    TEST_OK("[Pipe Test {noblock closePipe()} case3]");

    //int closePipe(PipeType type);
    Pipe pp3 = createPipe(st(Pipe)::NonBlock);

    pid = fork();
    if(pid == 0) {
       //child process
       pp3->closeWriteChannel();
       ByteArray array = createByteArray(testDatalength);
       int length = pp3->read(array);
       if(length > 0) {
           TEST_FAIL("[Pipe Test {noblock closePipe()} case4]");
       }
       exit(0);
    } else {
       pp3->closeWriteChannel();
       ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
       int result = pp3->write(array);
       if(result >= 0) {
           TEST_FAIL("[Pipe Test {noblock closePipe()} case5]");
       }
     }

     TEST_OK("[Pipe Test {noblock closePipe()} case6]");

}
