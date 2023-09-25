#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"
#include "Thread.hpp"
#include "ExecutorTask.hpp"

using namespace obotcha;

void testGetSetRemoveTask() {
    while(1) {
		ExecutorTask task = createExecutorTask(nullptr,nullptr);
		Thread t1 = createThread([&]{
			st(Executor)::SetCurrentTask(task);
			if(st(Executor)::GetCurrentTask() != task) {
				TEST_FAIL("Test Executor GetSetRemoveTask case1");
			}
		});
		t1->start();
		usleep(1000*100);
		if(st(Executor)::GetCurrentTask() != nullptr) {
			TEST_FAIL("Test Executor GetSetRemoveTask case2");
		}
		break;
	}
	
	while(1) {
		ExecutorTask task = createExecutorTask(nullptr,nullptr);
		st(Executor)::SetCurrentTask(task);
		Thread t1 = createThread([&]{
			st(Executor)::RemoveCurrentTask();
		});
		t1->start();
		usleep(1000*100);
		if(st(Executor)::GetCurrentTask() != task) {
			TEST_FAIL("Test Executor GetSetRemoveTask case3");
		}
		st(Executor)::RemoveCurrentTask();
		
		if(st(Executor)::GetCurrentTask() != nullptr) {
			TEST_FAIL("Test Executor GetSetRemoveTask case4");
		}
		break;
	}
    
    TEST_OK("Test Executor GetSetRemoveTask case100");
}