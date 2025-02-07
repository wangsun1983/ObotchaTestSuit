#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServer.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderServer match = HttpHeaderServer::New();
    match->load("Apache/2.4.1 (Unix)");
    if(!match->toString()->sameAs("Apache/2.4.1 (Unix)")) {
        TEST_FAIL("[HttpHeaderServer test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderServer match = HttpHeaderServer::New();
    match->set("Apache/2.4.1 (Unix)");
    if(!match->toString()->sameAs("Apache/2.4.1 (Unix)")) {
        TEST_FAIL("[HttpHeaderServer test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderServer match = HttpHeaderServer::New();
    match->load("Apache/2.4.1 (Unix)");
    HttpHeader header = HttpHeader::New();
    header->setServer(match);
    
    auto match2 = header->getServer();
    if(!match2->toString()->sameAs("Apache/2.4.1 (Unix)")) {
        TEST_FAIL("[HttpHeaderServer test toString case3]");
    }
    break;
  }

  TEST_OK("[HttpHeaderServer test toString case100]");
}
