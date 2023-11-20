#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int handler1_count = 0;
long time_125 = 0;
long time_126 = 0;
long time_127 = 0;

DECLARE_CLASS(FrontMessageHandler1) IMPLEMENTS(Handler) {
public:
    _FrontMessageHandler1(Looper l):_Handler(l){
        
    }
    
    void handleMessage(Message msg) {
        switch(msg->what) {
            case 100:
            handler1_count = 123;
            break;
            
            case 125:
                time_125 = st(System)::CurrentTimeMillis();
                usleep(100*1000);
            break;
            
            case 126:
                time_126 = st(System)::CurrentTimeMillis();
                usleep(100*1000);
            break;
            
            case 127:
                time_127 = st(System)::CurrentTimeMillis();
                usleep(100*1000);
            break;
        }
    }
};

void testHandlerFrontMessage() {
    HandlerThread t1 = createHandlerThread();
    t1->start();
    //case1
    FrontMessageHandler1 handler = createFrontMessageHandler1(t1->getLooper());
    Message msg = createMessage();
    msg->what = 100;
    handler->sendMessageAtFrontOfQueue(msg);

    usleep(100*1000);
    if(handler1_count != 123) {
       TEST_FAIL("[Handler Test front message case1]");
    }

    //case2
    Message msg2 = createMessage();
    msg2->what = 124;
    handler->sendMessage(msg2);

    Message msg3 = createMessage();
    msg3->what = 125;
    handler->sendMessage(msg3);

    Message msg4 = createMessage();
    msg4->what = 126;
    handler->sendMessage(msg4);

    Message msg5 = createMessage();
    msg5->what = 127;
    handler->sendMessageAtFrontOfQueue(msg5);
    usleep(1000*400);

    if(time_127 >= time_126 || time_126 > time_127) {
       TEST_FAIL("[Handler Test front message case2],time_126 is %ld,time_127 is %ld",time_126,time_127);
    }
    
    //case3
    
}
