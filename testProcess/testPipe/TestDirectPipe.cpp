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
#include "IO.hpp"

using namespace obotcha;

int testDirectPipe() {

  const int testDatalength = 32;
  char testData[testDatalength];
  for(int i = 0;i<testDatalength;i++) {
    testData[i] = i;
  }

  //int write(PipeType type,ByteArray data);
  //int read(PipeType type,ByteArray buff);
  Pipe pp = createPipe(st(IO)::Direct);
  

  int pid = fork();
  if(pid == 0) {
     //child process
     ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
     pp->write(array);
     exit(0);
  } else {
     ByteArray array = createByteArray(testDatalength);
     int length = pp->read(array);

     if(length < testDatalength) {
         TEST_FAIL("[Pipe Test {direct write/read()} case1]");
         return 1;
     }

     for(int i = 0; i < testDatalength;i++) {
       if(array->at(i) != i) {
         TEST_FAIL("[Pipe Test {direct write/read()} case2]");
         break;
       }
     }
   }

   TEST_OK("[Pipe Test {direct write/read()} case3]");

   //int closePipe(PipeType type);
   Pipe pp2 = createPipe(st(IO)::Direct);
   

   pid = fork();
   if(pid == 0) {
      //child process
      pp2->closeReadChannel();
      ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
      pp2->write(array);
      exit(0);
   } else {
      pp2->closeWriteChannel();
      ByteArray array = createByteArray(testDatalength);
      int length = pp2->read(array);

      if(length < testDatalength) {
          TEST_FAIL("[Pipe Test {direct closePipe()} case1]");
          return 1;
      }

      for(int i = 0; i < testDatalength;i++) {
        if(array->at(i) != i) {
          TEST_FAIL("[Pipe Test {direct closePipe()} case2]");
          break;
        }
      }
    }

    TEST_OK("[Pipe Test {direct closePipe()} case3]");

    //int closePipe(PipeType type);
    Pipe pp3 = createPipe(st(IO)::Direct);
    

    pid = fork();
    if(pid == 0) {
       //child process
       pp3->closeWriteChannel();
       ByteArray array = createByteArray(testDatalength);
       int length = pp3->read(array);
       if(length > 0) {
           TEST_FAIL("[Pipe Test {direct closePipe()} case4]");
       }
       exit(0);
    } else {
       pp3->closeWriteChannel();
       ByteArray array = createByteArray((byte *)&testData[0],testDatalength);
       int result = pp3->write(array);
       if(result >= 0) {
           TEST_FAIL("[Pipe Test {direct closePipe()} case5]");
       }
     }

     TEST_OK("[Pipe Test {direct closePipe()} case6]");

}
