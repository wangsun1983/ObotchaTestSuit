#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"

using namespace obotcha;

extern void testLinkeListBase();
extern void testLinkeListQueue();
extern void testPutFirst();
extern void testPutLast();
extern void testTakeLast();
extern void testTakeFirst();
extern void testLinkedListRemoveAt();
extern void testLinkedListRemove();
extern void testLinkeListQueueIterator();
extern void testLinkeListForeach();
extern void testLinkedListSize();
extern void testLinkedListPeekFirst();
extern void testLinkedListPeekLast();

int main() {
    testLinkedListPeekLast();
    testLinkedListPeekFirst();
    testLinkedListSize();
    testLinkeListForeach();
    testLinkeListQueueIterator();
    testLinkeListBase();
    testLinkeListQueue();
    testPutFirst();
    testPutLast();
    testTakeLast();
    testTakeFirst();
    testLinkedListRemoveAt();
    testLinkedListRemove();
    return 0;
}
