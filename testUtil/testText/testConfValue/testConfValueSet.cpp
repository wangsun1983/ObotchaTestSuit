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
    ConfValue value = ConfValue::New();
    
    value->set(String::New("tag1"),String::New("value1"));
    value->set(String::New("tag2"),String::New("value2"));
    value->set(String::New("tag3"),String::New("value3"));
    
    ConfWriter writer = ConfWriter::New(File::New("./tmp/test1.conf"));
    writer->write(value);
    
    ConfReader r = ConfReader::New()->loadFile(File::New("./tmp/test1.conf"));
    auto value2 = r->get();
    
    if(!value2->get(String::New("tag1"))->sameAs("value1")
        ||!value2->get(String::New("tag2"))->sameAs("value2")
        ||!value2->get(String::New("tag3"))->sameAs("value3")) {
        TEST_FAIL("ConfValue Get/Set test1");
    }
    
    TEST_OK("ConfValue Get/Set test100");
    return 0;
}
