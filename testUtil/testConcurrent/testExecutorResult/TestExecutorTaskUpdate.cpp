#include "Executor.hpp"
#include "TestLog.hpp"
#include "Future.hpp"

#include "ThreadCachedPoolExecutor.hpp"
#include "ThreadPoolExecutor.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "ExecutorResult.hpp"
#include "ExecutorBuilder.hpp"

using namespace obotcha;

void testExecutorTaskUpdate() {
	ExecutorResult result = ExecutorResult::New();
	
	int value = 100;
	result->update(value);
	if(result->get<int>() != 100) {
		TEST_FAIL("Test ExecutorResult update case1");
	}
	
	byte value1 = 12;
	result->update(value1);
	if(result->get<byte>() != 12) {
		TEST_FAIL("Test ExecutorResult update case2");
	}
	
	double value2 = 12.12;
	result->update(value2);
	if(st(Double)::Compare(result->get<double>(),12.12) != 0) {
		TEST_FAIL("Test ExecutorResult update case3");
	}
	
	float vaule3 = 33.44;
	result->update(vaule3);
	if(st(Float)::Compare(result->get<float>(),33.44) != 0) {
		TEST_FAIL("Test ExecutorResult update case4");
	}
	
	bool vaule4 = true;
	result->update(vaule4);
	if(result->get<bool>() != true) {
		TEST_FAIL("Test ExecutorResult update case5");
	}
	
	bool vaule5 = false;
	result->update(vaule5);
	if(result->get<bool>() != false) {
		TEST_FAIL("Test ExecutorResult update case6");
	}
	
	long vaule6 = 12345;
	result->update(vaule6);
	if(result->get<long>() != 12345) {
		TEST_FAIL("Test ExecutorResult update case7");
	}
	
	uint16_t vaule7 = 312;
	result->update(vaule7);
	if(result->get<uint16_t>() != 312) {
		TEST_FAIL("Test ExecutorResult update case8");
	}
	
	uint32_t vaule8 = 1312;
	result->update(vaule8);
	if(result->get<uint32_t>() != 1312) {
		TEST_FAIL("Test ExecutorResult update case9");
	}
	
	uint64_t vaule9 = 5643;
	result->update(vaule9);
	if(result->get<uint64_t>() != 5643) {
		TEST_FAIL("Test ExecutorResult update case10");
	}
    TEST_OK("Test ExecutorResult update case100");
}