#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "IniReader.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIniReader() {

    while(1) {
        IniReader reader = createIniReader()->loadFile(createFile("./testData.ini"));
        auto maps = reader->get()->getAll();
        if(maps->size() != 5) {
          TEST_FAIL("IniReader test1");
          break;
        }

        //L0
        auto map1 = maps->get(createString(st(IniValue)::RootSection));
        if(map1->size() != 1) {
          TEST_FAIL("IniReader test2");
          break;
        }

        auto str1 = map1->get(S("abc1"));
        if(str1 == nullptr || !str1->sameAs("1")) {
          TEST_FAIL("IniReader test3");
          break;
        }

        //L1
        auto map2 = maps->get(createString("l1"));
        if(map2->size() != 6) {
          TEST_FAIL("IniReader test4");
          break;
        }

        if(map2->get(S("a")) == nullptr || !map2->get(S("a"))->sameAs("1")) {
          TEST_FAIL("IniReader test5");
          break;
        }

        TEST_OK("IniReader test100");
        break;
    }
}
