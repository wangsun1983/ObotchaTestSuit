#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Integer.hpp"
#include "JsonReader.hpp"
#include <vector>

using namespace obotcha;

extern void testSimpleSql();
extern void testSqlObjectValues();

int main() {
    testSimpleSql();
    testSqlObjectValues();
}
