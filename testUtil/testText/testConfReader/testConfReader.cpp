#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int basetest() {
    while(1) {
      ConfReader reader = createConfReader(createFile("simple.conf"));
      auto value = reader->get();
        //getConf(String);

      String v1 = value->get(createString("Desktop-Picture"));
      if(!v1->equals("/usr/images/earth.jpg")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case2] ");
        break;
      }

      String v2 = value->get(createString("Position"));
      if(!v2->equals("Centered")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case3] ");
        break;
      }

      String v3 = value->get(S("Background Color"));
      if(!v3->equals("Black")) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case4] ");
        break;
      }

      String v4 = value->get(S("NULL"));
      if(v4->size() != 0) {
        TEST_FAIL("[ConfReader Test {getConf(String)} case5] v4 is [%s]",v4->toChars());
        break;
      }
      break;
    }
    TEST_OK("[ConfReader Test {getConf(String)} case6]");
    return 0;
}
