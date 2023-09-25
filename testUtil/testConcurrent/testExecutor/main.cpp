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

extern void testExecutorParam();
extern void testIsExecuting();
extern void testGetSetRemoveTask();

int main() {
	testGetSetRemoveTask();
    testExecutorParam();
	testIsExecuting();
    return 0;
}
