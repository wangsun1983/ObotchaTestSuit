#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderConnection.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Connection"),
                String::New(" keep-alive"));
      
    auto connection = header->getConnection();
    if(!connection->get()->sameAs("keep-alive")) {
      TEST_FAIL("[HttpHeaderConnection test SetToHeader case1]");
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Connection"),
                String::New(" close"));
      
    auto connection = header->getConnection();
    if(!connection->get()->sameAs("close")) {
      TEST_FAIL("[HttpHeaderConnection test SetToHeader case2]");
    }
    break;
  }


  TEST_OK("[HttpHeaderConnection test SetToHeader case100]");

}
