#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVia.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
      HttpHeaderVia match = HttpHeaderVia::New();
      match->load("1.1 GWA, 1.0 fred, 1.1 p.example.net");
      if(!match->toString()->sameAs("1.1 GWA, 1.0 fred, 1.1 p.example.net")) {
        TEST_FAIL("[HttpHeaderVia test toString case1],toString is %s",match->toString()->toChars());
      }
      
      HttpHeader header = HttpHeader::New();
      header->setVia(match);
      
      auto m = header->getVia();
      if(!m->toString()->sameAs("1.1 GWA, 1.0 fred, 1.1 p.example.net")) {
        TEST_FAIL("[HttpHeaderVia test toString case2],toString is %s",m->toString()->toChars());
      }
      break;
  }
  
  while(1) {
      HttpHeaderVia via = HttpHeaderVia::New();
      via->add(nullptr,String::New("1.1"),nullptr,String::New("GWA"));
      via->add(nullptr,String::New("1.0"),nullptr,String::New("fred"));
      via->add(nullptr,String::New("1.1"),String::New("p.example.net"),nullptr);
      if(!via->toString()->sameAs("1.1 GWA, 1.0 fred, 1.1 p.example.net")) {
        TEST_FAIL("[HttpHeaderVia test toString case3],toString is %s",via->toString()->toChars());
      }
      break;
  }
  
  TEST_OK("[HttpHeaderVia test toString case100]");
}
