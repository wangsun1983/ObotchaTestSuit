#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <mutex>

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
#include "Random.hpp"

using namespace obotcha;

void testTimeCheck() {
  TimeWatcher watch = createTimeWatcher();
  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxPendingTaskNum(1024)
              ->setMaxThreadNum(16)
              ->newScheduledThreadPool();
              
    std::vector<uint64_t> vector;
    Random rand = createRandom();
    CountDownLatch latch = createCountDownLatch(128);
    
    std::mutex m;
    std::vector<uint64_t> intervals;
    
    for(int i = 0;i < 128;i++) {
        auto interval = rand->nextInt(100,800);
        auto current = st(System)::CurrentTimeMillis();
        pool->schedule(interval,[&](uint64_t interval,uint64_t current) {
            m.lock();
            intervals.push_back(interval);
            m.unlock();
            
            auto now = st(System)::CurrentTimeMillis();
            //printf("now is %ld,before is %ld,interval is %ld ,cost is %ld\n",now,current,interval,now - current);
            if(now - current > interval + 10) {
                TEST_FAIL("[ScheduledThreadPoolExecutor TimeCheck case1],current is %ld,interval is %ld,now is %ld",
                            current,interval,now);
            }
            latch->countDown();
        },interval,current);
    }
    
    latch->await();
    
    if(intervals.size() != 128) {
        TEST_FAIL("[ScheduledThreadPoolExecutor TimeCheck case2],size is %d",intervals.size());
    }
    
    int cursor = intervals[0];
    for(int i = 1;i < 128;i++) {
        if(cursor > (intervals[i] + 10)) {
            TEST_FAIL("[ScheduledThreadPoolExecutor TimeCheck case3],cursor is %ld,intevals is %ld",cursor,intervals[i]);
        }
        cursor = intervals[i];
    }
    break;    
  }
  TEST_OK("[ScheduledThreadPoolExecutor TimeCheck case100]");
}
