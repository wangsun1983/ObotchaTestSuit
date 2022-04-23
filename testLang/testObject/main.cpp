#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"

using namespace obotcha;

extern void testEqual();
extern void testReferenceCount();
extern void testReferenceArraylist();
extern void testReferenceHashMap();
extern void testAutoCreator();

int main() {
    testAutoCreator();
    testEqual();
    testReferenceCount();
    testReferenceArraylist();
    testReferenceHashMap();
    return 0;
}
