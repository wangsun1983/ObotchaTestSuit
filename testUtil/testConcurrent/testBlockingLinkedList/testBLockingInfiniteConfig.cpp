#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListInfiniteConfig() {
    if(st(BlockingLinkedList)<int>::kLinkedListSizeInfinite != 0) {
		TEST_FAIL("BlockingLinkedList InfiniteConfig case1");
	}

    TEST_OK("BlockingLinkedList InfiniteConfig case100");
}
