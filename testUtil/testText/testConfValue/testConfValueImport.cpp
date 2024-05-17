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

DECLARE_CLASS(ImportData) {
public:
    int intValue;
    String stringValue;
    DECLARE_REFLECT_FIELD(ImportData,intValue,stringValue)
};

int testImport() {
    ImportData data = ImportData::New();
    data->intValue = 100;
    data->stringValue = String::New("aabbcc");
    
    ConfValue value = ConfValue::New();
    value->importFrom(data);
    
    ConfWriter writer = ConfWriter::New(File::New("./tmp/importdata1.conf"));
    writer->write(value);
    
    ConfReader reader = ConfReader::New()->loadFile(File::New("./tmp/importdata1.conf"));
    auto __value = reader->get();
    if(!__value->get("intValue")->sameAs("100")
        ||!__value->get("stringValue")->sameAs("aabbcc")) {
        TEST_FAIL("ConfValue import test1");
    }
    
    TEST_OK("ConfValue import test100");
    return 0;
}
