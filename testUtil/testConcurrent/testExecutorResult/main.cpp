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

extern void testExecutorTaskSet();
extern void testExecutorTaskUpdate();

int main() {
	testExecutorTaskUpdate();
	testExecutorTaskSet();
    return 0;
}
