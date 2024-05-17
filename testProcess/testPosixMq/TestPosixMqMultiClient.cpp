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
    ProcessMq sendMq = ProcessMq::New("multiabc1",false);
    ProcessMq readMq1 = ProcessMq::New("multiabc1",false);
    ProcessMq readMq2 = ProcessMq::New("multiabc1",false);
      
    Thread t1 = Thread::New([readMq1]{
      ByteArray data = ByteArray::New(readMq1->getMsgSize());
      int len = readMq1->receive(data);
      if(!data->toString()->sameAs("hello")) {
        TEST_FAIL("[ProcessMq Test MultiClient {send/receive()} case1]");
      }
    });
    t1->start();

    Thread t2 = Thread::New([readMq2]{
      sleep(2);
      ByteArray data = ByteArray::New(readMq2->getMsgSize());
      int len = readMq2->receive(data);
      if(!data->toString()->sameAs("world")) {
        TEST_FAIL("[ProcessMq Test MultiClient {send/receive()} case2]");
      }
    });
    t2->start();

    sleep(1);
    String sendData = String::New("hello");
    sendMq->send(sendData->toByteArray());
    
    sendData = String::New("world");
    sendMq->send(sendData->toByteArray());
    
    t1->join();
    t2->join();

    sendMq->clear();
	readMq1->close();
	readMq2->close();
    TEST_OK("[ProcessMq Test MultiClient {send/receive()} case3]");
}
