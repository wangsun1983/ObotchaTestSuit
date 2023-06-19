#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "IniReader.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"
#include "FileInputStream.hpp"

using namespace obotcha;

void testIniReaderLoadContent() {

    while(1) {
        FileInputStream stream = createFileInputStream("./testData.ini");
        stream->open();
        auto data = stream->readAll();
        IniReader reader = createIniReader(data->toString());
        
        auto maps = reader->parse()->getAll();
        if(maps->size() != 5) {
          TEST_FAIL("IniReader LoadContent test1,maps size is %d",maps->size());
          break;
        }

        //L0
        auto map1 = maps->get(createString(st(IniValue)::RootSection));
        if(map1->size() != 1) {
          TEST_FAIL("IniReader LoadContent test2");
          break;
        }

        auto str1 = map1->get(S("abc1"));
        if(str1 == nullptr || !str1->equals("1")) {
          TEST_FAIL("IniReader LoadContent test3");
          break;
        }

        //L1
        auto map2 = maps->get(createString("l1"));
        if(map2->size() != 6) {
          TEST_FAIL("IniReader LoadContent test4");
          break;
        }

        if(map2->get(S("a")) == nullptr || !map2->get(S("a"))->equals("1")) {
          TEST_FAIL("IniReader LoadContent test5");
          break;
        }

        TEST_OK("IniReader LoadContent test100");
        break;
    }
}
