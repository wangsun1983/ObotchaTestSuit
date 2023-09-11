#include <stdio.h>
#include <unistd.h>

#include "IniReader.hpp"
#include "IniWriter.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "IniValue.hpp"

using namespace obotcha;

void testIniValue() {
    while(1) {
      IniValue v1 = createIniValue();
      v1->set(createString("tag1"),createString("value1"));
      v1->set(createString("tag2"),createString("value2"));
      v1->set(createString("sec1"),
             createString("sec1_tag1"),createString("sec1_value1"));
      v1->set(createString("sec1"),
             createString("sec1_tag2"),createString("sec1_value2"));
      v1->set(createString("sec1"),
             createString("sec1_tag3"),createString("sec1_value3"));
 
      IniWriter w = createIniWriter(createFile("./tmp/test1.ini"));
      w->write(v1);
      
      IniReader r = createIniReader()->loadFile(createFile("./tmp/test1.ini"));
      auto v2 = r->get();
      
      if(!v2->get("tag1")->equals(v1->get("tag1"))) {
        TEST_FAIL("IniValue test set case1");
      }
      
      if(!v2->get("tag2")->equals(v1->get("tag2"))) {
        TEST_FAIL("IniValue test set case2");
      }
      
      if(!v2->get("sec1","sec1_tag1")->equals(v1->get("sec1","sec1_tag1"))) {
        TEST_FAIL("IniValue test set case3");
      }
      
      if(!v2->get("sec1","sec1_tag2")->equals(v1->get("sec1","sec1_tag2"))) {
        TEST_FAIL("IniValue test set case4");
      }
      
      if(!v2->get("sec1","sec1_tag3")->equals(v1->get("sec1","sec1_tag3"))) {
        TEST_FAIL("IniValue test set case5");
      }
      break;
    }

    TEST_OK("IniValue test set case100");
}
