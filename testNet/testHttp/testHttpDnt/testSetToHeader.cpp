#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDnt.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("dnt"),String::New("1"));
    auto dnt = header->getDnt();
    
    int val = dnt->get();
    if(val != 1) {
      TEST_FAIL("[HttpHeaderDnt test SetToHeader case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("dnt"),String::New("0"));
    auto dnt = header->getDnt();
    
    int val = dnt->get();
    if(val != 0) {
      TEST_FAIL("[HttpHeaderDnt test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderDnt test Parse case100]");

}
