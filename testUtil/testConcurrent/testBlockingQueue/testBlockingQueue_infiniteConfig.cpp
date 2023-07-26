#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueInfiniteConfig() {
    if(st(BlockingQueue)<int>::kQueueSizeInfinite != -1) {
		TEST_FAIL("BlockingQueue InfiniteConfig case1");
	}

    TEST_OK("BlockingQueue InfiniteConfig case100");
}
