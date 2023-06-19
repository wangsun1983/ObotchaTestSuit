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

void testJsonValueGet() {
    JsonReader reader = createJsonReader(createFile("./abc.json"));
    JsonValue root = reader->get();
    
    auto isNonProfitValue = root->getValue("isNonProfit");
    auto boolValue = isNonProfitValue->getBoolean();
    if(boolValue == nullptr || boolValue->toValue()) {
        TEST_FAIL("JsonValue testJsonValueGet case1");
    }
    
    auto nameValue = root->getValue("name");
    auto name = nameValue->getString();
    if(name == nullptr || !name->equals("BeJson")) {
        TEST_FAIL("JsonValue testJsonValueGet case2");
    }
    
    auto urlValue = root->getValue("url");
    auto url = urlValue->getString();
    if(url == nullptr || !url->equals("http://www.bejson.com")) {
        TEST_FAIL("JsonValue testJsonValueGet case3");
    }
    
    auto pageValue = root->getValue("page");
    auto page = pageValue->getInteger();
    if(page == nullptr || page->toValue() != 88) {
        TEST_FAIL("JsonValue testJsonValueGet case4");
    }
    
    pageValue = root->getValue("page");
    auto uint64Page = pageValue->getUint64();
    if(uint64Page == nullptr || uint64Page->toValue() != 88) {
        TEST_FAIL("JsonValue testJsonValueGet case5");
    }
    
    auto addressValue = root->getValue("address");
    if(addressValue == nullptr 
        || !addressValue->getString("street")->equals("street1")
        || !addressValue->getString("city")->equals("suzhou")
        || !addressValue->getString("country")->equals("China")){
        TEST_FAIL("JsonValue testJsonValueGet case6");
    }
    
    auto linksValue = root->getValue("links");
    auto arrValue0 = linksValue->getValueAt(0);
    if(arrValue0 == nullptr 
        || !arrValue0->getString("name")->equals("Google")
        || !arrValue0->getString("url")->equals("http://www.google.com")){
        TEST_FAIL("JsonValue testJsonValueGet case7");
    }
    
    auto arrValue1 = linksValue->getValueAt(1);
    if(arrValue1 == nullptr 
        || !arrValue1->getString("name")->equals("Baidu")
        || !arrValue1->getString("url")->equals("http://www.baidu.com")){
        TEST_FAIL("JsonValue testJsonValueGet case8");
    }
    
    auto arrValue2 = linksValue->getValueAt(2);
    if(arrValue2 == nullptr 
        || !arrValue2->getString("name")->equals("SoSo")
        || !arrValue2->getString("url")->equals("http://www.SoSo.com")){
        TEST_FAIL("JsonValue testJsonValueGet case9");
    }
    
    //getlistitemat
    auto item0 = linksValue->getListItemAt(0);
    if(item0 == nullptr 
        || !item0->getString("name")->equals("Google")
        || !item0->getString("url")->equals("http://www.google.com")){
        TEST_FAIL("JsonValue testJsonValueGet case10");
    }
    
    auto item1 = linksValue->getListItemAt(1);
    if(item1 == nullptr 
        || !item1->getString("name")->equals("Baidu")
        || !item1->getString("url")->equals("http://www.baidu.com")){
        TEST_FAIL("JsonValue testJsonValueGet case11");
    }
    
    auto item2 = linksValue->getListItemAt(2);
    if(item2 == nullptr 
        || !item2->getString("name")->equals("SoSo")
        || !item2->getString("url")->equals("http://www.SoSo.com")){
        TEST_FAIL("JsonValue testJsonValueGet case12");
    }
    
    //stringLinks
    auto stringList = root->getValue("stringLinks");
    auto str0 = stringList->getStringAt(0);
    auto str1 = stringList->getStringAt(1);
    auto str2 = stringList->getStringAt(2);
    if(!str0->equals("link1") ||!str1->equals("link2") ||!str2->equals("link3")) {
        TEST_FAIL("JsonValue testJsonValueGet case13,str0 is %s,str1 is %s,str2 is %s",str0->toChars(),str1->toChars(),str2->toChars());
    }
    
    //intLinks
    auto intList = root->getValue("intLinks");
    auto int0 = intList->getIntegerAt(0);
    auto int1 = intList->getIntegerAt(1);
    auto int2 = intList->getIntegerAt(2);
    if(int0->toValue() != 22 || int1->toValue() != 33 ||int2->toValue() != 44) {
        TEST_FAIL("JsonValue testJsonValueGet case14");
    }
    
    TEST_OK("JsonValue testJsonValueGet case100");
}
