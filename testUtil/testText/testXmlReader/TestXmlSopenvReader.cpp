#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "XmlReader.hpp"
#include "XmlValue.hpp"
#include "XmlDocument.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testsopenvreader() {
    XmlReader reader = createXmlReader(createFile("sopenv.xml"));
    XmlValue value = reader->get()->getRootNode();
    XmlValue value_1 = value->getNode(createString("soapenv:Body"));
    XmlValue value_1_1 = value_1->getNode(createString("ResponseMessage"));
    XmlValue value_1_1_1 = value_1_1->getNode(createString("Header"));
    XmlValue value_2 = value_1_1_1->getNode(createString("Verb"));
    if(!value_2->getStringValue()->sameAs("Show")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case1]");
    }

    XmlValue value_3 = value_1_1_1->getNode(createString("Noun"));
    if(!value_3->getStringValue()->sameAs("OMSFHYCZCJSJ")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case2]");
    }

    XmlValue value_4 = value_1_1_1->getNode(createString("User"));
    XmlValue value_4_1 = value_4->getNode(createString("UserID"));
    if(!value_4_1->getStringValue()->sameAs("DDD")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case3]");
    }
    XmlValue value_4_2 = value_4->getNode(createString("Organization"));
    if(!value_4_2->getStringValue()->sameAs("BRUCE")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case4]");
    }

    XmlValue value_5 = value_1_1_1->getNode(createString("Property"));
    XmlValue value_5_1 = value_5->getNode(createString("Name"));
    if(!value_5_1->getStringValue()->sameAs("count")) {
      TEST_FAIL("value is %s \n",value_4_1->getStringValue()->toChars());
      TEST_FAIL("[XmlReader Sopenv Test parse()} case5]");
    }
    XmlValue value_5_2 = value_5->getNode(createString("Value"));
    if(!value_5_2->getStringValue()->sameAs("50")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case6]");
    }

    XmlValue value_6 = value_1_1->getNode(createString("Reply"));
    XmlValue value_6_1 = value_6->getNode(createString("ReplyCode"));
    if(!value_6_1->getStringValue()->sameAs("OK")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case7]");
    }

    XmlValue value_7 = value_1_1->getNode(createString("Payload"));
    XmlValue value_7_1 = value_7->getNode(createString("rdf:RDF"));
    XmlValue value_7_2 = value_7_1->getNode(createString("cim:OMSFHYCZCJSJ"));
    XmlValue value_7_2_1 = value_7_2->getNode(createString("cim:aaa"));
    if(!value_7_2_1->getStringValue()->sameAs("ZHOGNG")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case8]");
    }

    XmlValue value_7_2_2 = value_7_2->getNode(createString("cim:bbb"));
    if(!value_7_2_2->getStringValue()->sameAs("广州")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case9]");
    }

    XmlValue value_7_2_2_c = value_7_2->getNode(createString("cim:bbb"));
    if(!value_7_2_2_c->getStringValue()->sameAs("广州")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case9]");
    }

    XmlValue value_7_2_3 = value_7_2->getNode(createString("cim:ccc"));
    if(!value_7_2_3->getStringValue()->sameAs("2018年第23周 (06.04~06.10)")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case10]");
    }

    XmlValue value_7_2_4 = value_7_2->getNode(createString("cim:ddd"));
    if(!value_7_2_4->getStringValue()->sameAs("16500")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case11]");
    }

    XmlValue value_7_2_5 = value_7_2->getNode(createString("cim:eee"));
    if(!value_7_2_5->getStringValue()->sameAs("8800")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case12]");
    }

    XmlValue value_7_2_6 = value_7_2->getNode(createString("cim:fff"));
    if(!value_7_2_6->getStringValue()->sameAs("2200000")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case13]");
    }

    XmlValue value_7_2_7 = value_7_2->getNode(createString("cim:ggg"));
    if(!value_7_2_7->getStringValue()->sameAs("0")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case14]");
    }

    XmlValue value_7_2_8 = value_7_2->getNode(createString("cim:hhh"));
    if(!value_7_2_8->getStringValue()->sameAs("0")) {
      TEST_FAIL("[XmlReader Sopenv Test parse()} case15]");
    }

    TEST_OK("[XmlReader Sopenv Test parse()} case100]");
}
