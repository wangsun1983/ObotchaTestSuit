#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderLink.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Link"),
                String::New("<https://example.com>; rel=\"preload\""));
                
    auto links = header->getLinks();
    auto link1 = links->get(0);
    if(link1->url == nullptr || !link1->url->sameAs("https://example.com")) {
      TEST_FAIL("[HttpHeaderLink test Parse case1] link is %s",link1->url->toChars());
    }

    if(!link1->rel->sameAs("preload")) {
      TEST_FAIL("[HttpHeaderLink test Parse case2] rel is %s",link1->rel->toChars());
    }
    break;
  }

  TEST_OK("[HttpHeaderLink test Parse case100]");

}
