#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Integer.hpp"
#include "String.hpp"
#include "JsonValue.hpp"
#include "JsonReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testJsonValueSize() {
    JsonReader reader = JsonReader::New()->loadFile(File::New("./abc.json"));
    JsonValue root = reader->get();
    
    auto isNonProfitValue = root->getValue("isNonProfit");
    if(isNonProfitValue->size() != 0) {
        TEST_FAIL("JsonValue testJsonValueSize case1");
    }
    
    auto addressVaue = root->getValue("address");
    if(addressVaue->size() != 3) {
        TEST_FAIL("JsonValue testJsonValueSize case2");
    }
    
    auto linksVaue = root->getValue("links");
    if(linksVaue->size() != 3) {
        TEST_FAIL("JsonValue testJsonValueSize case3");
    }
    
    TEST_OK("JsonValue testJsonValueSize case100");
}
