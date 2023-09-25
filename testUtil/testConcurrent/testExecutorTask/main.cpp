#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testExecutorTaskGetStatus();
extern void testExecutorTaskCancel();
extern void testExecutorTaskGetPriority();
extern void testExecutorTaskGetDelay();
extern void testExecutorTaskGetRunnable();
extern void testExecutorTaskExecute();

int main() {
	testExecutorTaskExecute();
	testExecutorTaskGetRunnable();
	testExecutorTaskGetDelay();
	testExecutorTaskGetPriority();
	testExecutorTaskGetStatus();
	testExecutorTaskCancel();
    return 0;
}
