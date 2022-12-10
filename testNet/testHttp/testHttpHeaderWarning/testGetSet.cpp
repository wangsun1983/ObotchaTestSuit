#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderWarning.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpDate.hpp"

using namespace obotcha;

void testGetSet() {

    HttpHeaderWarning warning = createHttpHeaderWarning();
    warning->setCode(100);
    if(warning->getCode() != 100) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case1]");
    }
    
    warning->setAgent(createString("aagent"));
    if(!warning->getAgent()->equals(createString("aagent"))) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case2]");
    }
    
    warning->setText(createString("ttext"));
    if(!warning->getText()->equals(createString("ttext"))) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case3]");
    }
    
    auto date = createHttpDate(createDateTime());
    warning->setDateTime(date);
    if(date != warning->getDateTime()) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case4]");
    }
    
    TEST_OK("[HttpHeaderWarning test GetSet case100]");
}
