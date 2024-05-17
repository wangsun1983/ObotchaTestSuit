#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServer.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Server"),
                String::New("Apache/2.4.1 (Unix)"));
                
    auto match = header->getServer();
    if(!match->get()->sameAs("Apache/2.4.1 (Unix)")) {
        TEST_FAIL("[HttpHeaderServer test SetToHeader case2]");
    }
    break;
  }

  TEST_OK("[HttpHeaderServer test SetToHeader case100]");
}
