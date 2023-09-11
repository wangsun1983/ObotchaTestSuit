#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "ConfWriter.hpp"
#include "Log.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testcreate() {

    ConfReader reader = createConfReader()->loadFile(createFile("simple.conf"));
    auto value = reader->get();
    ConfWriter writer = createConfWriter(createFile("./tmp/simple2.conf"));
    writer->write(value);
    
    ConfReader reader2 = createConfReader()->loadFile(createFile("./tmp/simple2.conf"));
    auto value2 = reader->get();
    
    auto iterator = value->getIterator();
    while(iterator->hasValue()) {
        auto tag = iterator->getTag();
        auto v = value2->get(tag);
        if(v == nullptr || !v->equals(iterator->getValue())) {
            TEST_FAIL("ConfWriter test create case1");
        }
        iterator->next();
    }
    
    iterator = value2->getIterator();
    while(iterator->hasValue()) {
        auto tag = iterator->getTag();
        auto v = value->get(tag);
        if(v == nullptr || !v->equals(iterator->getValue())) {
            TEST_FAIL("ConfWriter test create case2");
        }
        iterator->next();
    }
    
    TEST_OK("[ConfReader create test} case1]");

    return 0;
}
