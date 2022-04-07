#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "PosixMq.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testPosixMq() {

  PosixMq mq = createPosixMq("abc",st(PosixMq)::Send);
  mq->clear();

  const int testDatalength = 32;
  char testData[testDatalength];
  for(int i = 0;i<testDatalength;i++) {
    testData[i] = i;
  }

  //int send(ByteArray data);
  //int receive(ByteArray buff);
  int pid = fork();
  if(pid == 0) {
    //child process
    sleep(10);
    PosixMq mq = createPosixMq("abc",st(PosixMq)::Send);
    
    ByteArray array = createByteArray((const byte *)&testData[0],testDatalength);
    //TEST_FAIL("child start write \n");
    mq->send(array);
    mq->close();
    exit(0);
  } else {
    ByteArray array = createByteArray(mq->getMsgSize());
    //sleep(1);
    //TEST_FAIL("father start read \n");
    PosixMq mq = createPosixMq("abc",st(PosixMq)::Recv);
    
    int length = mq->receive(array);
    if(length < testDatalength) {
        TEST_FAIL("[PosixMq Test {send/receive()} case1],length is %d,error is %s",length,strerror(errno));
        return 1;
    }

    for(int i = 0; i < testDatalength;i++) {
      if(array->at(i) != i) {
        TEST_FAIL("[PosixMq Test {send/receive()} case2]");
        break;
      }
    }
    mq->clear();
    TEST_OK("[PosixMq Test {send/receive()} case3]");
  }

  //send(ByteArray data,int prio);
  //int receive(ByteArray buff);
  pid = fork();
  if(pid == 0) {
    //child process
    PosixMq mq = createPosixMq("abc",st(PosixMq)::Send);
    
    ByteArray array = createByteArray((const byte *)&testData[0],testDatalength);
    //TEST_FAIL("child start write \n");
    mq->send(array);

    ByteArray array2 = createByteArray((const byte *)&testData[1],testDatalength-1);
    mq->send(array2,st(PosixMq)::Normal);
    mq->close();
    exit(0);
  } else {
    sleep(1);
    ByteArray array = createByteArray(mq->getMsgSize());
    //sleep(1);
    //TEST_FAIL("father start read \n");
    PosixMq mq = createPosixMq("abc",st(PosixMq)::Recv);
    
    int length = mq->receive(array);

    if(length != (testDatalength-1)) {
        TEST_FAIL("[PosixMq Test {send/receive()} case4]");
        return 1;
    }

    for(int i = 0; i < testDatalength - 1;i++) {
      if(array->at(i) != (i+1)) {
        TEST_FAIL("[PosixMq Test {send/receive()} case5]");
        break;
      }
    }

    length = mq->receive(array);

    if(length != testDatalength) {
        TEST_FAIL("[PosixMq Test {send/receive()} case6]");
        return 1;
    }

    for(int i = 0; i < testDatalength;i++) {
      if(array->at(i) != i) {
        TEST_FAIL("[PosixMq Test {send/receive()} case6]");
        break;
      }
    }
    mq->clear();
    TEST_OK("[PosixMq Test {send/receive()} case7]");
  }

  //send(ByteArray data,int prio);

  //int receiveTimeout(ByteArray buff);
  pid = fork();
  if(pid == 0) {
    //child process
    exit(0);
  } else {
    ByteArray array = createByteArray(mq->getMsgSize());
    //sleep(1);
    //TEST_FAIL("father start read \n");
    PosixMq mq = createPosixMq("abc",st(PosixMq)::Recv);
    long current = st(System)::currentTimeMillis();
    int length = mq->receiveTimeout(array,500);

    if(st(System)::currentTimeMillis() - current != 500) {
      TEST_FAIL("[PosixMq Test {receiveTimeout()} case1]");
      return 1;
    }

    if(length > 0) {
      TEST_FAIL("[PosixMq Test {receiveTimeout()} case2]");
      return 1;
    }
    mq->clear();
    TEST_OK("[PosixMq Test {receiveTimeout()} case3]");
  }

}
