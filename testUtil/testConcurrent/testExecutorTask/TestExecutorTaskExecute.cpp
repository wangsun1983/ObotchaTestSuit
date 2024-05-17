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

DECLARE_CLASS(MyExecuteRunnable) IMPLEMENTS(Runnable) {
public:
    void run() {
		usleep(100*1000);
	}
};

DECLARE_CLASS(MyExecuteRunnable2) IMPLEMENTS(Runnable) {
public:
    _MyExecuteRunnable2(std::function<void(sp<_MyExecuteRunnable2>)> c) {
		onExecute = c;
	}
	
    void run() {
		onExecute(AutoClone(this));
	}
	
private:
	std::function<void(sp<_MyExecuteRunnable2>)> onExecute;
};

void testExecutorTaskExecute() {
	while(1) {
		auto r = MyExecuteRunnable::New();
		auto task = ExecutorTask::New(r,[&](ExecutorTask task){
		});
		
		Thread t1 = Thread::New([&]{
			if(st(Executor)::GetCurrentTask() != nullptr) {
				TEST_FAIL("Test ExecutorTask Execute case1");
			}
			
			Thread t2 = Thread::New([&] {
				task->execute();
			});
			t2->start();
			t2->join();
			if(st(Executor)::GetCurrentTask() != nullptr) {
				TEST_FAIL("Test ExecutorTask Execute case3");
			}
		});
		t1->start();
		t1->join();
		break;
	}
	
	while(1) {
		int executeFlag = 0;
		ExecutorTask task = nullptr;
		MyExecuteRunnable2 r = MyExecuteRunnable2::New([&](MyExecuteRunnable2 c){
			if(task != st(Executor)::GetCurrentTask()) {
				TEST_FAIL("Test ExecutorTask Execute case4");
			}
			executeFlag = 1;
		});
		
		task = ExecutorTask::New(r,[&](ExecutorTask task){
		});
		
		Thread t1 = Thread::New([&]{
			task->execute();
		});
		t1->start();
		t1->join();
		if(executeFlag != 1) {
			TEST_FAIL("Test ExecutorTask Execute case4");
		}
		break;
	}
	
    TEST_OK("Test ExecutorTask Execute case100");
}