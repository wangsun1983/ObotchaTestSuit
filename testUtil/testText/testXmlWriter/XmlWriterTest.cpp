#include <stdio.h>
#include <iostream>
#include <type_traits>

#include "String.hpp"
#include "XmlWriter.hpp"
#include "XmlDocument.hpp"
#include "XmlValue.hpp"
#include "XmlReader.hpp"
#include "File.hpp"
#include "TestLog.hpp"

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

using namespace obotcha;
using namespace rapidxml;
int main() {
    XmlDocument document = XmlDocument::New();
    XmlValue root = document->newRootNode("my root");
    String abc1 = String::New("aName");
    String abc2 = String::New("bValue");
    XmlValue node1 = document->newNode("aName","bValue");//createXmlValue(document);
    //XmlAttribute attr1 = document->newAttribute("attr1","aaa");
    //node1->appendAttr(attr1);
    node1->appendAttr("attr1","aaa");
    node1->appendAttr("attr2","bbb");
    root->appendNode(node1);

    XmlWriter xmlWriter = XmlWriter::New(document);

    //File file = File::New("my.xml");
    //file->createNewFile();
    xmlWriter->write("my.xml");

    while(1) {
      XmlReader reader = XmlReader::New()->loadFile(File::New("my.xml"));
      XmlDocument doc = reader->get();
      XmlValue myroot = doc->getRootNode();

      XmlValue abcnode1 = myroot->getNode("aName");
      if(abcnode1 == nullptr||!abcnode1->getStringValue()->sameAs("bValue")) {
        TEST_FAIL("[XmlWriter Test {write()} case1]");
        break;
      }

      String attr1 = abcnode1->getStringAttr("attr1");
      if(attr1 == nullptr || !attr1->sameAs("aaa")) {
        TEST_FAIL("[XmlWriter Test {write()} case2]");
        break;
      }

      String attr2 = abcnode1->getStringAttr("attr2");
      if(attr2 == nullptr || !attr2->sameAs("bbb")) {
        TEST_FAIL("[XmlWriter Test {write()} case3]");
        break;
      }

      TEST_OK("[XmlWriter Test {write()} case4]");
      break;
    }
/*
    String str1 = document->toString();
    TEST_FAIL("strrrrr1 is %s \n",str1->toChars());

    String str2 = document->toString();
    TEST_FAIL("strrrrr2 is %s \n",str2->toChars());

    String str3 = document->toString();
    TEST_FAIL("strrrrr3 is %s \n",str3->toChars());
*/

/*
    std::string text;
    rapidxml::print(std::back_inserter(text), document->xmlDoc, 0);
    TEST_FAIL("============================== \n");
    TEST_FAIL("toString1 is %s \n",text.data());

    std::string text2;
    rapidxml::print(std::back_inserter(text2), document->xmlDoc, 0);
    TEST_FAIL("============================== \n");
    TEST_FAIL("toString2 is %s \n",text2.data());

    std::string text3;
    rapidxml::print(std::back_inserter(text3), document->xmlDoc, 0);
    TEST_FAIL("============================== \n");
    TEST_FAIL("toString3 is %s \n",text3.data());


    //XmlWriter writer = XmlWriter::New(document);
    //writer->write("my.xml");

    //String str2 = document->toString();
    //TEST_FAIL("str2 is %s \n",str->toChars());
    while(1){}
    */


}
