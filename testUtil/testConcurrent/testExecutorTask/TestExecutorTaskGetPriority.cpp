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

DECLARE_CLASS(MyRunnable3) IMPLEMENTS(Runnable) {
public:
    void run() {
	}
};

void testExecutorTaskGetPriority() {
	auto task = createExecutorTask(createMyRunnable3(),[&](ExecutorTask task){
	});
	
	if(task->getPriority() != st(Concurrent)::TaskPriority::Medium) {
		TEST_FAIL("Test ExecutorTask GetPriority case1");
	}
	
	task->setPriority(st(Concurrent)::TaskPriority::Low);
	if(task->getPriority() != st(Concurrent)::TaskPriority::Low) {
		TEST_FAIL("Test ExecutorTask GetPriority case2");
	}
	
    TEST_OK("Test ExecutorTask GetPriority case100");
}