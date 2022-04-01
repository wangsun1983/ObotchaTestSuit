#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

extern void testYamlWriter();

int main() {
    testYamlWriter();
    return 0;
}
