#include <stdio.h>
#include <unistd.h>
#include <vector>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "Random.hpp"
#include "AutoLock.hpp"
#include "TestLog.hpp"

using namespace obotcha;

class DelayTestData {
public:
  long start;
  long interval;
  long finished;
};

Mutex delayDataMutex = Mutex::New();
std::vector<DelayTestData *> datas;

DECLARE_CLASS(MyDelayedHandler) IMPLEMENTS(Handler) {
public:

  void handleMessage(Message msg) {
    AutoLock l(delayDataMutex);
    DelayTestData *data = datas[msg->what];
    data->finished = st(System)::CurrentTimeMillis();
  }
};


void testSendMessageDelayed() {
  MyDelayedHandler m = MyDelayedHandler::New();
  Random rnd = Random::New();

  for(int i = 0;i<1024;i++) {
    int interval = rnd->next<int>(100,800);
    {
      AutoLock l(delayDataMutex);
      DelayTestData *data = new DelayTestData();
      data->start = st(System)::CurrentTimeMillis();
      data->interval = interval;
      datas.push_back(data);
    }
    m->sendEmptyMessageDelayed(i,interval);
  }

  sleep(5);

  for(int i = 0;i<1024;i++) {
      DelayTestData *data = datas[i];
      //TEST_FAIL("trace start is %ld,finished is %ld,interval is %ld,real interval is %ld ",data->start,data->finished,data->interval,data->finished - data->start);
      if((data->finished - data->start) > (data->interval + 10)) {
        TEST_FAIL("[Handler Test {Test SendMessageDelayed} case1] !!!!error,start is %ld,finished is %ld,interval is %ld ",data->start,data->finished,data->interval);
      }
      delete data;
  }

}
