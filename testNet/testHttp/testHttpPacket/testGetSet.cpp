#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "CRLFDetector.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

#include "HttpPacket.hpp"
#include "HttpHeader.hpp"
#include "Http.hpp"

using namespace obotcha;

void testGetSetFunction() {
  while(1) {
    //setHeader/getHeader
    HttpHeader h = HttpHeader::New();
    HttpPacket p = HttpPacket::New();
    p->setHeader(h);
     
    auto h2 = p->getHeader();
    if(h != h2) {
        TEST_FAIL("HttpPacket test set/get Header case1");
    }
    
    //getEntity/setEntity
    HttpEntity e1 = HttpEntity::New();
    p->setEntity(e1);
    
    auto e2 = p->getEntity();
    if(e2 != e1) {
        TEST_FAIL("HttpPacket test set/get Entity case2");
    }
    
    //getType/setType
    p->setType(st(Http)::PacketType::Request);
    auto t1 = p->getType();
    if(t1 != st(Http)::PacketType::Request) {
        TEST_FAIL("HttpPacket test set/get Entity case3,t1 is %d",t1);
    }
    break;
  }
  
  while(1) {
    HttpHeader h = HttpHeader::New();
    HttpPacket p = HttpPacket::New();
    p->setHeader(h);
    
    h->set(String::New("Transfer-Encoding"),
           String::New("Chunked"));
    if(!p->isChunked()) {
        TEST_FAIL("HttpPacket test set/get Entity case4");
    }
    break;
  }

  TEST_OK("[HttpPakcet test GetSet case100]");
}
