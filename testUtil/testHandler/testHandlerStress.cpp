#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

long totalCount = 0;

DECLARE_CLASS(StressHandler) IMPLEMENTS(Handler) {
public:
    _StressHandler(Looper l):_Handler(l) {
		
	}
	
	void handleMessage(Message msg) {
		totalCount++;
		auto v = Cast<Long>(msg->data)->toValue();
		
		if(millseconds == 0) {
			millseconds = v;
		} else {
			if(millseconds > v) {
				TEST_FAIL("[Handler Test {Stress} case1],millscoonds is %ld,msg is %ld",
							millseconds,v);
				millseconds = v;
			}
		}
	}
private:
	long millseconds = 0;
};

void testHandlerStress() {
  
  HandlerThread handlerThread = createHandlerThread();
  handlerThread->start();
  
  StressHandler h = createStressHandler(handlerThread->getLooper());
  
  Thread t1 = createThread([&h] {
     for(int i = 0;i < 1024*16;i++) {
		 auto time = st(System)::CurrentTimeMillis();
		 auto msg = createMessage(1);
		 msg->data = createLong(time);
		 h->sendMessage(msg);
		 usleep(1000);
	 }
  });
  
  Thread t2 = createThread([&h] {
     for(int i = 0;i < 1024*16;i++) {
  		 auto time = st(System)::CurrentTimeMillis();
  		 auto msg = createMessage(1);
  		 msg->data = createLong(time);
  		 h->sendMessage(msg);
  		 usleep(1000);
  	 }
  });
	
  t1->start();
  t2->start();
  t1->join();
  t2->join();

  while(h->size() != 0 || totalCount < 1024*32) {
	printf("totalCount is %ld \n",totalCount);
	usleep(1000*1000);
  }
  TEST_OK("[Handler Test {testHandlerStress} case5]");
}
