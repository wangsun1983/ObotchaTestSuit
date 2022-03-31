#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "YamlArray.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

extern void testReflectTo(); 
extern void testImportFrom();
extern void testSaveFile();

int main() {
    testReflectTo();
    testImportFrom();
    testSaveFile();

    return 0;
}
