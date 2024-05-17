#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int count_1 = 0;
int count_2 = 0;

DECLARE_CLASS(RemoveEqualHandler) IMPLEMENTS(Handler) {
public:
    _RemoveEqualHandler(Looper l):_Handler(l) {}
    void handleMessage(Message msg) {
        switch(msg->what) {
            case 1:
            auto data = Cast<String>(msg->data);
            if(data->sameAs("h")) {
                count_1 = 100;
            }
            
            if(data->sameAs("b")) {
                count_2 = 101;
            }
        }
    }
};

void testHandlerRemoveEqualMessage() {
    //case1
    HandlerThread t1 = HandlerThread::New();
    t1->start();
    //case1
    String data1 = String::New("h");
    String data2 = String::New("b");
    RemoveEqualHandler handler = RemoveEqualHandler::New(t1->getLooper());
    
    Message msg1 = Message::New();
    msg1->what = 1;
    msg1->data = data1;
    handler->sendMessageDelayed(msg1,200);
    
    Message msg2 = Message::New();
    msg2->what = 1;
    msg2->data = data2;
    handler->sendMessageDelayed(msg2,200);
    
    handler->removeEqualMessages(1,data2);
    usleep(1000*300);
    
    if(count_1 != 100) {
        TEST_FAIL("[Handler Test RemoveEqualMessage case1]");
    }
    
    if(count_2 == 101) {
        TEST_FAIL("[Handler Test RemoveEqualMessage case2]");
    }
    
    TEST_OK("[Handler Test RemoveEqualMessage case100]");
}
