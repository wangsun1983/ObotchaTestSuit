#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "CRLFDetector.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpSessionManager.hpp"

using namespace obotcha;

void testGetSet() {
  while(1) {
    //auto session = st(HttpSessionManager)::getInstance()->createSession(2);
    auto session = createHttpSession(1);
    st(HttpSessionManager)::getInstance()->add(session);
    usleep(1000 * 200);
    auto session2 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session2 == nullptr || session2 != session) {
        TEST_FAIL("[HttpSessionManager GetSet test case1]");
    }
    
    usleep(1000*850);
    auto session3 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session3 != nullptr) {
        TEST_FAIL("[HttpSessionManager GetSet test case2]");
    }
    break;
  }
  
  while(1) {
    //auto session = st(HttpSessionManager)::getInstance()->createSession(2);
    auto session = createHttpSession(1);
    st(HttpSessionManager)::getInstance()->add(session);
    usleep(1000 * 200);
    auto session2 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session2 == nullptr || session2 != session) {
        TEST_FAIL("[HttpSessionManager GetSet test case1_1]");
    }
    
    usleep(1000*850);
    auto session3 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session3 != nullptr) {
        TEST_FAIL("[HttpSessionManager GetSet test case2_2]");
    }
    break;
  }
  
  while(1) {
    //auto session = st(HttpSessionManager)::getInstance()->createSession(2);
    auto session = createHttpSession(st(HttpSession)::InfiniteDuration);
    st(HttpSessionManager)::getInstance()->add(session);
    usleep(1000 * 200);
    auto session2 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session2 == nullptr || session2 != session) {
        TEST_FAIL("[HttpSessionManager GetSet test case3]");
    }
    
    usleep(1000*2100);
    auto session3 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session3 == nullptr || session3 != session) {
        TEST_FAIL("[HttpSessionManager GetSet test case4]");
    }
    break;
  }
  
  while(1) {
    //auto session = st(HttpSessionManager)::getInstance()->createSession(2);
    auto session = createHttpSession();
    st(HttpSessionManager)::getInstance()->add(session);
    usleep(1000*100);
    session->setMaxInactiveInterval(st(HttpSession)::InfiniteDuration);
    
    usleep(1000 * 200);
    auto session2 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session2 == nullptr || session2 != session) {
        TEST_FAIL("[HttpSessionManager GetSet test case5]");
    }
    
    usleep(1000*2100);
    auto session3 = st(HttpSessionManager)::getInstance()->get(session->getId());
    if(session3 == nullptr || session3 != session) {
        TEST_FAIL("[HttpSessionManager GetSet test case6]");
    }
    break;
  }

  TEST_OK("[HttpSessionManager GetSet test case100]");
}
