#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "ConfWriter.hpp"
#include "ConfValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testConfValueSet() {
    ConfValue value = createConfValue();
    
    value->set(createString("tag1"),createString("value1"));
    value->set(createString("tag2"),createString("value2"));
    value->set(createString("tag3"),createString("value3"));
    
    ConfWriter writer = createConfWriter(createFile("./tmp/test1.conf"));
    writer->write(value);
    
    ConfReader r = createConfReader(createFile("./tmp/test1.conf"));
    auto value2 = r->get();
    
    if(!value2->get(createString("tag1"))->equals("value1")
        ||!value2->get(createString("tag2"))->equals("value2")
        ||!value2->get(createString("tag3"))->equals("value3")) {
        TEST_FAIL("ConfValue Get/Set test1");
    }
    
    TEST_OK("ConfValue Get/Set test100");
    return 0;
}
