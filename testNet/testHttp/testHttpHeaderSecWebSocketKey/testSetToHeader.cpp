#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecWebSocketKey.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    header->set(String::New("sec-websocket-key"),String::New(" abc"));
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey();
    if(!key->get()->sameAs("abc")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case1]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    header->set(String::New("sec-websocket-key1"),String::New(" abc"));
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey1();
    if(!key->get()->sameAs("abc")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case2]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    header->set(String::New("sec-websocket-key2"),String::New(" abc3"));
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey2();
    if(!key->get()->sameAs("abc3")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case3]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    header->set(String::New("sec-websocket-key3"),String::New(" abc4"));
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey3();
    if(!key->get()->sameAs("abc4")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case4]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    upgrade->load(" websocket ");
    header->setWebSocketKey(upgrade);
    
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey();
    if(!key->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case5]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    upgrade->load(" websocket ");
    header->setWebSocketKey1(upgrade);
    
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey1();
    if(!key->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case6]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    upgrade->load(" websocket ");
    header->setWebSocketKey2(upgrade);
    
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey2();
    if(!key->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case7]");
    }
    break;
  }
  
  while(1) {
    //HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    HttpHeader header = HttpHeader::New();
    HttpHeaderSecWebSocketKey upgrade = HttpHeaderSecWebSocketKey::New();
    upgrade->load(" websocket ");
    header->setWebSocketKey3(upgrade);
    
    //upgrade->load(" websocket ");
    auto key = header->getWebSocketKey3();
    if(!key->get()->sameAs("websocket")) {
      TEST_FAIL("[HttpHeaderSecWebSocketKey test setToHeader case8]");
    }
    break;
  }

  TEST_OK("[HttpHeaderSecWebSocketKey test setToHeader case100]");
}
