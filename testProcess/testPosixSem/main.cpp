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

extern int normalTest();
extern int testGetValue();
extern int testTryWait();

int main() {
	testGetValue();
    normalTest();
	testTryWait();
	return 0;
}
 