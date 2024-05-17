#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "CRLFDetector.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testCRLFDetector() {
  while(1) {
   
    CRLFDetector dector = CRLFDetector::New();     
    const char *p = "abc\r\n,d";
    int i = 0;
    for(;i < strlen(p);i++) {
      uint8_t v = p[i];
      if(dector->isEnd(v)) {
        break;
      }
    }

    if(i != 4) {
      TEST_FAIL("[CRLFDetector test Parse case1,i is %d]",i)
    }

    const char *p2 = "abc\r \n,d";
    i = 0;
    for(;i < strlen(p2);i++) {
      uint8_t v = p2[i];
      if(dector->isEnd(v)) {
        break;
      }
    }

    if(i != strlen(p2)) {
      TEST_FAIL("[CRLFDetector test Parse case2,i is %d]",i)
    }

    const char *p3 = "abc\r\n,d";
    i = 0;
    for(;i < strlen(p3);i++) {
      uint8_t v = p3[i];
      if(dector->isOnlyCRLF(v)) {
        break;
      }
    }

    if(i != strlen(p3)) {
      TEST_FAIL("[CRLFDetector test Parse case3,i is %d]",i);
      break;
    }

    const char *p4 = "\r\naabb";
    i = 0;
    dector = CRLFDetector::New();
    bool isOnly = false;
    for(;i < strlen(p4);i++) {
      uint8_t v = p4[i];
      if(dector->isOnlyCRLF(v)) {
        isOnly = true;
        break;
      }
    }

    if(!isOnly) {
      TEST_FAIL("[CRLFDetector test Parse case4],i is %d",i);
      break;
    }

    const char *p5 = "abc \r\na\r\n\r\n";
    i = 0;
    for(;i < strlen(p5);i++) {
      uint8_t v = p5[i];
      if(dector->isOnlyCRLF(v)) {
        break;
      }
    }

    if(i != 10) {
      TEST_FAIL("[CRLFDetector test Parse case5],i is %d",i);
    }

    const char *p6 = "\r\nfff";
    i = 0;
    for(;i < strlen(p6);i++) {
      uint8_t v = p6[i];
      if(dector->isEnd(v)) {
        break;
      }
    }

    if(i != 1) {
      TEST_FAIL("[CRLFDetector test Parse case6],i is %d",i);
    }
    break;
  }

  TEST_OK("[CRLFDetector test Parse case100]");
}
