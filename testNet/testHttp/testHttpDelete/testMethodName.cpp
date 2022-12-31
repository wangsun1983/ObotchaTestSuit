#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "HttpDelete.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testMethodName() {
    HttpDelete del = createHttpDelete("abc");
    if(!del->getMethodName()->equals(st(HttpMethod)::DeleteString)) {
        TEST_FAIL("testHttpDelete getMethodName case1");
    }
    TEST_OK("testHttpDelete getMethodName case100");
}
