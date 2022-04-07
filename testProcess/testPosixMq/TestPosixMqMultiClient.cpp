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
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testPosixMqMultiClient() {
    PosixMq sendMq = createPosixMq("multiabc1",st(PosixMq)::Send);
    PosixMq readMq1 = createPosixMq("multiabc1",st(PosixMq)::Recv);
    PosixMq readMq2 = createPosixMq("multiabc1",st(PosixMq)::Recv);
      
    Thread t1 = createThread([readMq1]{
      ByteArray data = createByteArray(readMq1->getMsgSize());
      int len = readMq1->receive(data);
      if(!data->toString()->equals("hello")) {
        TEST_FAIL("[PosixMq Test MultiClient {send/receive()} case1]");
      }
    });
    t1->start();

    Thread t2 = createThread([readMq2]{
      sleep(2);
      ByteArray data = createByteArray(readMq2->getMsgSize());
      int len = readMq2->receive(data);
      if(!data->toString()->equals("world")) {
        TEST_FAIL("[PosixMq Test MultiClient {send/receive()} case2]");
      }
    });
    t2->start();

    sleep(1);
    String sendData = createString("hello");
    sendMq->send(sendData->toByteArray());

    sendData = createString("world");
    sendMq->send(sendData->toByteArray());
    
    t1->join();
    t2->join();

    sendMq->clear();
    TEST_OK("[PosixMq Test MultiClient {send/receive()} case3]");
}
