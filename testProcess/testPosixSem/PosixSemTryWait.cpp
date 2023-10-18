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

int testTryWait() {
    st(ProcessSem)::Create("sem_v1",0);
	auto sem1 = createProcessSem("sem_v1");
	TimeWatcher w = createTimeWatcher();
	w->start();
	int ret = sem1->tryWait();
	auto cost = w->stop();
	if(ret >= 0) {
		TEST_FAIL("[ProcessSem tryWait case1],ret is %d",ret);
	}
	
	if(cost > 5) {
		TEST_FAIL("[ProcessSem tryWait case2]");
	}
	
	TEST_OK("[ProcessSem tryWait case100]");
	return 0;
}
