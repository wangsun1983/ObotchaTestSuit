#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Integer.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "System.hpp"

using namespace obotcha;

extern int testMutexNormal();
extern int testMutexInOneThread();
extern void testMutex_Lock();
extern void testMutex_TryLock();
extern void testMutex_UnLock();
extern int testMutex_isOwner();

int main() {
    testMutex_isOwner();
    testMutexInOneThread();
    testMutexNormal();
    testMutex_Lock();
    testMutex_TryLock();
    testMutex_UnLock();

    return 1;
}
