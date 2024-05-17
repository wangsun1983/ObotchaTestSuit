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

void testJsonValueTypeCheck() {
    JsonReader reader = JsonReader::New()->loadFile(File::New("./abc.json"));
    JsonValue root = reader->get();
    
    auto isNonProfitValue = root->getValue("isNonProfit");
    if(!isNonProfitValue->isBool()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case1");
    }
    
    if(isNonProfitValue->isInt()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case2");
    }
    
    if(isNonProfitValue->isNull()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case2_1");
    }
    
    auto nameValue = root->getValue("name");
    if(!nameValue->isString()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case3");
    }
    
    if(nameValue->isInt()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case4");
    }
    
    if(nameValue->isBool()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case5");
    }
    
    if(nameValue->isArray()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case6");
    }
    
    if(nameValue->isNull()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case7");
    }
    
    auto links = root->getValue("links");
    if(!links->isArray()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case8");
    }
    
    if(links->isString()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case9");
    }
    
    if(links->isInt()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case10");
    }
    
    if(links->isBool()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case11");
    }
    
    if(!links->isArray()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case12");
    }
    
    if(links->isNull()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case13");
    }
    
    if(links->isObject()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case14");
    }
    
    //
    auto addressValue = root->getValue("address");
    if(addressValue->isArray()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case15");
    }
    
    if(!addressValue->isObject()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case16");
    }
    
    if(addressValue->isNull()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case17");
    }
    
    auto doubleValue = root->getValue("doublevalue");
    if(!doubleValue->isDouble()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case18");
    }
    
    if(doubleValue->isArray()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case19");
    }
    
    if(doubleValue->isNull()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case20");
    }
    
    //
    auto pageValue = root->getValue("page");
    if(!pageValue->isUint64()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case21");
    }
    
    if(!pageValue->isInt()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case22");
    }
    
    if(pageValue->isBool()) {
        TEST_FAIL("JsonValue testJsonValueTypeCheck case23");
    }
    
    TEST_OK("JsonValue testJsonValueTypeCheck case100");
}
