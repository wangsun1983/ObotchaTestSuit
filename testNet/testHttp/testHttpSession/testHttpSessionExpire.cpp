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
        HttpSession ss = st(HttpSessionManager)::getInstance()->createSession();
        ss->setAttribute("a",createString("value_a"));
        String v = ss->getAttribute<String>(createString("a"));
        if(v == nullptr || !v->equals("value_a")) {
            TEST_FAIL("[testHttpSessionExpire case1]");
        }
        
        sleep(121);
        v = ss->getAttribute<String>(createString("a"));
        if(v != nullptr) {
            TEST_FAIL("[testHttpSessionExpire case2]");
        }
        break;
    }
    
    while(1) {
        HttpSession ss = st(HttpSessionManager)::getInstance()->createSession();
        ss->setAttribute("a",createString("value_a"));
        sleep(100);
        String v = ss->getAttribute<String>(createString("a"));
        if(v == nullptr || !v->equals("value_a")) {
            TEST_FAIL("[testHttpSessionExpire case3]");
        }
        
        sleep(100);
        v = ss->getAttribute<String>(createString("a"));
        if(v == nullptr || !v->equals("value_a")) {
            TEST_FAIL("[testHttpSessionExpire case4]");
        }
        break;
    }
    
    TEST_OK("[testHttpSessionExpire case100]");
}
