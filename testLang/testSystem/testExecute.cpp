#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "System.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testExecute() {
    String str = st(System)::ExecuteForResult("cd ./bin && ./test");
    if(str->size() != 1024*48) {
        TEST_FAIL("Test System executeForResult case1");
    }
    
    const char *p = str->toChars();
    for(int i = 0; i < 1024*48;i++) {
        if(p[i] != 'a') {
            TEST_FAIL("Test System executeForResult case2");
            break;
        }
    }
    
    TEST_OK("Test System executeForResult case100");
}
