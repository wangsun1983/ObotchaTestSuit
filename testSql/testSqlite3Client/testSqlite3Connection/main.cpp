#include <stdio.h>
#include <unistd.h>
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Reflect.hpp"
#include "Sqlite3Connection.hpp"
#include "SqlConnection.hpp"
#include "Sqlite3ConnectParam.hpp"
#include "TestLog.hpp"
#include "File.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

extern void testConnect();

int main() {
    testConnect();
    return 0;
}
