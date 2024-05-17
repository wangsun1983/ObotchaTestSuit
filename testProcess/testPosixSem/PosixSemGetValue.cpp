#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ProcessSem.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testGetValue() {
    st(ProcessSem)::Create("sem_t1",1);
	auto sem1 = ProcessSem::New("sem_t1");
	if(sem1->getValue() != 1) {
		TEST_FAIL("[ProcessSem testGetValue case1]");
	}
	
	st(ProcessSem)::Create("sem_t2",0);
	auto sem2 = ProcessSem::New("sem_t2");
	Thread t1 = Thread::New([&]{
		TimeWatcher w = TimeWatcher::New();
		if(sem2->getValue() != 0) {
			TEST_FAIL("[ProcessSem testGetValue case2]");
		}
		w->start();
		sem2->wait();
		auto ret = w->stop();
		if(ret > 200 || ret < 95) {
			TEST_FAIL("[ProcessSem testGetValue case3],ret is %d",ret);
		}
		
		if(sem2->getValue() != 0) {
			TEST_FAIL("[ProcessSem testGetValue case4],v is %d",sem2->getValue());
		}
	});
	t1->start();
	usleep(1000*100);
	sem2->post();
	t1->join();
	if(sem2->getValue() != 0) {
		TEST_FAIL("[ProcessSem testGetValue case5], v is %d",sem2->getValue());
	}
	
	sem2->post();
	if(sem2->getValue() != 1) {
		TEST_FAIL("[ProcessSem testGetValue case6], v is %d",sem2->getValue());
	}
	
	TimeWatcher w2 = TimeWatcher::New();
	w2->start();
	sem2->wait();
	auto ret = w2->stop();
	if(ret > 5) {
		TEST_FAIL("[ProcessSem testGetValue case7], v is %d",ret);
	}
	
	if(sem2->getValue() != 0) {
		TEST_FAIL("[ProcessSem testGetValue case8], v is %d",sem2->getValue());
	}
	
	TEST_OK("[ProcessSem testGetValue case100]");
	return 0;
}
