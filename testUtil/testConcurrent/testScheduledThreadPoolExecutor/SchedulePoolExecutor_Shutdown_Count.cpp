#include <stdio.h>
#include <unistd.h>
#include <atomic>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Long.hpp"
#include "TimeWatcher.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int scheduleShutdownCount{0};
int runCount{0};

DECLARE_CLASS(ScheduleShutDownTask) IMPLEMENTS(Runnable){
public:
    void run() {
	  {
		  AutoLock l(m);
		  if(status != 0) {
			  printf("run status is %d \n",status);
			  return;
		  }
		  status = 1;
		  runCount++;
	  }
	  
      usleep(1000 * 15000);
    }

    bool onInterrupt() {
	  {
		  AutoLock l(m);
		  if(status != 0) {
			  printf("interrupt status is %d \n",status);
			  return true;
		  }
		  status = 2;
		  scheduleShutdownCount++;
	  }
      return true;
    }
	
private:
	Mutex m = createMutex();
	int status = 0;
};

void testShutdownCount() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();
	
	for(int i = 0;i<32*1024;i++) {
      pool->schedule(30000,createScheduleShutDownTask());
    }
    usleep(1000*100);

    pool->shutdown();
    pool->awaitTermination();
	int r1 = runCount;
	int r2 = scheduleShutdownCount;
	printf("r1 is %d,r2 is %d \n",r1,r2);
	
    if((r1 + r2) != 32*1024) {
      TEST_FAIL("[ScheduledThreadPoolExecutor Shutdown case1],count is %d",r1+r2);
    }
    break;
  }

  TEST_OK("[ScheduledThreadPoolExecutor Shutdown case100]");
}
