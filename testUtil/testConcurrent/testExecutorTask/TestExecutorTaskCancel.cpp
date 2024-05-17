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

int run2 = 0;

DECLARE_CLASS(MyRunnable2) IMPLEMENTS(Runnable) {
public:
    void run() {
		run2 = 1;
	}
};

void testExecutorTaskCancel() {
	while(1) {
		int r1 = 0;
		auto task = ExecutorTask::New(MyRunnable2::New(),[&](ExecutorTask task){
			if(r1 == 0) {
				r1 = 2;
			} else if(r1 == 2) {
				r1 = 3;
			}
		});
		
		task->cancel();
		if(r1 != 2) {
			TEST_FAIL("Test ExecutorTask Cancel case1");
		}

		task->cancel();
		if(r1 != 2) {
			TEST_FAIL("Test ExecutorTask Cancel case2");
		}
		break;
	}
	
	while(1) {
		int r1 = 0;
		auto task = ExecutorTask::New(MyRunnable2::New(),[&](ExecutorTask task){
			if(r1 == 0) {
				r1 = 2;
			} else if(r1 == 2) {
				r1 = 3;
			}
		});
		
		task->execute();
		usleep(1000*100);
		task->cancel();
		if(r1 != 0) {
			TEST_FAIL("Test ExecutorTask Cancel case3");
		}
	
		task->cancel();
		if(r1 != 0) {
			TEST_FAIL("Test ExecutorTask Cancel case4");
		}
		break;
	}
	
	
    TEST_OK("Test ExecutorTask Cancel case100");
}