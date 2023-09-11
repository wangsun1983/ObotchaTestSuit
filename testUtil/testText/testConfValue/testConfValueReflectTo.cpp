#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ConfReader.hpp"
#include "ConfWriter.hpp"
#include "ConfValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"

using namespace obotcha;

DECLARE_CLASS(ReflectData) {
public:
    int intValue;
    String stringValue;
    DECLARE_REFLECT_FIELD(ReflectData,intValue,stringValue)
};

int testReflectTo() {
    ConfReader reader = createConfReader()->loadFile(createFile("./reflectdata.conf"));
    auto value = reader->get();
    
    ReflectData data = createReflectData();
    value->reflectTo(data);
    
    if(data->intValue != 100 || !data->stringValue->sameAs("aabbcc")) {
        TEST_FAIL("ConfValue reflectTo case1");
    }
    
    TEST_OK("ConfValue reflectTo case100");
    return 0;
}
