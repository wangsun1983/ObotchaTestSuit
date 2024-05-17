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
    HttpHeaderUpgrade upgrade = HttpHeaderUpgrade::New();
    upgrade->load(" websocket ");
    if(!upgrade->toString()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderUpgrade upgrade = HttpHeaderUpgrade::New();
    upgrade->load(" websocket ");
    
    HttpHeader header = HttpHeader::New();
    header->setUpgrade(upgrade);
    auto upgrade2 = header->getUpgrade();
    if(!upgrade2->toString()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case2]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderUpgrade upgrade = HttpHeaderUpgrade::New();
    upgrade->set(" websocket ");
    
    HttpHeader header = HttpHeader::New();
    header->setUpgrade(upgrade);
    auto upgrade2 = header->getUpgrade();
    if(!upgrade2->toString()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderUpgrade test toString case3]");
    }
    break;
  }

  TEST_OK("[HttpHeaderUpgrade test toString case100]");
}
