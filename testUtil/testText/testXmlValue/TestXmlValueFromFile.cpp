#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "XmlReader.hpp"
#include "XmlValue.hpp"
#include "XmlDocument.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testXmlValueFromFile() {
    XmlReader reader = createXmlReader(createFile("regressions.xml"));
    XmlDocument doc = reader->get();
    XmlValue root = doc->getRootNode();

    //String getName();
    while(1) {
      String name = root->getName();
      //TEST_FAIL("name is %s \n",name->toChars());
      if(name == nullptr || !name->sameAs("RegressionTests")) {
        TEST_FAIL("[XmlValue TestFromFile {getName()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getName()} case2]");
      break;
    }

    //String getStringAttr(String attr)
    while(1) {
        String attr1 = root->getStringAttr("name");
        if(attr1 == nullptr || !attr1->sameAs("rootn")) {
          TEST_FAIL("[XmlValue TestFromFile {getStringAttr()} case1]");
          break;
        }

        TEST_OK("[XmlValue TestFromFile {getStringAttr()} case2]");
        break;
    }

    //Integer getIntegerAttr(String attr);
    while(1) {
        Integer attr1 = root->getIntegerAttr("intv");
        if(attr1 == nullptr || attr1->toValue() != 123) {
          TEST_FAIL("[XmlValue TestFromFile {getIntegerAttr()} case1]");
          break;
        }

        TEST_OK("[XmlValue TestFromFile {getIntegerAttr()} case2]");
        break;
    }

    //Boolean getBooleanAttr(String attr);
    while(1) {
        Boolean attr1 = root->getBooleanAttr("boolv");
        if(attr1 == nullptr || attr1->toValue() != false) {
          TEST_FAIL("[XmlValue TestFromFile {getBooleanAttr()} case1]");
          break;
        }

        TEST_OK("[XmlValue TestFromFile {getBooleanAttr()} case2]");
        break;
    }

    //Double getDoubleAttr(String attr);
    while(1) {
      Double attr1 = root->getDoubleAttr("doublev");
      if(attr1 == nullptr || st(Math)::compareDouble(attr1->toValue(),1.1) != st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromFile {getDoubleAttr()} case1] [FAILED],value is %lf \n",attr1->toValue());
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getDoubleAttr()} case2]");
      break;
    }

    //Float getFloatAttr(String attr);
    while(1) {
      Float attr1 = root->getFloatAttr("floatv");
      if(attr1 == nullptr || st(Math)::compareFloat(attr1->toValue(),2.2)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromFile {getFloatAttr()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getFloatAttr()} case2]");
      break;
    }

    //String getStringValue(String);
    while(1) {
      String value = root->getStringValue("teststring");
      if(value == nullptr || !value->sameAs("test string")) {
        TEST_FAIL("[XmlValue TestFromFile {getStringValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getStringValue()} case2]");
      break;
    }

    //Integer getIntegerValue(String);
    while(1) {
      Integer value = root->getIntegerValue("testint");
      if(value == nullptr || value->toValue() != 12) {
        TEST_FAIL("[XmlValue TestFromFile {getIntegerValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getIntegerValue()} case2]");
      break;
    }

    //Boolean getBooleanValue(String);
    while(1) {
      Boolean value = root->getBooleanValue("testbool");
      if(value == nullptr || value->toValue() != false) {
        TEST_FAIL("[XmlValue TestFromFile {getBooleanValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getBooleanValue()} case2]");
      break;
    }

    //Double getDoubleValue(String);
    while(1) {
      Double value = root->getDoubleValue("testdouble");
      if(value == nullptr || st(Math)::compareDouble(value->toValue(),1.11)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromFile {getDoubleValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getDoubleValue()} case2]");
      break;
    }

    //Double getFloatValue(String);
    while(1) {
      Float value = root->getFloatValue("testfloat");
      if(value == nullptr || st(Math)::compareFloat(value->toValue(),2.22)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromFile {getFloatValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getFloatValue()} case2]");
      break;
    }

    //XmlValue getNode(String);
    while(1) {
      XmlValue v = root->getNode("defaults");
      if(v == nullptr) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case1]");
        break;
      }

      String t1 = v->getStringValue("testname");
      if(t1 == nullptr || !t1->sameAs("noname")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case2]");
        break;
      }

      t1 = v->getStringValue("execpath");
      if(t1 == nullptr || !t1->sameAs(".")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case3]");
        break;
      }

      t1 = v->getStringValue("testprog");
      if(t1 == nullptr || !t1->sameAs("xmllint")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case4]");
        break;
      }

      t1 = v->getStringValue("srcdir");
      if(t1 == nullptr || !t1->sameAs("test")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case5]");
        break;
      }

      t1 = v->getStringValue("resdir");
      if(t1 == nullptr || !t1->sameAs("result")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case6]");
        break;
      }

      t1 = v->getStringValue("file");
      if(t1 == nullptr || !t1->sameAs("*.xml")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case7]");
        break;
      }

      String attr1 = v->getStringAttr("name");
      if(attr1 == nullptr || !attr1->sameAs("BeiJing54")) {
        TEST_FAIL("[XmlValue TestFromFile {getNode()} case8]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getNode()} case8]");
      break;
    }

    //String getName();
    while(1) {
      XmlValue v = root->getNode("defaults");
      String na = v->getName();
      if(na == nullptr || !na->sameAs("defaults")) {
        TEST_FAIL("[XmlValue TestFromFile {getName()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {getName()} case2]");
      break;
    }

    //void updateName(String name);
    while(1) {
      XmlValue v = root->getNode("defaults");
      if(v == nullptr) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case0]");
        break;
      }

      v->updateName("testupdate1");

      XmlValue v2 = root->getNode("testupdate1");
      if(v2 == nullptr) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case1]");
        break;
      }

      String t1 = v2->getStringValue("testname");
      if(t1 == nullptr || !t1->sameAs("noname")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case2]");
        break;
      }

      t1 = v2->getStringValue("execpath");
      if(t1 == nullptr || !t1->sameAs(".")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case3]");
        break;
      }

      t1 = v2->getStringValue("testprog");
      if(t1 == nullptr || !t1->sameAs("xmllint")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case4]");
        break;
      }

      t1 = v2->getStringValue("srcdir");
      if(t1 == nullptr || !t1->sameAs("test")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case5]");
        break;
      }

      t1 = v2->getStringValue("resdir");
      if(t1 == nullptr || !t1->sameAs("result")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case6]");
        break;
      }

      t1 = v2->getStringValue("file");
      if(t1 == nullptr || !t1->sameAs("*.xml")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case7]");
        break;
      }

      String attr1 = v2->getStringAttr("name");
      if(attr1 == nullptr || !attr1->sameAs("BeiJing54")) {
        TEST_FAIL("[XmlValue TestFromFile {updateName()} case8]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {updateName()} case9]");
      break;
    }

    //void updateValue(String value);
    while(1) {
      XmlValue v = root->getNode("teststring");
      v->updateValue("new test");

      String t1 = root->getStringValue("teststring");
      if(t1 == nullptr || !t1->sameAs("new test")) {
        TEST_FAIL("[XmlValue TestFromFile {updateValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {updateValue()} case2]");
      break;
    }

    //void appendNode(XmlValue v);
    while(1) {
      XmlValue node = doc->newNode("myt1","hello world");
      root->appendNode(node);

      XmlValue node2 = root->getNode("myt1");
      if(node2 == nullptr || !node2->getStringValue()->sameAs("hello world")) {
        TEST_FAIL("[XmlValue TestFromFile {appendNode()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {appendNode()} case2]");
      break;
    }

    //void appendAttr(String name,String value);
    while(1) {
      XmlValue v = root->getNode("testdouble");
      v->appendAttr("testAttr1","testAttr1 hello");
      //TEST_FAIL("start getAttr!!! \n");
      String attr1 = v->getStringAttr("testAttr1");
      //if(attr1 == nullptr) {
      //  TEST_FAIL("attr1 is nullptr \n");
      //} else {
      //  TEST_FAIL("attr1 is %s,haha \n",attr1->toChars());
      //}

      if(attr1 == nullptr || !attr1->sameAs("testAttr1 hello")) {
        TEST_FAIL("[XmlValue TestFromFile {appendAttr()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {appendAttr()} case1]");
      break;
    }

    //void removeNode(XmlValue v);
    while(1) {
      XmlValue node = root->getNode("testdouble");
      root->removeNode(node);

      XmlValue node2 = root->getNode("testdouble");
      if(node2 != nullptr) {
        TEST_FAIL("[XmlValue TestFromFile {removeNode()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {removeNode()} case2]");
      break;
    }

    //void removeNode(String v);
    while(1) {
      XmlValue node0 = root->getNode("testfloat");
      if(node0 == nullptr) {
        TEST_FAIL("[XmlValue TestFromFile {removeNode()} case3]");
        break;
      }

      root->removeNode(createString("testfloat"));
      XmlValue node2 = root->getNode("testfloat");
      if(node2 != nullptr) {
        TEST_FAIL("[XmlValue TestFromFile {removeNode()} case4]");
        break;
      }

      TEST_OK("[XmlValue TestFromFile {removeNode()} case5]");
      break;
    }
}
