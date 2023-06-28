#include <stdio.h>
#include <unistd.h>

#include "HashSet.hpp"
#include "HashMap.hpp"

using namespace obotcha;

extern void testHashAdd();
extern void testHashIteratorRemove();
extern void testHashContains();
extern void testHashSetForeach();
extern void testHashSetGet();
extern void testHashRemove();

int main() {
    testHashRemove();
    testHashSetGet();
    testHashSetForeach();
    testHashAdd();
    testHashIteratorRemove();
    testHashContains();
    return 0;
}
