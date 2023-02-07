#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Integer.hpp"
#include "String.hpp"

using namespace obotcha;

extern void testJsonValueTypeCheck();
extern void testJsonValueSize();
extern void testJsonValueGet();
extern void testJsonValueAppend();

int main() {
    testJsonValueTypeCheck();
    testJsonValueSize();
    testJsonValueGet();
    testJsonValueAppend();
    return 0;
}
