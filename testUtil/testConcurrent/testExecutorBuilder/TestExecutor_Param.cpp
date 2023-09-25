#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"

#include "ThreadCachedPoolExecutor.hpp"
#include "ThreadPoolExecutor.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "ExecutorBuilder.hpp"

using namespace obotcha;

void testExecutorParam() {
	while(1) {
		auto pool = createExecutorBuilder()->setMaxPendingTaskNum(1)
										   ->setDefaultThreadNum(2)
										   ->setMaxSubmitTaskWaitTime(3)
										   ->newThreadPool();
		if(pool->getMaxPendingTaskNum() != 1) {
			TEST_FAIL("Test ExecutorBuilder Param case7,result is %d",pool->getMaxPendingTaskNum());
		}
		
		if(pool->getDefaultThreadNum() != 2) {
			TEST_FAIL("Test ExecutorBuilder Param case8,result is %d",pool->getDefaultThreadNum());
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 3) {
			TEST_FAIL("Test ExecutorBuilder Param case8_1,result is %d",pool->getMaxSubmitTaskWaitTime());
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = createExecutorBuilder()->setMaxPendingTaskNum(1)
										   ->setMaxThreadNum(5)
										   ->setMinThreadNum(3)
										   ->setMaxSubmitTaskWaitTime(3)
										   ->setMaxNoWorkingTime(7)
										   ->newCachedThreadPool();
	    if(pool->getMaxPendingTaskNum() != 1) {
	    	TEST_FAIL("Test ExecutorBuilder Param case9");
	    }
	
		if(pool->getMaxThreadNum() != 5) {
			TEST_FAIL("Test ExecutorBuilder Param case10");
		}
		
		if(pool->getMinThreadNum() != 3) {
			TEST_FAIL("Test ExecutorBuilder Param case11");
		}
		
		if(pool->getMaxNoWorkingTime() != 7) {
			TEST_FAIL("Test ExecutorBuilder Param case12");
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 3) {
			TEST_FAIL("Test ExecutorBuilder Param case13");
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = createExecutorBuilder()->setMaxPendingTaskNum(9)
										   ->setMaxSubmitTaskWaitTime(10)
										   ->newScheduledThreadPool();
												
	    if(pool->getMaxPendingTaskNum() != 9) {
			TEST_FAIL("Test ExecutorBuilder Param case14");
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 10) {
			TEST_FAIL("Test ExecutorBuilder Param case15");
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = createExecutorBuilder()->setMaxPendingTaskNum(6)
										   ->setDefaultThreadNum(7)
										   ->setMaxSubmitTaskWaitTime(8)
										   ->newPriorityThreadPool();
												
	    if(pool->getMaxPendingTaskNum() != 6) {
			TEST_FAIL("Test ExecutorBuilder Param case16");
		}
		
		if(pool->getDefaultThreadNum() != 7) {
			TEST_FAIL("Test ExecutorBuilder Param case17");
		}
		
		if(pool->getMaxSubmitTaskWaitTime() != 8) {
			TEST_FAIL("Test ExecutorBuilder Param case18");
		}
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
    
    TEST_OK("Test ExecutorBuilder Param case100");
}