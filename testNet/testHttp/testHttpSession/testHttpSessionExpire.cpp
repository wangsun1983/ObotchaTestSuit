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

void testHttpSessionExipre() {

    while(1) {
        HttpSession ss = st(HttpSessionManager)::getInstance()->createSession(2);
        ss->setAttribute("a",createString("value_a"));
        String v = ss->getAttribute<String>(createString("a"));
        if(v == nullptr || !v->sameAs("value_a")) {
            TEST_FAIL("[testHttpSessionExpire case1]");
        }
        
        sleep(3);
        v = ss->getAttribute<String>(createString("a"));
        if(v != nullptr) {
            TEST_FAIL("[testHttpSessionExpire case2]");
        }
        break;
    }
    
    while(1) {
        HttpSession ss = st(HttpSessionManager)::getInstance()->createSession(2);
        ss->setAttribute("a",createString("value_a"));
        sleep(1);
        String v = ss->getAttribute<String>(createString("a"));
        if(v == nullptr || !v->sameAs("value_a")) {
            TEST_FAIL("[testHttpSessionExpire case3]");
        }
        
        sleep(1);
        v = ss->getAttribute<String>(createString("a"));
        if(v == nullptr || !createString("value_a")->equals(v)) {
            TEST_FAIL("[testHttpSessionExpire case4]");
        }
        
        usleep(1000*2100);
        v = ss->getAttribute<String>(createString("a"));
        if(v != nullptr || createString("value_a")->equals(v)) {
            TEST_FAIL("[testHttpSessionExpire case5]");
        }
        break;
    }
    
    TEST_OK("[testHttpSessionExpire case100]");
}
