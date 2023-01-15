#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpSession.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpSessionManager.hpp"

using namespace obotcha;

void testHttpSessionGetSet() {

    while(1) {
        HttpSession ss = st(HttpSessionManager)::getInstance()->createSession(1);
        ss->setMaxInactiveInterval(2);
        usleep(1000*1200);
        if(!ss->isValid()) {
            TEST_OK("[testHttpSessionGetSet case1]");
        }
        usleep(1000*850);
        if(ss->isValid()) {
            TEST_OK("[testHttpSessionGetSet case2]");
        }
        break;
    }
    
    while(1) {
        HttpSession ss = st(HttpSessionManager)::getInstance()->createSession(1);
        ss->setMaxInactiveInterval(2);
        usleep(1000*1200);
        ss->setAttribute(createString("abc"),
                         createString("bbb"));
        usleep(1000*1000);
        if(!ss->isValid()) {
            TEST_OK("[testHttpSessionGetSet case3]");
        }
        
        usleep(1000*1100);
        if(ss->isValid()) {
            TEST_OK("[testHttpSessionGetSet case4]");
        }
        break;
    }
    
    TEST_OK("[testHttpSessionGetSet case100]");
}
