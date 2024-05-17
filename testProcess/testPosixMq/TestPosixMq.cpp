#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ProcessMq.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testProcessMq() {

  ProcessMq mq = ProcessMq::New("abc",false);
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
    ProcessMq mq = ProcessMq::New("abc",false);
    
    ByteArray array = ByteArray::New((byte *)&testData[0],testDatalength);
    //TEST_FAIL("child start write \n");
    mq->send(array);
    mq->close();
    exit(0);
  } else {
    ByteArray array = ByteArray::New(mq->getMsgSize());
    //sleep(1);
    //TEST_FAIL("father start read \n");
    ProcessMq mq = ProcessMq::New("abc",false);
    
    int length = mq->receive(array);
    if(length < testDatalength) {
        TEST_FAIL("[ProcessMq Test {send/receive()} case1],length is %d,error is %s",length,strerror(errno));
        return 1;
    }

    for(int i = 0; i < testDatalength;i++) {
      if(array->at(i) != i) {
        TEST_FAIL("[ProcessMq Test {send/receive()} case2]");
        break;
      }
    }
    mq->clear();
    TEST_OK("[ProcessMq Test {send/receive()} case3]");
  }
  usleep(1000 *100);
  
  //send(ByteArray data,int prio);
  //int receive(ByteArray buff);
  pid = fork();
  if(pid == 0) {
    //child process
    ProcessMq mq = ProcessMq::New("abc",false);
    
    ByteArray array = ByteArray::New((byte *)&testData[0],testDatalength);
    //TEST_FAIL("child start write \n");
    int ret = mq->send(array);
	
    ByteArray array2 = ByteArray::New((byte *)&testData[1],testDatalength-1);
    ret = mq->send(array2,5);
	
    mq->close();
    return 1;
  } else {
    sleep(1);
    ByteArray array = ByteArray::New(mq->getMsgSize());
    ProcessMq mq = ProcessMq::New("abc",false);
    
    int length = mq->receive(array);
    if(length != testDatalength - 1) {
        TEST_FAIL("[ProcessMq Test {send/receive()} case4],length is %d,testDatalength is %d",length,testDatalength);
        return 1;
    }

    for(int i = 0; i < testDatalength - 1;i++) {
      if(array->at(i) != i + 1) {
        TEST_FAIL("[ProcessMq Test {send/receive()} case5]");
        break;
      }
    }

    length = mq->receive(array);
    if(length != testDatalength) {
        TEST_FAIL("[ProcessMq Test {send/receive()} case6],length is %d,testDatalength is %d",length,testDatalength - 1);
        return 1;
    }

    for(int i = 0; i < testDatalength;i++) {
      if(array->at(i) != i) {
        TEST_FAIL("[ProcessMq Test {send/receive()} case6_1]");
        break;
      }
    }
    mq->clear();
    TEST_OK("[ProcessMq Test {send/receive()} case7]");
  }

  //send(ByteArray data,int prio);

  //int receiveTimeout(ByteArray buff);
  pid = fork();
  if(pid == 0) {
    //child process
    exit(0);
  } else {
    ByteArray array = ByteArray::New(mq->getMsgSize());
    ProcessMq mq = ProcessMq::New("abc",false);
    long current = st(System)::CurrentTimeMillis();
    int length = mq->receiveTimeout(array,500);
    
    long interval = st(System)::CurrentTimeMillis() - current;
    if(interval > 505 || interval < 495) {
      TEST_FAIL("[ProcessMq Test {receiveTimeout()} case1],interval is %d",interval);
      return 1;
    }

    if(length > 0) {
      TEST_FAIL("[ProcessMq Test {receiveTimeout()} case2]");
      return 1;
    }
    mq->clear();
    TEST_OK("[ProcessMq Test {receiveTimeout()} case3]");
  }

  return 0;
}
