#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->load(" websocket ");
    if(!upgrade->toString()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->load(" websocket ");
    
    HttpHeader header = createHttpHeader();
    header->setUpgrade(upgrade);
    auto upgrade2 = header->getUpgrade();
    if(!upgrade2->toString()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderUpgrade upgrade = createHttpHeaderUpgrade();
    upgrade->set(" websocket ");
    
    HttpHeader header = createHttpHeader();
    header->setUpgrade(upgrade);
    auto upgrade2 = header->getUpgrade();
    if(!upgrade2->toString()->equals("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case3]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUpgrade test toString case100]");
}
