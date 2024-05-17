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

int run1 = 0;

DECLARE_CLASS(MyRunnable1) IMPLEMENTS(Runnable) {
public:
    void run() {
		usleep(1000*100);
		run1 = 1;
	}
};

void testExecutorTaskGetStatus() {
	while(1) {
		int r1 = 0;
		auto task = ExecutorTask::New(MyRunnable1::New(),[&](ExecutorTask task){
			r1 = 2;
		});
		
		if(task->getStatus() != st(Concurrent)::Status::Idle) {
			TEST_FAIL("Test ExecutorTask GetStatus case1");
		}
		
		task->cancel();
		if(task->getStatus() != st(Concurrent)::Status::Interrupt) {
			TEST_FAIL("Test ExecutorTask GetStatus case2");
		}
				
		task = ExecutorTask::New(MyRunnable1::New(),[&](ExecutorTask task){
			r1 = 3;
		});
		
		Thread t1 = Thread::New([&]{
			task->execute();
		});
		t1->start();
		
		usleep(1000*50);
		
		if(task->getStatus() != st(Concurrent)::Status::Running) {
			TEST_FAIL("Test ExecutorTask GetStatus case3,status is %d",static_cast<int>(task->getStatus()));
		}
		
		t1->join();
		if(task->getStatus() != st(Concurrent)::Status::Complete) {
			TEST_FAIL("Test ExecutorTask GetStatus case4");
		}
		break;					   
	}
	
	while(1) {
		int r1 = 0;
		auto task = ExecutorTask::New(MyRunnable1::New(),[&](ExecutorTask task){
			r1 = 2;
		});
		task->setPending();
		if(task->getStatus() != st(Concurrent)::Status::WaitingStart) {
			TEST_OK("Test ExecutorTask GetStatus case5");
		}
		break;
	}
	
	
    TEST_OK("Test ExecutorTask GetStatus case100");
}