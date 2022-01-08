#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int basetest() {
    ConfReader reader = createConfReader("simple.conf");

    //getConf(String);
    while(1) {
      String v1 = reader->get(createString("Desktop-Picture"));
      if(!v1->equals("/usr/images/earth.jpg")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case2] ");
        break;
      }

      String v2 = reader->get(createString("Position"));
      if(!v2->equals("Centered")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case3] ");
        break;
      }

      String v3 = reader->get(S("Background Color"));
      if(!v3->equals("Black")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case4] ");
        break;
      }

      String v4 = reader->get(S("NULL"));
      if(v4 != nullptr) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case5] ");
        break;
      }

      TEST_OK("[ConfReader Test {getConf(String)} case6]");
      break;
    }

    return 0;
}
