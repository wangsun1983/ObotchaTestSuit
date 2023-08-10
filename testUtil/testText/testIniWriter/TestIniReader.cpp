#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "IniReader.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"
#include "IniWriter.hpp"

using namespace obotcha;

void testIniReader() {

    while(1) {
        IniReader reader = createIniReader(createFile("testData.ini"));
        IniValue v = reader->parse();
        auto writer = createIniWriter(createFile("./tmp/testData0.ini"));
        writer->write(v);
        IniReader reader2 = createIniReader(createFile("./tmp/testData0.ini"));
      
        auto maps = reader2->parse()->getAll();
        if(maps->size() != 5) {
          TEST_FAIL("IniWriter test1");
          break;
        }

        //L0
        auto map1 = maps->get(createString(st(IniValue)::RootSection));
        if(map1->size() != 1) {
          TEST_FAIL("IniWriter test2");
          break;
        }

        auto str1 = map1->get(S("abc1"));
        if(str1 == nullptr || !str1->sameAs("1")) {
          TEST_FAIL("IniWriter test3");
          break;
        }

        //L1
        auto map2 = maps->get(createString("l1"));
        if(map2->size() != 6) {
          TEST_FAIL("IniWriter test4");
          break;
        }

        if(map2->get(S("a")) == nullptr || !map2->get(S("a"))->sameAs("1")) {
          TEST_FAIL("IniWriter test5");
          break;
        }

        TEST_OK("IniWriter test100");
        break;
    }
}
