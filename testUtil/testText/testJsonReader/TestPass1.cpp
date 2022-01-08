#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"
#include "File.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int testpass1() {
    JsonReader mReader = createJsonReader(createFile("pass1.json"));
    JsonValue root = mReader->get();

    //first array;
    //"JSON Test Pattern pass1",
    String v1 = root->getStringAt(0);
    if(!v1->equals("JSON Test Pattern pass1")) {
      TEST_FAIL("[JsonReader testPass case1]");
      return 0;
    }

    //{"object with 1 member":["array with 1 element"]},
    JsonValue value1 = root->getValueAt(1);
    JsonValue value1_1 = value1->getValue("object with 1 member");
    String value1_2 = value1_1->getStringAt(0);
    if(!value1_2->equals("array with 1 element")) {
      TEST_FAIL("[JsonReader testPass case2]");
      return 0;
    }

    if(value1_1->size() != 1) {
      TEST_FAIL("[JsonReader testPass case3]");
      return 0;
    }

    //{},
    JsonValue value2 = root->getValueAt(2);
    if(value2->size() != 0) {
      TEST_FAIL("[JsonReader testPass case4]");
      return 0;
    }

    //[],
    JsonValue value3 = root->getValueAt(3);
    if(value3->size() != 0) {
      TEST_FAIL("[JsonReader testPass case4]");
      return 0;
    }

    //-42,
    Integer value4 = root->getIntegerAt(4);
    if(value4->toValue() != -42) {
      TEST_FAIL("[JsonReader testPass case5]");
      return 0;
    }

    //true,
    Boolean value5 = root->getBooleanAt(5);
    if(!value5->toValue()) {
      TEST_FAIL("[JsonReader testPass case6]");
      return 0;
    }

    //false,
    Boolean value6 = root->getBooleanAt(6);
    if(value6->toValue()) {
      TEST_FAIL("[JsonReader testPass case7]");
      return 0;
    }

    //null,
    JsonValue value7 = root->getValueAt(7);
    if(value7 != nullptr) {
      TEST_FAIL("[JsonReader testPass case8]");
      return 0;
    }

    //new json value
        //"integer": 1234567890,
        JsonValue value8 = root->getValueAt(8);

        Integer value8_1 = value8->getInteger("integer");
        if(value8_1->toValue() != 1234567890) {
          TEST_FAIL("[JsonReader testPass case9]");
          return 0;
        }

        //"real": -9876.543210,
        Double value8_2 = value8->getDouble("real");
        if(value8_2->toValue() != -9876.543210) {
          TEST_FAIL("[JsonReader testPass case10]");
          return 0;
        }

        //"e": 0.123456789e-12,
        Double value8_3 = value8->getDouble("e");
        if(value8_3->toValue() != 0.123456789e-12) {
          TEST_FAIL("[JsonReader testPass case11]");
          return 0;
        }

        //"E": 1.234567890E+34,
        #if 0
        Double value8_4 = value8->getDouble("E");
        if(value8_3->toValue() != 1.234567890E+34) {
          TEST_FAIL("[JsonReader testPass case12]");
          return 0;
        }
        #endif

        //"":  23456789012E66,
        Double value8_5 = value8->getDouble("");
        if(value8_5->toValue() != 23456789012E66) {
          TEST_FAIL("[JsonReader testPass case13],value is %f",value8_5->toValue());
          return 0;
        }

        //"zero": 0,
        Double value8_6 = value8->getDouble("zero");
        if(value8_6->toValue() != 0) {
          TEST_FAIL("[JsonReader testPass case14],value is %f",value8_6->toValue());
          return 0;
        }

        //"one": 1,
        Integer value8_7 = value8->getInteger("one");
        if(value8_7->toValue() != 1) {
          TEST_FAIL("[JsonReader testPass case15],[FAILED] ");
          return 0;
        }

        //"space": " ",
        String value8_8 = value8->getString("space");
        if(!value8_8->equals(" ")) {
          TEST_FAIL("[JsonReader testPass case16],[FAILED] ");
          return 0;
        }

        //"quote": "\"",
        String value8_9 = value8->getString("quote");
        if(!value8_9->equals("\"")) {
          TEST_FAIL("[JsonReader testPass case17],[FAILED] ");
          return 0;
        }

        //"backslash": "\\",
        String value8_10 = value8->getString("backslash");
        if(!value8_10->equals("\\")) {
          TEST_FAIL("[JsonReader testPass case18],[FAILED] ");
          return 0;
        }

        //"controls": "\b\f\r\t",
        String value8_11 = value8->getString("controls");
        if(!value8_11->equals("\b\f\r\t")) {
          TEST_FAIL("[JsonReader testPass case19],[FAILED] ");
          return 0;
        }

        //"slash": "/ & \/",
        String value8_12 = value8->getString("slash");
        if(!value8_12->equals("/ & \/")) {
          TEST_FAIL("[JsonReader testPass case20],[FAILED] ");
          return 0;
        }

        //"alpha": "abcdefghijklmnopqrstuvwyz",
        String value8_13 = value8->getString("alpha");
        if(!value8_13->equals("abcdefghijklmnopqrstuvwyz")) {
          TEST_FAIL("[JsonReader testPass case21],[FAILED] ");
          return 0;
        }

        //"ALPHA": "ABCDEFGHIJKLMNOPQRSTUVWYZ",
        String value8_14 = value8->getString("ALPHA");
        if(!value8_14->equals("ABCDEFGHIJKLMNOPQRSTUVWYZ")) {
          TEST_FAIL("[JsonReader testPass case21],[FAILED] ");
          return 0;
        }

        //"digit": "0123456789",
        String value8_15 = value8->getString("digit");
        if(!value8_15->equals("0123456789")) {
          TEST_FAIL("[JsonReader testPass case21],[FAILED] ");
          return 0;
        }

        //"0123456789": "digit",
        String value8_16 = value8->getString("0123456789");
        if(!value8_16->equals("digit")) {
          TEST_FAIL("[JsonReader testPass case22],[FAILED] ");
          return 0;
        }

        //"special": "`1~!@#$%^&*()_+-={':[,]}|;.</>?",
        String value8_17 = value8->getString("special");
        if(!value8_17->equals("`1~!@#$%^&*()_+-={':[,]}|;.</>?")) {
          TEST_FAIL("[JsonReader testPass case23],[FAILED] ");
          return 0;
        }

        //"hex": "\u0123\u4567\u89AB\uCDEF\uabcd\uef4A",
        String value8_18 = value8->getString("hex");
        if(!value8_18->equals("\u0123\u4567\u89AB\uCDEF\uabcd\uef4A")) {
          TEST_FAIL("[JsonReader testPass case24],[FAILED] ");
          return 0;
        }

        //"true": true,
        Boolean value8_19 = value8->getBoolean("true");
        if(!value8_19->toValue()) {
          TEST_FAIL("[JsonReader testPass case25],[FAILED] ");
          return 0;
        }

        //"false": false,
        Boolean value8_20 = value8->getBoolean("false");
        if(value8_20->toValue()) {
          TEST_FAIL("[JsonReader testPass case26],[FAILED] ");
          return 0;
        }

        //"null": null,
        JsonValue value8_21 = value8->getValue("null");
        if(!value8_21->isNull()) {
          TEST_FAIL("[JsonReader testPass case27],[FAILED] ");
          return 0;
        }

        //"array":[  ],
        JsonValue value8_22 = value8->getValue("array");
        if(value8_22->size() != 0) {
          TEST_FAIL("[JsonReader testPass case28],[FAILED] ");
          return 0;
        }

        //"object":{  },
        JsonValue value8_23 = value8->getValue("object");
        if(!value8_23->isNull()) {
          TEST_FAIL("[JsonReader testPass case29],[FAILED] ");
          return 0;
        }

        //"address": "50 St. James Street",
        String value8_24 = value8->getString("address");
        if(!value8_24->equals("50 St. James Street")) {
          TEST_FAIL("[JsonReader testPass case30],[FAILED] ");
          return 0;
        }

        //"url": "http://www.JSON.org/",
        String value8_25 = value8->getString("url");
        if(!value8_25->equals("http://www.JSON.org/")) {
          TEST_FAIL("[JsonReader testPass case31],[FAILED] ");
          return 0;
        }

        //"comment": "// /* <!-- --",
        String value8_26 = value8->getString("comment");
        if(!value8_26->equals("// /* <!-- --")) {
          TEST_FAIL("[JsonReader testPass case32],[FAILED] ");
          return 0;
        }

        //"# -- --> */": " ",
        String value8_27 = value8->getString("# -- --> */");
        if(!value8_27->equals(" ")) {
          TEST_FAIL("[JsonReader testPass case33],[FAILED] ");
          return 0;
        }

        //" s p a c e d " :[1,2 , 3
        //
        //,
        //
        //4 , 5        ,          6           ,7        ],
        JsonValue value8_28 = value8->getValue(" s p a c e d ");
        if(value8_28->size() != 7) {
          TEST_FAIL("[JsonReader testPass case34],[FAILED] ");
          return 0;
        }

        for(int i = 0;i<7;i++) {
          if(value8_28->getIntegerAt(i)->toValue() != (i+1)) {
            //TEST_FAIL("v1 is %d,i is %d ",value8_28->getIntegerAt(i)->toValue(),i);
            TEST_FAIL("[JsonReader testPass case35],[FAILED] ");
            return 0;
          }
        }

        //"compact":[1,2,3,4,5,6,7],
        JsonValue value8_29 = value8->getValue("compact");
        if(value8_29->size() != 7) {
          TEST_FAIL("[JsonReader testPass case36],[FAILED] ");
          return 0;
        }

        for(int i = 0;i<7;i++) {
          if(value8_29->getIntegerAt(i)->toValue() != (i+1)) {
            TEST_FAIL("[JsonReader testPass case37],[FAILED] ");
            return 0;
          }
        }

        //"jsontext": "{\"object with 1 member\":[\"array with 1 element\"]}",
        String value8_30 = value8->getString("jsontext");
        if(value8_30 == nullptr) {
          TEST_FAIL("[JsonReader testPass case38],[FAILED] ");
          return 0;
        }
            //"{\"object with 1 member\":[\"array with 1 element\"]}",
            JsonReader reader = createJsonReader(value8_30);
            JsonValue value8_30_1 = reader->get();
            JsonValue value8_30_1_1 = value8_30_1->getValue("object with 1 member");
            if(!value8_30_1_1->getStringAt(0)->equals("array with 1 element")) {
              TEST_FAIL("[JsonReader testPass case39],[FAILED] ");
              return 0;
            }

        //"quotes": "&#34; \u0022 %22 0x22 034 &#x22;",
        String value8_31 = value8->getString("quotes");
        if(!value8_31->equals("&#34; \u0022 %22 0x22 034 &#x22;")) {
          TEST_FAIL("[JsonReader testPass case41],[FAILED] ");
          return 0;
        }

        //"\/\\\"\uCAFE\uBABE\uAB98\uFCDE\ubcda\uef4A\b\f\r\t`1~!@#$%^&*()_+-=[]{}|;:',./<>?"
        //: "A key can be any string"
        String value8_32 = value8->getString("\/\\\"\uCAFE\uBABE\uAB98\uFCDE\ubcda\uef4A\b\f\r\t`1~!@#$%^&*()_+-=[]{}|;:',./<>?");
        if(!value8_32->equals("A key can be any string")) {
          TEST_FAIL("[JsonReader testPass case42],[FAILED] ");
          return 0;
        }

    //0.5 ,
    Double value9 = root->getDoubleAt(9);
    if(value9->toValue() != 0.5) {
      TEST_FAIL("[JsonReader testPass case41]");
      return 0;
    }

    //98.6
    Double value10 = root->getDoubleAt(10);
    if(value10->toValue() != 98.6) {
      TEST_FAIL("[JsonReader testPass case42]");
      return 0;
    }

    //99.44
    Double value11 = root->getDoubleAt(11);
    if(value11->toValue() != 99.44) {
      TEST_FAIL("[JsonReader testPass case43]");
      return 0;
    }

    //1066,
    Integer value12 = root->getIntegerAt(12);
    if(value12->toValue() != 1066) {
      TEST_FAIL("[JsonReader testPass case44]");
      return 0;
    }

    //1e1,
    Double value13 = root->getDoubleAt(13);
    if(value13->toValue() != 1e1) {
      TEST_FAIL("[JsonReader testPass case45]");
      return 0;
    }

    //0.1e1,
    Double value14 = root->getDoubleAt(14);
    if(value14->toValue() != 0.1e1) {
      TEST_FAIL("[JsonReader testPass case46]");
      return 0;
    }

    //1e-1,
    Double value15 = root->getDoubleAt(15);
    if(value15->toValue() != 1e-1) {
      TEST_FAIL("[JsonReader testPass case47]");
      return 0;
    }

    //1e00,
    Double value16 = root->getDoubleAt(16);
    if(value16->toValue() != 1e00) {
      TEST_FAIL("[JsonReader testPass case48]");
      return 0;
    }

    //2e+00,
    Double value17 = root->getDoubleAt(17);
    if(value17->toValue() != 2e+00) {
      TEST_FAIL("[JsonReader testPass case49]");
      return 0;
    }

    //2e-00
    Double value18 = root->getDoubleAt(18);
    if(value18->toValue() != 2e-00) {
      TEST_FAIL("[JsonReader testPass case50]");
      return 0;
    }

    TEST_OK("[JsonReader testPass case]");
    return 0;
}
