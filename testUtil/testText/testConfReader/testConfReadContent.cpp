#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testReadContent() {
    ConfReader reader = createConfReader(createString("Desktop-Picture = /usr/images/earth.jpg \r\n \
                                            Position = Centered \r\n \
                                            \"Background Color\" = Black \r\n \
                                            NULL=  \r\n \
                                            "));
    auto value = reader->get();
    //getConf(String);
    while(1) {
      String v1 = value->get(createString("Desktop-Picture"));
      if(!v1->sameAs("/usr/images/earth.jpg")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case2] ");
        break;
      }

      String v2 = value->get(createString("Position"));
      if(!v2->sameAs("Centered")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case3] ");
        break;
      }

      String v3 = value->get(S("Background Color"));
      if(!v3->sameAs("Black")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case4] ");
        break;
      }

      String v4 = value->get(S("NULL"));
      if(v4->size() != 0) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case5] v4 is [%s]",v4->toChars());
        break;
      }

      TEST_OK("[ConfReader Test {getConf(String)} case6]");
      break;
    }

    return 0;
}
