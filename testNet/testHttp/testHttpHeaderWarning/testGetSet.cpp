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

    HttpHeaderWarning warning = HttpHeaderWarning::New();
    warning->setCode(100);
    if(warning->getCode() != 100) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case1]");
    }
    
    warning->setAgent(String::New("aagent"));
    if(!warning->getAgent()->equals(String::New("aagent"))) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case2]");
    }
    
    warning->setText(String::New("ttext"));
    if(!warning->getText()->equals(String::New("ttext"))) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case3]");
    }
    
    auto date = HttpDate::New(DateTime::New());
    warning->setDateTime(date);
    if(date != warning->getDateTime()) {
        TEST_FAIL("[HttpHeaderWarning test GetSet case4]");
    }
    
    TEST_OK("[HttpHeaderWarning test GetSet case100]");
}
