#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"

using namespace obotcha;

DECLARE_CLASS(MyExecutor) IMPLEMENTS(Executor) {
public:
    _MyExecutor() {
        mMaxPendingTaskNum = 1;
        mDefaultThreadNum = 2;
        mMaxThreadNum = 3;
        mMinThreadNum = 4;
        mMaxNoWorkingTime = 5;
        mMaxSubmitTaskWaitTime = 6;
    }
    
    int shutdown() {
        return 0;
    }

    bool isTerminated() {
        return true;
    }

    int awaitTermination(long timeout = 0) {
        return 1;
    }
    
    Future submitRunnable(Runnable r) {
        return nullptr;
    }
    
    Future submitTask(ExecutorTask task) {
        return nullptr;
    }
    
    size_t getPendingTaskNum() {
        return 0;
    }
    
    size_t getExecutingThreadNum() {
        return 0;
    }
    
    void onRemoveTask(sp<_ExecutorTask> task) {
        //TODO
    }
};


void testExecutorParam() {
    MyExecutor t = createMyExecutor();
    if(t->getMaxPendingTaskNum() != 1) {
        TEST_FAIL("Test Executor Param case1");
    }
    
    if(t->getDefaultThreadNum() != 2) {
        TEST_FAIL("Test Executor Param case2");
    }
    
    if(t->getMaxThreadNum() != 3) {
        TEST_FAIL("Test Executor Param case3");
    }
    
    if(t->getMinThreadNum() != 4) {
        TEST_FAIL("Test Executor Param case4");
    }
    
    if(t->getMaxNoWorkingTime() != 5) {
        TEST_FAIL("Test Executor Param case5");
    }
    
    if(t->getMaxSubmitTaskWaitTime() != 6) {
        TEST_FAIL("Test Executor Param case6");
    }
    
    TEST_OK("Test Executor Param case100");
}