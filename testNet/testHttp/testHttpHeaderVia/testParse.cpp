#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVia.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderVia match = createHttpHeaderVia();
    match->import("1.1 GWA,1.0 fred, 1.1 p.example.net");
    printf("testParse1 \n");
    ArrayList<HttpHeaderViaItem> list = match->get();
    printf("testParse2 \n");
    if(list->size() != 3) {
      printf("testParse3 \n");
      printf("---[HttpHeaderVia test Parse case1] [FAILED]--- \n");
      break;
    }
    printf("testParse4 \n");
    break;
  }

  printf("---[HttpHeaderVia test Parse case100] [OK]--- \n");
}
