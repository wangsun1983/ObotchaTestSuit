#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"
#include "ExecutorBuilder.hpp"

using namespace obotcha;

void testIsExecuting() {
    while(1) {
		auto pool = createExecutorBuilder()
		          ->setDefaultThreadNum(1)
		          ->newPriorityThreadPool();
		if(!pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case1");
		}
		
		if(pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case2");
		}
		
		pool->shutdown();
		
		if(pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case3");
		}
		
		if(!pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case4");
		}
		break;
	}
	
	while(1) {
		auto pool = createExecutorBuilder()
		          ->newCachedThreadPool();
		if(!pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case5");
		}
		
		if(pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case6");
		}
		
		pool->shutdown();
		
		if(pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case7");
		}
		
		if(!pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case8");
		}
		break;
	}
	
	while(1) {
		auto pool = createExecutorBuilder()
		          ->newThreadPool();
		if(!pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case9");
		}
		
		if(pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case10");
		}
		
		pool->shutdown();
		
		if(pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case11");
		}
		
		if(!pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case12");
		}
		break;
	}
	
	while(1) {
		auto pool = createExecutorBuilder()
		          ->newScheduledThreadPool();
		if(!pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case13");
		}
		
		if(pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case14");
		}
		
		pool->shutdown();
		
		if(pool->isExecuting()) {
			TEST_FAIL("Test Executor isExecuting case15");
		}
		
		if(!pool->isShutDown()) {
			TEST_FAIL("Test Executor isExecuting case16");
		}
		break;
	}
	
    TEST_OK("Test Executor isExecuting case100");
}