#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"

#include "ThreadCachedPoolExecutor.hpp"
#include "ThreadPoolExecutor.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "ThreadScheduledPoolExecutor.hpp"

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
    MyExecutor t = MyExecutor::New();
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
	
	while(1) {
		auto pool = ThreadPoolExecutor::New(1,/*mMaxPendingTaskNum*/
											2,/*mDefaultThreadNum*/
											3 /*mMaxSubmitTaskWaitTime*/);
		if(pool->getMaxPendingTaskNum() != 1) {
			TEST_FAIL("Test Executor Param case7,result is %d",pool->getMaxPendingTaskNum());
		}
		
		if(pool->getDefaultThreadNum() != 2) {
			TEST_FAIL("Test Executor Param case8,result is %d",pool->getDefaultThreadNum());
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 3) {
			TEST_FAIL("Test Executor Param case8_1,result is %d",pool->getMaxSubmitTaskWaitTime());
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = ThreadCachedPoolExecutor::New(1,/*mMaxPendingTaskNum, */
		                                           5,/*mMaxThreadNum, */
		                                           3,/*mMinThreadNum,*/
		                                           4,/*mMaxSubmitTaskWaitTime,*/
		                                           7/*mMaxNoWorkingTime*/);
	    if(pool->getMaxPendingTaskNum() != 1) {
	    	TEST_FAIL("Test Executor Param case9");
	    }
	
		if(pool->getMaxThreadNum() != 5) {
			TEST_FAIL("Test Executor Param case10");
		}
		
		if(pool->getMinThreadNum() != 3) {
			TEST_FAIL("Test Executor Param case11");
		}
		
		if(pool->getMaxNoWorkingTime() != 7) {
			TEST_FAIL("Test Executor Param case12");
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 4) {
			TEST_FAIL("Test Executor Param case13");
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = ThreadScheduledPoolExecutor::New(9,/*mMaxPendingTaskNum,*/
		                                              10 /*mMaxSubmitTaskWaitTime*/);
												
	    if(pool->getMaxPendingTaskNum() != 9) {
			TEST_FAIL("Test Executor Param case14");
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 10) {
			TEST_FAIL("Test Executor Param case15");
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = ThreadPriorityPoolExecutor::New(6,/*mMaxPendingTaskNum, */
                                                     7,/*mDefaultThreadNum,*/
                                                     8 /*mMaxSubmitTaskWaitTime*/);
												
	    if(pool->getMaxPendingTaskNum() != 6) {
			TEST_FAIL("Test Executor Param case16");
		}
		
		if(pool->getDefaultThreadNum() != 7) {
			TEST_FAIL("Test Executor Param case17");
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 8) {
			TEST_FAIL("Test Executor Param case18");
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
    
    TEST_OK("Test Executor Param case100");
}