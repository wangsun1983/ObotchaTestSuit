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
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testProcessMqMultiClient() {
    ProcessMq sendMq = createProcessMq("multiabc1",st(ProcessMq)::Send);
    ProcessMq readMq1 = createProcessMq("multiabc1",st(ProcessMq)::Recv);
    ProcessMq readMq2 = createProcessMq("multiabc1",st(ProcessMq)::Recv);
      
    Thread t1 = createThread([readMq1]{
      ByteArray data = createByteArray(readMq1->getMsgSize());
      int len = readMq1->receive(data);
      if(!data->toString()->sameAs("hello")) {
        TEST_FAIL("[ProcessMq Test MultiClient {send/receive()} case1]");
      }
    });
    t1->start();

    Thread t2 = createThread([readMq2]{
      sleep(2);
      ByteArray data = createByteArray(readMq2->getMsgSize());
      int len = readMq2->receive(data);
      if(!data->toString()->sameAs("world")) {
        TEST_FAIL("[ProcessMq Test MultiClient {send/receive()} case2]");
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
	readMq1->close();
	readMq2->close();
    TEST_OK("[ProcessMq Test MultiClient {send/receive()} case3]");
}
