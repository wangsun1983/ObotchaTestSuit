#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

extern void testReflectTo();
extern void testImportFrom();
extern void testReflectComplex();

int main() {
    testReflectTo();
    testImportFrom();
    testReflectComplex();
    return 0;
}
