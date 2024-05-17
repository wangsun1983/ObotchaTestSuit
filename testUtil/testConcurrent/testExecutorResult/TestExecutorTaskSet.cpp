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

void testExecutorTaskSet() {
	while(1) {
		auto pool = ExecutorBuilder::New()
		            ->setDefaultThreadNum(1)
		            ->newThreadPool();
		auto f1 = pool->submit([]{
			int value = 100;
			st(ExecutorResult)::Set(value);
		});
		if(f1->getResult<int>() != 100) {
			TEST_FAIL("Test ExecutorResult set case1");
		}
		
		auto f2 = pool->submit([]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f2->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case2");
		}
		
		auto f3 = pool->submit([]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f3->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case3");
		}
		
		auto f4 = pool->submit([]{
			double value = 11.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Double)::Compare(f4->getResult<double>(),11.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case4");
		}
		
		auto f5 = pool->submit([]{
			float value = 211.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Float)::Compare(f5->getResult<float>(),211.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case5");
		}
		
		auto f6 = pool->submit([]{
			bool value = false;
			st(ExecutorResult)::Set(value);
		});
		if(f6->getResult<bool>() != false) {
			TEST_FAIL("Test ExecutorResult set case6");
		}
		
		auto f7 = pool->submit([]{
			bool value = true;
			st(ExecutorResult)::Set(value);
		});
		if(f7->getResult<bool>() != true) {
			TEST_FAIL("Test ExecutorResult set case7");
		}
		
		auto f8 = pool->submit([]{
			long value = 12345;
			st(ExecutorResult)::Set(value);
		});
		if(f8->getResult<long>() != 12345) {
			TEST_FAIL("Test ExecutorResult set case8");
		}
		
		auto f9 = pool->submit([]{
			uint16_t value = 1122;
			st(ExecutorResult)::Set(value);
		});
		if(f9->getResult<uint16_t>() != 1122) {
			TEST_FAIL("Test ExecutorResult set case9");
		}
		
		auto f10 = pool->submit([]{
			uint32_t value = 2233;
			st(ExecutorResult)::Set(value);
		});
		if(f10->getResult<uint32_t>() != 2233) {
			TEST_FAIL("Test ExecutorResult set case10");
		}
		
		auto f11 = pool->submit([]{
			uint64_t value = 7788;
			st(ExecutorResult)::Set(value);
		});
		if(f11->getResult<uint64_t>() != 7788) {
			TEST_FAIL("Test ExecutorResult set case11");
		}
		
		auto f12 = pool->submit([]{
			st(ExecutorResult)::Set(String::New("hello world"));
		});
		
		if(!f12->getResult<String>()->sameAs("hello world")) {
			TEST_FAIL("Test ExecutorResult set case12");
		}
		
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
    
	while(1) {
		auto pool = ExecutorBuilder::New()
		            ->newCachedThreadPool();
					
		auto f1 = pool->submit([]{
			int value = 100;
			st(ExecutorResult)::Set(value);
		});
		if(f1->getResult<int>() != 100) {
			TEST_FAIL("Test ExecutorResult set case13");
		}
		
		auto f2 = pool->submit([]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f2->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case14");
		}
		
		auto f3 = pool->submit([]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f3->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case15");
		}
		
		auto f4 = pool->submit([]{
			double value = 11.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Double)::Compare(f4->getResult<double>(),11.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case16");
		}
		
		auto f5 = pool->submit([]{
			float value = 211.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Float)::Compare(f5->getResult<float>(),211.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case17");
		}
		
		auto f6 = pool->submit([]{
			bool value = false;
			st(ExecutorResult)::Set(value);
		});
		if(f6->getResult<bool>() != false) {
			TEST_FAIL("Test ExecutorResult set case18");
		}
		
		auto f7 = pool->submit([]{
			bool value = true;
			st(ExecutorResult)::Set(value);
		});
		if(f7->getResult<bool>() != true) {
			TEST_FAIL("Test ExecutorResult set case19");
		}
		
		auto f8 = pool->submit([]{
			long value = 12345;
			st(ExecutorResult)::Set(value);
		});
		if(f8->getResult<long>() != 12345) {
			TEST_FAIL("Test ExecutorResult set case20");
		}
		
		auto f9 = pool->submit([]{
			uint16_t value = 1122;
			st(ExecutorResult)::Set(value);
		});
		if(f9->getResult<uint16_t>() != 1122) {
			TEST_FAIL("Test ExecutorResult set case21");
		}
		
		auto f10 = pool->submit([]{
			uint32_t value = 2233;
			st(ExecutorResult)::Set(value);
		});
		if(f10->getResult<uint32_t>() != 2233) {
			TEST_FAIL("Test ExecutorResult set case22");
		}
		
		auto f11 = pool->submit([]{
			uint64_t value = 7788;
			st(ExecutorResult)::Set(value);
		});
		if(f11->getResult<uint64_t>() != 7788) {
			TEST_FAIL("Test ExecutorResult set case23");
		}
		
		auto f12 = pool->submit([]{
			st(ExecutorResult)::Set(String::New("hello world"));
		});
		
		if(!f12->getResult<String>()->sameAs("hello world")) {
			TEST_FAIL("Test ExecutorResult set case24");
		}
		
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = ExecutorBuilder::New()
		            ->newScheduledThreadPool();
					
		auto f1 = pool->schedule(1,[]{
			int value = 100;
			st(ExecutorResult)::Set(value);
		});
		if(f1->getResult<int>() != 100) {
			TEST_FAIL("Test ExecutorResult set case25");
		}
		
		auto f2 = pool->schedule(1,[]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f2->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case26");
		}
		
		auto f3 = pool->schedule(1,[]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f3->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case27");
		}
		
		auto f4 = pool->schedule(1,[]{
			double value = 11.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Double)::Compare(f4->getResult<double>(),11.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case28");
		}
		
		auto f5 = pool->schedule(1,[]{
			float value = 211.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Float)::Compare(f5->getResult<float>(),211.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case29");
		}
		
		auto f6 = pool->schedule(1,[]{
			bool value = false;
			st(ExecutorResult)::Set(value);
		});
		if(f6->getResult<bool>() != false) {
			TEST_FAIL("Test ExecutorResult set case30");
		}
		
		auto f7 = pool->schedule(1,[]{
			bool value = true;
			st(ExecutorResult)::Set(value);
		});
		if(f7->getResult<bool>() != true) {
			TEST_FAIL("Test ExecutorResult set case31");
		}
		
		auto f8 = pool->schedule(1,[]{
			long value = 12345;
			st(ExecutorResult)::Set(value);
		});
		if(f8->getResult<long>() != 12345) {
			TEST_FAIL("Test ExecutorResult set case32");
		}
		
		auto f9 = pool->schedule(1,[]{
			uint16_t value = 1122;
			st(ExecutorResult)::Set(value);
		});
		if(f9->getResult<uint16_t>() != 1122) {
			TEST_FAIL("Test ExecutorResult set case33");
		}
		
		auto f10 = pool->schedule(1,[]{
			uint32_t value = 2233;
			st(ExecutorResult)::Set(value);
		});
		if(f10->getResult<uint32_t>() != 2233) {
			TEST_FAIL("Test ExecutorResult set case34");
		}
		
		auto f11 = pool->schedule(1,[]{
			uint64_t value = 7788;
			st(ExecutorResult)::Set(value);
		});
		if(f11->getResult<uint64_t>() != 7788) {
			TEST_FAIL("Test ExecutorResult set case35");
		}
		
		auto f12 = pool->schedule(1,[]{
			st(ExecutorResult)::Set(String::New("hello world"));
		});
		
		if(!f12->getResult<String>()->sameAs("hello world")) {
			TEST_FAIL("Test ExecutorResult set case36");
		}
		
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
	
	while(1) {
		auto pool = ExecutorBuilder::New()
		            ->newPriorityThreadPool();
					
		auto f1 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			int value = 100;
			st(ExecutorResult)::Set(value);
		});
		if(f1->getResult<int>() != 100) {
			TEST_FAIL("Test ExecutorResult set case37");
		}
		
		auto f2 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f2->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case38");
		}
		
		auto f3 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			byte value = 11;
			st(ExecutorResult)::Set(value);
		});
		if(f3->getResult<byte>() != 11) {
			TEST_FAIL("Test ExecutorResult set case39");
		}
		
		auto f4 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			double value = 11.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Double)::Compare(f4->getResult<double>(),11.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case40");
		}
		
		auto f5 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			float value = 211.23;
			st(ExecutorResult)::Set(value);
		});
		
		if(st(Float)::Compare(f5->getResult<float>(),211.23) != 0) {
			TEST_FAIL("Test ExecutorResult set case41");
		}
		
		auto f6 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			bool value = false;
			st(ExecutorResult)::Set(value);
		});
		if(f6->getResult<bool>() != false) {
			TEST_FAIL("Test ExecutorResult set case42");
		}
		
		auto f7 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			bool value = true;
			st(ExecutorResult)::Set(value);
		});
		if(f7->getResult<bool>() != true) {
			TEST_FAIL("Test ExecutorResult set case43");
		}
		
		auto f8 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			long value = 12345;
			st(ExecutorResult)::Set(value);
		});
		if(f8->getResult<long>() != 12345) {
			TEST_FAIL("Test ExecutorResult set case44");
		}
		
		auto f9 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			uint16_t value = 1122;
			st(ExecutorResult)::Set(value);
		});
		if(f9->getResult<uint16_t>() != 1122) {
			TEST_FAIL("Test ExecutorResult set case45");
		}
		
		auto f10 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			uint32_t value = 2233;
			st(ExecutorResult)::Set(value);
		});
		if(f10->getResult<uint32_t>() != 2233) {
			TEST_FAIL("Test ExecutorResult set case46");
		}
		
		auto f11 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			uint64_t value = 7788;
			st(ExecutorResult)::Set(value);
		});
		if(f11->getResult<uint64_t>() != 7788) {
			TEST_FAIL("Test ExecutorResult set case47");
		}
		
		auto f12 = pool->preempt(st(Concurrent)::TaskPriority::Low,[]{
			st(ExecutorResult)::Set(String::New("hello world"));
		});
		
		if(!f12->getResult<String>()->sameAs("hello world")) {
			TEST_FAIL("Test ExecutorResult set case48");
		}
		
		pool->shutdown();
		pool->awaitTermination();
		break;
	}
    TEST_OK("Test ExecutorResult set case100");
}