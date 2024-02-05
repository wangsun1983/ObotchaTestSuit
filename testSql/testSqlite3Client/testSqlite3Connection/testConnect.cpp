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

void testConnect() {
    Sqlite3ConnectParam param = createSqlite3ConnectParam();
    param->setPath("./testdata.db");
    SqlConnection c = createSqlite3Connection();
    int ret = c->connect(param);
    if(ret != 0) {
        TEST_FAIL("Sqlite3Connect connect case1");
    }
    
    Sqlite3ConnectParam param2 = createSqlite3ConnectParam();
    param2->setPath("./aabbcc.db");
    SqlConnection c2 = createSqlite3Connection();
    int ret2 = c2->connect(param2);
    if(ret2 == 0) {
        TEST_FAIL("Sqlite3Connect connect case2,ret is %d",ret2);
    }
}
