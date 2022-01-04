#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "TransformException.hpp"
#include "IllegalArgumentException.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void StringConstructTest() {
    //String append(String s);
    while(1) {
        std::string str = "abc";
        String str1 = createString(&str);
        if(!str1->equals("abc")) {
            TEST_FAIL("String construct test1");
            break;
        }

        String str2 = createString(str);
        if(!str2->equals("abc")) {
            TEST_FAIL("String construct test2");
            break;
        }

        String str3 = createString(str2);
        if(!str3->equals("abc")) {
            TEST_FAIL("String construct test3");
            break;
        }

        String str4 = createString("abc");
        if(!str4->equals("abc")) {
            TEST_FAIL("String construct test4");
            break;
        }

        String str5 = createString("abcd",1,3);
        if(!str5->equals("bcd")) {
            TEST_FAIL("String construct test5");
            break;
        }

        bool isException = false;
        try {
            String str5 = createString("abcd",1,6);
        } catch(...) {
            isException = true;
        }

        try {
            String str5 = createString("abcd",-1,6);
        } catch(...) {
            isException = true;
        }

        try {
            String str5 = createString("abcd",-1,-1);
        } catch(...) {
            isException = true;
        }

        if(!isException) {
            TEST_FAIL("String construct test6");
            break;
        }

        //
        Integer v1 = createInteger(1200);
        String str6 = createString(v1);
        if(!str6->equals("1200")) {
            TEST_FAIL("String construct test7");
            break;
        }

        //
        Boolean v2 = createBoolean(false);
        String str7 = createString(v2);
        if(!str7->equals("false")) {
            TEST_FAIL("String construct test8");
            break;
        }

        Boolean v3 = createBoolean(true);
        String str8 = createString(v3);
        if(!str8->equals("true")) {
            TEST_FAIL("String construct test9");
            break;
        }

/*
        Float v4 = createFloat(100.0001);
        String str9 = createString(v4);
        if(!str9->equals("100.0001")) {
            TEST_FAIL("String construct test10-------[FAIL] str9 is %s\n",str9->toChars());
            break;
        }

        //
        Double v5 = createDouble(200.3322);
        String str10 = createString(v5);
        if(!str10->equals("200.0002")) {
            TEST_FAIL("String construct test11-------[FAIL],str10 is %s \n",str10->toChars());
            break;
        }
*/
        //
        Long v6 = createLong(200);
        String str11 = createString(v6);
        if(!str11->equals("200")) {
            TEST_FAIL("String construct test12");
            break;
        }

        //
        Uint8 v7 = createUint8(200);
        String str12 = createString(v7);
        if(!str12->equals("200")) {
            TEST_FAIL("String construct test13");
            break;
        }

        //
        Uint16 v8 = createUint16(12200);
        String str13 = createString(v8);
        if(!str13->equals("12200")) {
            TEST_FAIL("String construct test14");
            break;
        }

        //
        Uint32 v9 = createUint32(12200);
        String str14 = createString(v9);
        if(!str14->equals("12200")) {
            TEST_FAIL("String construct test15");
            break;
        }

        //
        Uint64 v10 = createUint64(12200);
        String str15 = createString(v10);
        if(!str15->equals("12200")) {
            TEST_FAIL("String construct test16");
            break;
        }

        //
        Byte v11 = createByte(22);
        String str16 = createString(v11);
        if(!str16->equals("22")) {
            TEST_FAIL("String construct test17");
            break;
        }

        //_String(int v);
        int v12 = 100;
        String str17 = createString(v12);
        if(!str17->equals("100")) {
            TEST_FAIL("String construct test18");
            break;
        }


        //_String(bool v);
        bool v13 = false;
        String str18 = createString(v13);
        if(!str18->equals("false")) {
            TEST_FAIL("String construct test19");
            break;
        }

        bool v14 = true;
        String str19 = createString(v14);
        if(!str19->equals("true")) {
            TEST_FAIL("String construct test20");
            break;
        }

/*
        //_String(float v);
        float v15 = 11.112;
        String str20 = createString(v15);
        if(!str20->equals("11.112")) {
            TEST_FAIL("String construct test21");
            break;
        }

        //_String(double v);
        double v16 = 11.112;
        String str21 = createString(v16);
        if(!str21->equals("11.112")) {
            TEST_FAIL("String construct test22");
            break;
        }
*/
        //_String(long v);
        long v17 = 1200;
        String str22 = createString(v17);
        if(!str22->equals("1200")) {
            TEST_FAIL("String construct test23");
            break;
        }

        //_String(char v);
        char v18 = 112;
        String str23 = createString(v18);
        if(!str23->equals("112")) {
            TEST_FAIL("String construct test24");
            break;
        }

        //_String(uint8_t);
        uint8_t v19 = 112;
        String str24 = createString(v19);
        if(!str24->equals("112")) {
            TEST_FAIL("String construct test25");
            break;
        }

        //_String(uint16_t);
        uint16_t v20 = 1112;
        String str25 = createString(v20);
        if(!str25->equals("1112")) {
            TEST_FAIL("String construct test26");
            break;
        }

        //_String(uint32_t);
        uint32_t v21 = 1113332;
        String str26 = createString(v21);
        if(!str26->equals("1113332")) {
            TEST_FAIL("String construct test27");
            break;
        }

        //_String(uint64_t);
        uint32_t v22 = 111334432;
        String str27 = createString(v22);
        if(!str27->equals("111334432")) {
            TEST_FAIL("String construct test28");
            break;
        }

        TEST_OK("String construct test100");
        break;
    }
}
