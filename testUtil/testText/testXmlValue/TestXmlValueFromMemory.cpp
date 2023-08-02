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
//<RegressionTests name="rootn" intv="123" boolv="false" doublev="1.1" floatv="2.2">

void testXmlValueFromMemory() {
    //XmlReader reader = createXmlReader("regressions.xml");
    //XmlDocument doc = reader->parse();
    //XmlValue root = doc->getRootNode();
    XmlDocument doc = createXmlDocument();
    XmlValue root = doc->newRootNode("RegressionTests");
    root->appendAttr("name","rootn");
    root->appendAttr("intv","123");
    root->appendAttr("boolv","false");
    root->appendAttr("doublev","1.1");
    root->appendAttr("floatv","2.2");

    XmlValue teststring = doc->newNode("teststring","test string");
    teststring->appendAttr("name","BeiJing54");
    root->appendNode(teststring);

    XmlValue testint = doc->newNode("testint","12");
    testint->appendAttr("name","BeiJing54");
    root->appendNode(testint);

    XmlValue testbool = doc->newNode("testbool","false");
    testbool->appendAttr("name","BeiJing54");
    root->appendNode(testbool);

    XmlValue testdouble = doc->newNode("testdouble","1.11");
    testdouble->appendAttr("name","BeiJing54");
    root->appendNode(testdouble);

    XmlValue testfloat = doc->newNode("testfloat","2.22");
    testfloat->appendAttr("name","BeiJing54");
    root->appendNode(testfloat);

    XmlValue testDefault = doc->newNode("defaults");
    testDefault->appendAttr("name","BeiJing54");

    //XmlValue test1 = doc->newNode("testname","noname");
    //testDefault->appendNode(test1);
    testDefault->appendNode("testname","noname");

    //XmlValue test2 = doc->newNode("execpath",".");
    //testDefault->appendNode(test2);
    testDefault->appendNode("execpath",".");

    XmlValue test3 = doc->newNode("testprog","xmllint");
    testDefault->appendNode(test3);

    XmlValue test4 = doc->newNode("srcdir","test");
    testDefault->appendNode(test4);

    XmlValue test5 = doc->newNode("resdir","result");
    testDefault->appendNode(test5);

    XmlValue test6 = doc->newNode("file","*.xml");
    testDefault->appendNode(test6);

    XmlValue test7 = doc->newNode("reserrext","err");
    testDefault->appendNode(test7);

    root->appendNode(testDefault);

    //String getName();
    while(1) {
      String name = root->getName();
      //TEST_FAIL("name is %s \n",name->toChars());
      if(name == nullptr || !name->sameAs("RegressionTests")) {
        TEST_FAIL("[XmlValue TestFromMemory {getName()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getName()} case2]");
      break;
    }

    //String getStringAttr(String attr)
    while(1) {
        String attr1 = root->getStringAttr("name");
        if(attr1 == nullptr || !attr1->sameAs("rootn")) {
          TEST_FAIL("[XmlValue TestFromMemory {getStringAttr()} case1]");
          break;
        }

        TEST_OK("[XmlValue TestFromMemory {getStringAttr()} case2]");
        break;
    }

    //Integer getIntegerAttr(String attr);
    while(1) {
        Integer attr1 = root->getIntegerAttr("intv");
        if(attr1 == nullptr || attr1->toValue() != 123) {
          TEST_FAIL("[XmlValue TestFromMemory {getIntegerAttr()} case1]");
          break;
        }

        TEST_OK("[XmlValue TestFromMemory {getIntegerAttr()} case2]");
        break;
    }

    //Boolean getBooleanAttr(String attr);
    while(1) {
        Boolean attr1 = root->getBooleanAttr("boolv");
        if(attr1 == nullptr || attr1->toValue() != false) {
          TEST_FAIL("[XmlValue TestFromMemory {getBooleanAttr()} case1]");
          break;
        }

        TEST_OK("[XmlValue TestFromMemory {getBooleanAttr()} case2]");
        break;
    }

    //Double getDoubleAttr(String attr);
    while(1) {
      Double attr1 = root->getDoubleAttr("doublev");
      if(attr1 == nullptr || st(Math)::compareDouble(attr1->toValue(),1.1)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromMemory {getDoubleAttr()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getDoubleAttr()} case2]");
      break;
    }

    //Float getFloatAttr(String attr);
    while(1) {
      Float attr1 = root->getFloatAttr("floatv");
      if(attr1 == nullptr || st(Math)::compareFloat(attr1->toValue(),2.2)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromMemory {getFloatAttr()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getFloatAttr()} case2]");
      break;
    }

    //String getStringValue(String);
    while(1) {
      String value = root->getStringValue("teststring");
      if(value == nullptr || !value->sameAs("test string")) {
        TEST_FAIL("[XmlValue TestFromMemory {getStringValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getStringValue()} case2]");
      break;
    }

    //Integer getIntegerValue(String);
    while(1) {
      Integer value = root->getIntegerValue("testint");
      if(value == nullptr || value->toValue() != 12) {
        TEST_FAIL("[XmlValue TestFromMemory {getIntegerValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getIntegerValue()} case2]");
      break;
    }

    //Boolean getBooleanValue(String);
    while(1) {
      Boolean value = root->getBooleanValue("testbool");
      if(value == nullptr || value->toValue() != false) {
        TEST_FAIL("[XmlValue TestFromMemory {getBooleanValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getBooleanValue()} case2]");
      break;
    }

    //Double getDoubleValue(String);
    while(1) {
      Double value = root->getDoubleValue("testdouble");
      if(value == nullptr || st(Math)::compareDouble(value->toValue(),1.11)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromMemory {getDoubleValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getDoubleValue()} case2]");
      break;
    }

    //Double getFloatValue(String);
    while(1) {
      Float value = root->getFloatValue("testfloat");
      if(value == nullptr || st(Math)::compareFloat(value->toValue(),2.22)!= st(Math)::AlmostEqual) {
        TEST_FAIL("[XmlValue TestFromMemory {getFloatValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getFloatValue()} case2]");
      break;
    }

    //XmlValue getNode(String);
    while(1) {
      XmlValue v = root->getNode("defaults");
      if(v == nullptr) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case1]");
        break;
      }

      String t1 = v->getStringValue("testname");
      if(t1 == nullptr || !t1->sameAs("noname")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case2]");
        break;
      }

      t1 = v->getStringValue("execpath");
      if(t1 == nullptr || !t1->sameAs(".")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case3]");
        break;
      }

      t1 = v->getStringValue("testprog");
      if(t1 == nullptr || !t1->sameAs("xmllint")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case4]");
        break;
      }

      t1 = v->getStringValue("srcdir");
      if(t1 == nullptr || !t1->sameAs("test")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case5]");
        break;
      }

      t1 = v->getStringValue("resdir");
      if(t1 == nullptr || !t1->sameAs("result")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case6]");
        break;
      }

      t1 = v->getStringValue("file");
      if(t1 == nullptr || !t1->sameAs("*.xml")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case7]");
        break;
      }

      String attr1 = v->getStringAttr("name");
      if(attr1 == nullptr || !attr1->sameAs("BeiJing54")) {
        TEST_FAIL("[XmlValue TestFromMemory {getNode()} case8]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getNode()} case8]");
      break;
    }

    //String getName();
    while(1) {
      XmlValue v = root->getNode("defaults");
      String na = v->getName();
      if(na == nullptr || !na->sameAs("defaults")) {
        TEST_FAIL("[XmlValue TestFromMemory {getName()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {getName()} case2]");
      break;
    }

    //void updateName(String name);
    while(1) {
      XmlValue v = root->getNode("defaults");
      if(v == nullptr) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case0]");
        break;
      }

      v->updateName("testupdate1");

      XmlValue v2 = root->getNode("testupdate1");
      if(v2 == nullptr) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case1]");
        break;
      }

      String t1 = v2->getStringValue("testname");
      if(t1 == nullptr || !t1->sameAs("noname")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case2]");
        break;
      }

      t1 = v2->getStringValue("execpath");
      if(t1 == nullptr || !t1->sameAs(".")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case3]");
        break;
      }

      t1 = v2->getStringValue("testprog");
      if(t1 == nullptr || !t1->sameAs("xmllint")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case4]");
        break;
      }

      t1 = v2->getStringValue("srcdir");
      if(t1 == nullptr || !t1->sameAs("test")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case5]");
        break;
      }

      t1 = v2->getStringValue("resdir");
      if(t1 == nullptr || !t1->sameAs("result")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case6]");
        break;
      }

      t1 = v2->getStringValue("file");
      if(t1 == nullptr || !t1->sameAs("*.xml")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case7]");
        break;
      }

      String attr1 = v2->getStringAttr("name");
      if(attr1 == nullptr || !attr1->sameAs("BeiJing54")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateName()} case8]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {updateName()} case9]");
      break;
    }

    //void updateValue(String value);
    while(1) {
      XmlValue v = root->getNode("teststring");
      v->updateValue("new test");

      String t1 = root->getStringValue("teststring");
      if(t1 == nullptr || !t1->sameAs("new test")) {
        TEST_FAIL("[XmlValue TestFromMemory {updateValue()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {updateValue()} case2]");
      break;
    }

    //void appendNode(XmlValue v);
    while(1) {
      XmlValue node = doc->newNode("myt1","hello world");
      root->appendNode(node);

      XmlValue node2 = root->getNode("myt1");
      if(node2 == nullptr || !node2->getStringValue()->sameAs("hello world")) {
        TEST_FAIL("[XmlValue TestFromMemory {appendNode()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {appendNode()} case2]");
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
        TEST_FAIL("[XmlValue TestFromMemory {appendAttr()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {appendAttr()} case1]");
      break;
    }

    //void removeNode(XmlValue v);
    while(1) {
      XmlValue node = root->getNode("testdouble");
      root->removeNode(node);

      XmlValue node2 = root->getNode("testdouble");
      if(node2 != nullptr) {
        TEST_FAIL("[XmlValue TestFromMemory {removeNode()} case1]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {removeNode()} case2]");
      break;
    }

    //void removeNode(String v);
    while(1) {
      XmlValue node0 = root->getNode("testfloat");
      if(node0 == nullptr) {
        TEST_FAIL("[XmlValue TestFromMemory {removeNode()} case3]");
        break;
      }

      root->removeNode(createString("testfloat"));
      XmlValue node2 = root->getNode("testfloat");
      if(node2 != nullptr) {
        TEST_FAIL("[XmlValue TestFromMemory {removeNode()} case4]");
        break;
      }

      TEST_OK("[XmlValue TestFromMemory {removeNode()} case5]");
      break;
    }
}
