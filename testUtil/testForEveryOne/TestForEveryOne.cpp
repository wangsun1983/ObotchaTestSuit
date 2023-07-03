#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

extern void testArrayList();
extern void testLinkedList();
extern void testHashMap();
extern void testStack();
extern void testConcurrentQueue();
extern void testConcurrentHashMap();
extern void testConcurrentLinkedList();
extern void testConcurrentStack();
extern void testBlockingQueue();
extern void testHashSet();
extern void testConcurrentHashSet();
extern void testList();

int main() {
    testList();
    testConcurrentHashSet();
    testHashSet();
    testBlockingQueue();
    testConcurrentStack();
    testConcurrentLinkedList();
    testConcurrentHashMap();
    testConcurrentQueue();
    testStack();
    testArrayList();
    testLinkedList();
    testHashMap();

    return 0;
}
