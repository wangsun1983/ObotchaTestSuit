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

DECLARE_CLASS(MyRunnable5) IMPLEMENTS(Runnable) {
public:
    void run() {
	}
};

void testExecutorTaskGetRunnable() {
	while(1) {
		auto r = createMyRunnable5();
		auto task = createExecutorTask(r,[&](ExecutorTask task){
		});
		if(r != task->getRunnable()) {
			TEST_FAIL("Test ExecutorTask GetRunnable case1");
		}
		
		task = createExecutorTask(nullptr,[&](ExecutorTask task){
		});
		if(task->getRunnable() != nullptr) {
			TEST_FAIL("Test ExecutorTask GetRunnable case2");
		}
		break;
	}
	
    TEST_OK("Test ExecutorTask GetRunnable case100");
}