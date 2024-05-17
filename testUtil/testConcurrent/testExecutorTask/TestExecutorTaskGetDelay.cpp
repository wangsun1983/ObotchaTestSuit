#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"

#include "ThreadCachedPoolExecutor.hpp"
#include "ThreadPoolExecutor.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "ExecutorResult.hpp"
#include "ExecutorBuilder.hpp"
#include "Thread.hpp"

using namespace obotcha;

DECLARE_CLASS(MyRunnable4) IMPLEMENTS(Runnable) {
public:
    void run() {
	}
};

void testExecutorTaskGetDelay() {
	while(1) {
		auto task = ExecutorTask::New(MyRunnable4::New(),[&](ExecutorTask task){
		});
		
		if(task->getDelay() != 0) {
			TEST_FAIL("Test ExecutorTask GetDelay case1");
		}
		
		task->setDelay(100);
		if(task->getDelay() != 100) {
			TEST_FAIL("Test ExecutorTask GetDelay case2");
		}
		break;
	}
	
	while(1) {
		auto task = ExecutorTask::New(MyRunnable4::New(),[&](ExecutorTask task){
		},23,st(Concurrent)::TaskPriority::Low);
		
		if(task->getDelay() != 23) {
			TEST_FAIL("Test ExecutorTask GetDelay case3");
		}
		
		task->setDelay(100);
		if(task->getDelay() != 100) {
			TEST_FAIL("Test ExecutorTask GetDelay case4");
		}
		break;
	}
	
    TEST_OK("Test ExecutorTask GetDelay case100");
}